/*input
8 5
1 2 2 3 3 2 3 3
1 2
1 5
2 3
2 4
5 6
5 7
5 8
1 2
1 3
1 4
2 3
5 3

*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 1e5 + 5;

struct Query {
    int l, r, lim, id;
};

int n, q, S;
int color[N], sta[N], en[N];
int cntC[N], cntA[N], ansToQuery[N];
vector<vector<int> > a(N);
int Time = -1;
vector<int> seq;

vector<vector<Query> > query;
void dfs(int u, int p) {
    sta[u] = ++Time;
    seq.push_back(u);
    for (auto v : a[u]) {
        if (v != p) dfs(v, u);
    }
    en[u] = Time;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    S = sqrt(n);
    query.assign(n / S + 1, vector<Query>());
    loop(i, 1, n) cin >> color[i];
    loop(i, 1, n - 1) {
        int u, v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 1);
    loop(i, 0, q - 1) {
        int u, lim;
        cin >> u >> lim;
        query[en[u] / S].push_back({sta[u], en[u], lim, i});
    }
    for (auto &vec : query) {
        sort(vec.begin(), vec.end(), [&](Query & x, Query & y) {
            return x.l > y.l;
        });
    }
    vector<pair<int*, int> > data;
    auto modify = [&](int u, bool saved) {
        u = color[u];
        if (saved) data.push_back({&cntC[u], cntC[u]});
        cntC[u]++;
        if (saved) data.push_back({&cntA[cntC[u]], cntA[cntC[u]]});
        cntA[cntC[u]]++;
    };

    auto rollback = [&]() {
        rloop(i, data.size() - 1, 0) {
            *data[i].fi = data[i].se;
        }
        data.clear();
    };

    loop(p, 0, query.size() - 1) {
        auto &vec = query[p];
        memset(cntC, 0, sizeof(cntC)); memset(cntA, 0, sizeof(cntA));
        int L = p * S;
        for (auto &cur : vec) {
            while (L > cur.l) {
                L--; modify(seq[L], 0);
            }
            if (L == p * S) {
                loop(i, cur.l, cur.r) {
                    modify(seq[i], 1);
                }
            }
            else {
                loop(i, p * S, cur.r) {
                    modify(seq[i], 1);
                }
            }
            ansToQuery[cur.id] = cntA[cur.lim];
            rollback();
        }
    }
    loop(i, 0, q - 1) cout << ansToQuery[i] << endl;
}