/*input
4
2 3 5 7
*/
#ifdef UncleGrandpa
#include <prettyprint.hpp>
#define LOCAL 1
#else
#define LOCAL 0
#endif
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define all(x) (x).begin(), (x).end()
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
#define debug(x...) {if (!LOCAL) return; cout << "[" << #x << "] ="; print(x);}
void print() {cout << endl;}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {if (!LOCAL) return; cout << value << ' '; print(values...);}
// const int N =;

const int INF = 1e9;
const int M = 1000005;
int primes[M]; // bitset for faster speed
void eratosthene() {
    for (int i = 2, lim = sqrt(M - 5); i <= lim; i++) if (primes[i] == 0) for (int j = i * i; j <= M - 5; j += i) primes[j] = i;
    loop(i, 2, M - 5) if (primes[i] == 0) primes[i] = i;
}

int n, ans = INF;
vector<int> a, vis;
vector<vector<int> > g(M);
map<pair<int, int>, int> mark;
bool spec[M];
int dis[M], par[M];

vector<pair<int, int> > fact(int X) {
    vector<pair<int, int> > ret;
    while (X > 1) {
        int div = primes[X]; int cnt = 0;
        while (X % div == 0) {
            X /= div; cnt++;
        }
        ret.push_back({div, cnt});
    }
    return ret;
}

pair<int, int> norm(vector<pair<int, int> > X) {
    sort(X.begin(), X.end());
    vector<pair<int, int> > Y; for (auto it : X) if (it.se % 2 != 0) Y.push_back(it);
    if (Y.size() == 0) return { -1, -1};
    else if (Y.size() == 1) return {Y[0].fi, -1};
    else return {Y[0].fi, Y[1].fi};
}

// usage: just call cycle()
struct ShortestCycle {
    int n, ans;
    vector<int> aff, dis, par;
    void init(int _n) {
        n = _n; ans = INF; aff.clear(); dis.assign(n + 5, INF);  par.assign(n + 5, 0);
    }
    int bfsCycle(int root) {
        queue<int> q; q.push(root);  dis[root] = 1;
        aff.push_back(root);
        int pre = -1; if (spec[root]) pre = 1;

        auto ret = [&] {
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                if (dis[u] + dis[u] - 2 >= ans) return INF;
                if (u != root && spec[u]) {
                    if (pre == -1) pre = dis[u];
                    else return pre + dis[u];
                }
                for (auto v : g[u]) {
                    if (dis[v] > dis[u] + 1) {
                        dis[v] = dis[u] + 1; par[v] = u;
                        q.push(v); aff.push_back(v);
                    }
                    else if (par[u] != v and par[v] != u)
                        return dis[u] + dis[v] - 1;
                }
            }
            return INF;
        }();
        for (auto it : aff) dis[it] = INF, par[it] = 0;
        aff.clear();
        return ret;
    }
    int operator()() {
        loop(i, 1, n) {
            if (i > 1000) break;
            ans = min(ans, bfsCycle(i));
        }
        return ans;
    }
} cycle;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    eratosthene();
    cin >> n;
    loop(i, 1, n) {
        int t; cin >> t;
        a.push_back(t);
    }
    for (auto it : a) {
        auto rec = norm(fact(it));
        if (rec == make_pair(-1LL, -1LL)) {
            cout << 1 << endl;
            return 0;
        }
        else mark[rec]++;
    }
    for (auto it : mark) if (it.se >= 2) {
            cout << 2 << endl;
            return 0;
        }
    vector<int> ava;
    for (auto it : mark) {
        if (it.fi.se != -1) {
            ava.push_back(it.fi.fi); ava.push_back(it.fi.se);
            g[it.fi.fi].push_back(it.fi.se);
            g[it.fi.se].push_back(it.fi.fi);
        }
        else spec[it.fi.fi] = true;
    }
    if (!ava.empty()) {
        sort(ava.begin(), ava.end()); ava.resize(distance(ava.begin(), unique(ava.begin(), ava.end())));
        cycle.init(ava.back());
        ans = cycle();
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}