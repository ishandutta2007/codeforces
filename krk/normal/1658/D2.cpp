#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1 << 17;
const int Maxb = 17;

struct node {
    int ch[2];
    node() { ch[0] = ch[1] = 0; }
};

vector <node> V;
int T;
int l, r;
int a[Maxn];

void addNode() { V.push_back(node()); }

int getLst() { return int(V.size()) - 1; }

void Add(int tr, int b, int mask)
{
    if (b < 0) return;
    int ind = bool(mask & 1 << b);
    if (!V[tr].ch[ind]) {
        addNode();
        V[tr].ch[ind] = getLst();
    }
    Add(V[tr].ch[ind], b - 1, mask);
}

int Get(int tr, int b, int mask, bool getmax)
{
    if (b < 0) return 0;
    int ind1 = bool(mask & 1 << b);
    int ind2 = !ind1;
    if (getmax) swap(ind1, ind2);
    if (V[tr].ch[ind1]) return Get(V[tr].ch[ind1], b - 1, mask, getmax) | (int(getmax) << b);
    return Get(V[tr].ch[ind2], b - 1, mask, getmax) | (int(!getmax) << b);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        int sz = r - l + 1;
        V.clear(); addNode();
        addNode();
        int root = getLst();
        for (int i = 0; i < sz; i++) {
            scanf("%d", &a[i]);
            Add(root, Maxb - 1, a[i]);
        }
        int res = -1;
        for (int i = 0; i < sz && res == -1; i++) {
            int cand = (a[i] ^ l);
            if (Get(root, Maxb - 1, cand, false) == l && Get(root, Maxb - 1, cand, true) == r)
                res = cand;
        }
        printf("%d\n", res);
    }
    return 0;
}