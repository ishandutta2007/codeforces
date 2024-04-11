#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef unsigned long long ULL;
typedef pair<unsigned, int> pui;
const int MAXN = 200003;
/* PUSH DOWN !! */
struct Node {
    Node *left, *right;
    int bt, hv; // 1: black   2 : white
    unsigned mn;
    int len;
    Node(int _bt, unsigned _mn, int _len): bt(_bt), mn(_mn), len(_len)
    {
        left = right = NULL;
    }
};
void insert(Node *h, int bt, unsigned mn, int len)
{
    if (h->len == len) {
        h->bt |= bt;
        return;
    }
    unsigned mid = h->mn + (1ull << (h->len - 1));
    if (h->left == NULL) {
        h->left = new Node(0, h->mn, h->len - 1);
        h->right = new Node(0, mid, h->len - 1);
    }
    if (mn < mid)
        insert(h->left, bt, mn, len);
    else
        insert(h->right, bt, mn, len);
}
void pushdown(Node *h)
{
    if (h->bt == 3) {
        puts("-1");
        exit(0);
    }
    if (h->left) {
        h->left->bt |= h->bt;
        h->right->bt |= h->bt;
        pushdown(h->left);
        pushdown(h->right);
    }
}
void pullup(Node *h)
{
    h->hv = h->bt;
    if (h->left) {
        pullup(h->left);
        pullup(h->right);
        h->hv |= h->left->hv;
        h->hv |= h->right->hv;
    }
}
Node *root;
int n;
struct Atype {
    int bt;
    unsigned mn;
    int len;
    bool operator< (const Atype &x)const
    {
        return len < x.len;
    }
} e[MAXN];
vector<pui> ans;
void getAns(Node *h)
{
    if (h->hv == 1) {
        ans.emplace_back(h->mn, h->len);
        return;
    }
    else if (h->hv == 2) {
        return;
    }
    else {
        if (h->left) {
            getAns(h->left);
            getAns(h->right);
        }
    }
}
int main()
{
    root = new Node(0, 0, 32);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        char s0[100];
        scanf("%s", s0);
        string s(s0 + 1);
        int p = s.find('/');
        if (p == -1) {
            s += "/32";
            p = s.find('/');
        }
        unsigned x = 0;
        unsigned a, b, c, d;
        int l;
        sscanf(s.c_str(), "%u.%u.%u.%u/%d", &a, &b, &c, &d, &l);
        l = 32 - l;
        x += a << 24;
        x += b << 16;
        x += c << 8;
        x += d;
        x &= ((ULL) - 1) ^ ((1ull << l) - 1);
        e[i].bt = (s0[0] == '-' ? 1 : 2);
        e[i].mn = x;
        e[i].len = l;
    }
    sort(e, e + n);
    for (int i = 0; i < n; ++i)
        insert(root, e[i].bt, e[i].mn, e[i].len);
    pushdown(root);
    pullup(root);
    getAns(root);
    printf("%d\n", (int)ans.size());
    for (pui pp : ans) {
        unsigned x = pp.first;
        int a, b, c, d;
        a = x >> 24;
        b = (x >> 16) & 0xff;
        c = (x >> 8) & 0xff;
        d = x & 0xff;
        printf("%d.%d.%d.%d/%d\n", a, b, c, d, 32 - pp.second);
    }
    return 0;
}