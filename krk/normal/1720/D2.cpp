#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;
const int Maxc = 2;
const int Maxd = 4;
const int win[Maxd] = {1, 3, 0, 2};

struct trie {
    trie *ch[Maxc];
    int vals[Maxd];
    trie() {
        for (int i = 0; i < Maxc; i++)
            ch[i] = nullptr;
        fill(vals, vals + Maxd, 0);
    }
};

int T;
int n;

void Insert(trie *tr, int lvl, int a, int b, int val)
{
    if (lvl < 0) return;
    int fir = bool(a & 1 << lvl), sec = bool(b & 1 << lvl);
    int ind = 2 * fir + sec;
    tr->vals[ind] = max(tr->vals[ind], val);
    ind = (fir ^ sec);
    if (!tr->ch[ind]) tr->ch[ind] = new trie();
    Insert(tr->ch[ind], lvl - 1, a, b, val);
}

int Get(trie *tr, int lvl, int a, int b)
{
    if (lvl < 0 || !tr) return 0;
    int fir = bool(a & 1 << lvl), sec = bool(b & 1 << lvl);
    int ind = 2 * fir + sec;
    int res = tr->vals[win[ind]];
    ind = (fir ^ sec);
    res = max(res, Get(tr->ch[ind], lvl - 1, a, b));
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        trie *root = new trie();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            int cand = Get(root, Maxb - 1, a, i) + 1;
            res = max(res, cand);
            Insert(root, Maxb - 1, a, i, cand);
        }
        printf("%d\n", res);
    }
    return 0;
}