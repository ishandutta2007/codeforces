#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const int Maxd = 3;

struct pos {
    int d[Maxd];
    pos() { fill(d, d + Maxd, 0); }
    bool operator==(const pos &b) const {
        return d[0] == b.d[0] && d[1] == b.d[1] && d[2] == b.d[2];
    }
    bool operator<(const pos &b) const {
        for (int i = 0; i < Maxd; i++)
            if (d[i] != b.d[i]) return d[i] < b.d[i];
        return false;
    }
};

int T;
int n, x, y, z;
vector <pos> V;
map <vector <pos>, int> M;
int st, len;
ll a[Maxn];

bool Same()
{
    if (V.size() >= 5) {
        vector <pos> seq;
        for (int j = int(V.size()) - 5; j < V.size(); j++)
            seq.push_back(V[j]);
        auto it = M.find(seq);
        if (it != M.end()) {
            st = it->second;
            len = int(V.size()) - 5 - st;
            return true;
        } else M.insert(make_pair(seq, int(V.size()) - 5));
    }
    return false;
}

int getVal(ll my, int d)
{
    if (my < V.size()) return V[my].d[d];
    my -= st;
    return V[my % len + st].d[d];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &x, &y, &z);
        V.clear(); M.clear();
        V.push_back(pos());
        int cnt = 0;
        while (!Same()) {
            pos p;
            for (int j = 0; j < Maxd; j++) {
                int mask = 0;
                mask |= 1 << getVal(max(0, int(V.size()) - x), 0);
                if (j != 1)
                    mask |= 1 << getVal(max(0, int(V.size()) - y), 1);
                if (j != 2)
                    mask |= 1 << getVal(max(0, int(V.size()) - z), 2);
                while (mask & 1 << p.d[j]) p.d[j]++;
            }
            V.push_back(p);
        }
        int res = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%I64d", &a[i]);
            res ^= getVal(a[i], 0);
        }
        for (int i = 0; i < n; i++) {
            int cand = (res ^ getVal(a[i], 0));
            ll my = max(0ll, a[i] - x);
            cand ^= getVal(my, 0);
            if (cand == 0) ans++;
            cand ^= getVal(my, 0);
            my = max(0ll, a[i] - y);
            cand ^= getVal(my, 1);
            if (cand == 0) ans++;
            cand ^= getVal(my, 1);
            my = max(0ll, a[i] - z);
            cand ^= getVal(my, 2);
            if (cand == 0) ans++;
            cand ^= getVal(my, 2);
        }
        printf("%d\n", ans);
    }
    return 0;
}