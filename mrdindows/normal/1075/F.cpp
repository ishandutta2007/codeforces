#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5+5;
map<int,int> parent;
map<int,vector<int>> childs;
map<int,int> xorP; //xor sum to parent
int Find(int x) {
    if (!parent.count(x)) {
        parent[x] = -1;
        childs[x] = {};
        xorP[x] = 0;
    }
    return parent[x] < 0 ? x : Find(parent[x]);
}

void recompute(int i, int x) {
    xorP[i] ^= x;
    for (int j: childs[i]) {
        recompute(j,x);
    }
}

void Union(int x, int y, int z) {
    int px = Find(x);
    int py = Find(y);
    assert(px != py);
    if (parent[px] > parent[py]) swap(px,py);
    parent[px] += parent[py];
    parent[py] = px;
    childs[px].push_back(py);
    //recalculate xor paths
    int a = xorP[x];
    int b = xorP[y];
    recompute(py, a ^ b ^ z);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int q; cin >> q;
    int last = 0;
    while (q--) {
        if (last == -1) last = 1;
        int t; cin >> t;
        if (t == 1) {
            int l, r, x; cin >> l >> r >> x;
            l ^= last, r ^= last, x ^= last;
            if (l > r) swap(l,r);
            //cout << t << ' ' << l << ' ' << r << ' ' << x << '\n';
            r++;
            //add edge from par[l] to par[r], total weight is x
            if (Find(l) != Find(r)) {
                Union(l,r,x);
            }
            /*
            for (int i = 1; i <= 4; i++) {
                cout << i << ": " << (parent.count(i) ? parent[i] : i) << ' ' << (xorP.count(i) ? xorP[i] : 0) << '\n';
            }
            */
        }
        else {
            int l, r; cin >> l >> r;
            l ^= last, r ^= last;
            if (l > r) swap(l,r);
            //cout << t << ' ' << l << ' ' << r << '\n';
            r++;
            if (Find(l) != Find(r)) {
                last = -1;
            }
            else {
                last = xorP[l] ^ xorP[r];
            }
            cout << last << '\n';
        }
    }

    return 0;
}