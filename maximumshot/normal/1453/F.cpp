#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct Dinic {

    struct Edge {
        int fr, to, cp, id, fl;
    };

    int n, S, T;
    vector< Edge > es;
    vector< vector< int > > g;
    vector< int > dist, res, ptr;

    Dinic(int n_, int S_, int T_):
            n(n_), S(S_), T(T_)
    {
        g.resize(n);
    }

    void add_edge(int fr, int to, int cp, int id) {
        g[fr].push_back((int)es.size());
        es.push_back({fr, to, cp, id, 0});
        g[to].push_back((int)es.size());
        es.push_back({to, fr, 0, -1, 0});
    }

    bool bfs(int K) {
        dist.assign(n, inf);
        dist[S] = 0;
        queue< int > q;
        q.push(S);
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int ps : g[v]) {
                Edge &e = es[ps];
                if(e.fl + K > e.cp) continue;
                if(dist[e.to] > dist[e.fr] + 1) {
                    dist[e.to] = dist[e.fr] + 1;
                    q.push(e.to);
                }
            }
        }
        return dist[T] < inf;
    }

    int dfs(int v, int _push = INT_MAX) {
        if(v == T || !_push) return _push;
        for(int &iter = ptr[v];iter < (int)g[v].size();iter++) {
            int ps = g[v][ ptr[v] ];
            Edge &e = es[ps];
            if(dist[e.to] != dist[e.fr] + 1) continue;
            int tmp = dfs(e.to, min(_push, e.cp - e.fl));
            if(tmp) {
                e.fl += tmp;
                es[ps ^ 1].fl -= tmp;
                return tmp;
            }
        }
        return 0;
    }

    ll find_max_flow() {
        ptr.resize(n);
        ll max_flow = 0, add_flow;
        for(int K = 1 << 30;K > 0;K >>= 1) {
            while(bfs(K)) {
                ptr.assign(n, 0);
                while((add_flow = dfs(S))) {
                    max_flow += add_flow;
                }
            }
        }
        return max_flow;
    }

    void assign_result() {
        res.resize(es.size());
        for(Edge e : es) if(e.id != -1) res[e.id] = e.fl;
    }

    int get_flow(int id) {
        return res[id];
    }

    bool go(int v, vector< int > &F, vector< int > &path) {
        if(v == T) return 1;
        for(int ps : g[v]) {
            if(F[ps] <= 0) continue;
            if(go(es[ps].to, F, path)) {
                path.push_back(ps);
                return 1;
            }
        }
        return 0;
    }

    vector< pair< int, vector< int > > > decomposition() {
        find_max_flow();
        vector< int > F((int)es.size()), path, add;
        vector< pair< int, vector< int > > > dcmp;
        for(int i = 0;i < (int)es.size();i++) F[i] = es[i].fl;
        while(go(S, F, path)) {
            int mn = INT_MAX;
            for(int ps : path) mn = min(mn, F[ps]);
            for(int ps : path) F[ps] -= mn;
            for(int ps : path) add.push_back(es[ps].id);
            reverse(add.begin(), add.end());
            dcmp.push_back({mn, add});
            add.clear();
            path.clear();
        }
        return dcmp;
    }
};

void gen(int& n, vector<int>& a, mt19937& rnd) {
    const int MAXN = 10;
    while (1) {
        n = rnd() % (MAXN - 1) + 2;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % (n - i + 1);

        vector<int> f(n + 1);
        f[n] = 1;
        for (int i = n - 1; i >= 1; i--)
            for (int j = i + 1; j <= i + a[i]; j++)
                f[i] |= f[j];

        if (f[1])
            break;
    }
}

void read(int& n, vector<int>& a) {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int fast(int n, vector<int> a) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, inf)), pr = dp;
    dp[1][0] = 0;
    pr[1][0] = 0;
    for (int x = 1; x <= n; x++)
        pr[1][x] = min(pr[1][x], pr[1][x - 1]);
    for (int k = 2; k <= n; k++) {
        int cnt = 0;
        for (int j = k - 1; j >= 1; j--) {
            if (j + a[j] >= k) {
//                for (int x = 0; x < k; x++) {
//                    dp[k][j + a[j]] = min(dp[k][j + a[j]], dp[j][x] + cnt);
//                }
                dp[k][j + a[j]] = min(dp[k][j + a[j]], pr[j][k - 1] + cnt);
                cnt++;
            }
        }
        pr[k] = dp[k];
        for (int x = 1; x <= n; x++)
            pr[k][x] = min(pr[k][x], pr[k][x - 1]);
    }
    return dp[n][n];
}

int slow(int n, vector<int> a) {
    int res = n - 2;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (((1 << 0) & mask) || ((1 << (n - 1)) & mask))
            continue;
        vector<int> f(n + 1);
        f[n] = 1;
        for (int i = n - 1; i >= 1; i--) {
            if ((1 << (i - 1)) & mask)
                continue;
            for (int j = i + 1; j <= i + a[i]; j++)
                f[i] = min(2, f[i] + f[j]);
        }
        if (f[1] == 1)
            res = min(res, __builtin_popcount(mask));
    }
    return res;
}

void work() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> a;
        read(n, a);
        int fs = fast(n, a);
        cout << fs << "\n";
    }
}

void test() {
    mt19937 rnd(42);
    while (1) {
        int n;
        vector<int> a;
        gen(n, a, rnd);
        int fs = fast(n, a);
        int sl = slow(n, a);
        cout << n << endl;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
        if (fs == sl) {
            cout << "OK(" << fs << ")" << endl;
        } else {
            cout << "exp = " << sl << endl;
            cout << "fnd = " << fs << endl;
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}