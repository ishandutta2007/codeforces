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

const int mod = 998244353;
const int X = 512;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline int _sub(int a, int b) {
    return a >= b ? a - b : a - b + mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

inline void _dec(int &x, int y) {
    if ((x -= y) < 0) {
        x += mod;
    }
}

inline int _binpow(int x, int pw) {
    int res = 1;
    int tmp = x;
    while (pw > 0) {
        if (pw & 1) {
            res = _mul(res, tmp);
        }
        tmp = _mul(tmp, tmp);
        pw >>= 1;
    }
    return res;
}

inline int _div(int a, int b) {
    return _mul(a, _binpow(b, mod - 2));
}

void read(int& n, int& m, vector<vector<int>>& g) {
    cin >> n >> m;
    g.resize(n + 1);
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
    }
}

int fast(int n, int m, vector<vector<int>> g) {
    vector<int> tops, used(n + 1);
    function<void(int)> dfs = [&](int v) {
        if (used[v])
            return;
        used[v] = 1;
        for (int to : g[v])
            dfs(to);
        tops.push_back(v);
    };
    for (int v = 1; v <= n; v++)
        dfs(v);
    vector<int> t(n + 1, 0);
    for (int v : tops) {
        unordered_set<int> q;
        for (int to : g[v])
            q.insert(t[to]);
        while (q.count(t[v]))
            t[v]++;
//        cout << v << " : " << t[v] << "\n";
    }
    vector<int> cnt(X);
    for (int v = 1; v <= n; v++)
        cnt[t[v]]++;
    vector<vector<int>> A(X, vector<int>(X + 1));
    for (int v = 0; v < X; v++) {
        _inc(A[v][v], 1);
        for (int k = 0; k < X; k++) {
            int coef = _div(cnt[k], n + 1);
            _dec(A[v][v ^ k], coef);
        }
        if (v == 0)
            _inc(A[v][X], _div(1, n + 1));
    }
    for (int i = 0, j = 0; j < X; j++) {
        int q = i;
        while (q < X && !A[q][j])
            q++;
        if (q == X)
            continue;
        swap(A[i], A[q]);
        int coef = _div(1, A[i][j]);
        for (int p = 0; p <= X; p++)
            A[i][p] = _mul(A[i][p], coef);
        for (q = i + 1; q < X; q++) {
            if (!A[q][j])
                continue;
            coef = _sub(0, A[q][j]);
            for (int p = 0; p <= X; p++)
                _inc(A[q][p], _mul(coef, A[i][p]));
        }
        i++;
    }
//    for (auto row : A) {
//        for (auto x : row)
//            cout << !!x << " ";
//        cout << "\n";
//    }
    vector<int> P(X);
    for (int i = X - 1; i >= 0; i--) {
        if (!A[i][i])
            continue;
        P[i] = A[i][X];
        for (int j = i + 1; j < X; j++)
            _dec(P[i], _mul(P[j], A[i][j]));
        P[i] = _div(P[i], A[i][i]);
    }
    return _sub(1, P[0]);
//    return P[0];
}

void work() {
    int n, m;
    vector<vector<int>> g;
    read(n, m, g);
    int fs = fast(n, m, g);
    cout << fs << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}