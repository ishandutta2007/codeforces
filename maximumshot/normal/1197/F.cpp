#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = 998244353;

inline int _sum(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void _inc(int &x, int y) {
    if ((x += y) >= mod) {
        x -= mod;
    }
}

const int X = 64;

struct Matrix {
    int m[X][X];

    Matrix() {
        fill((int*) m, (int*) m + X * X, 0);
    }

    Matrix operator * (const Matrix &o) const {
        Matrix res;
        for (int i = 0; i < X; i++) {
            for (int k = 0; k < X; k++) {
                for (int j = 0; j < X; j++) {
                    _inc(res.m[i][j], _mul(m[i][k], o.m[k][j]));
                }
            }
        }
        return res;
    }

    Matrix operator + (const Matrix &o) const {
        Matrix res;
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < X; j++) {
                res.m[i][j] = _sum(m[i][j], o.m[i][j]);
            }
        }
        return res;
    }

    Matrix &operator = (const Matrix &o) {
        memcpy(m, o.m, sizeof(int) * X * X);
        return *this;
    }

    vector<int> operator * (const vector<int> &o) const {
        vector<int> res(X);
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < X; j++) {
                _inc(res[i], _mul(m[i][j], o[j]));
            }
        }
        return res;
    }

    void print() const {
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < X; j++) {
                cout << m[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

inline int _bit(int mask, int i) {
    return (mask >> i) & 1;
}

int USED[4];

int mex(vector<int> ar) {
    memset(USED, 0, sizeof(int) * 4);
    for (int x : ar) USED[x] = 1;
    int res = 0;
    while (USED[res]) res++;
    return res;
}

const int LOG = 32;

Matrix mem[LOG];

void precalc(Matrix start) {
    mem[0] = start;
    for (int i = 1; i < LOG; i++) {
        mem[i] = mem[i - 1] * mem[i - 1];
    }
}

vector<int> binpow(Matrix x, int pw, vector<int> cur) {
    for (int i = 0; (1 << i) <= pw; i++) {
        if ((1 << i) & pw) {
            cur = mem[i] * cur;
        }
    }
    return cur;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    vector<vector<pii>> colored(n);

    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--, c--;
        colored[x].push_back({y, c});
    }

    vector<vector<int>> f(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> f[i][j];
        }
    }

    vector<Matrix> A(3);

    for (int t = 0; t < 3; t++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                for (int z = 0; z < 4; z++) {
                    int i = x * 4 * 4 + y * 4 + z;
                    vector<int> hlp;
                    if (f[t][0]) hlp.push_back(z);
                    if (f[t][1]) hlp.push_back(y);
                    if (f[t][2]) hlp.push_back(x);
                    int j = y * 4 * 4 + z * 4 + mex(hlp);
                    A[t].m[j][i] = 1;
                }
            }
        }
    }

    Matrix SUM_A;

    for (int i = 0; i < 3; i++) {
        SUM_A = SUM_A + A[i];
    }

    precalc(SUM_A);

//    for (int i = 0; i < 3; i++) {
//        cout << "i = " << i << "\n";
//        A[i].print();
//    }
//    cout << "SUM\n";
//    SUM_A.print();

    vector<vector<int>> dp(n, vector<int>(4));

    for (int i = 0; i < n; i++) {
        vector<int> cur(X); cur[X - 1] = 1;
        int last = -1;
        sort(colored[i].begin(), colored[i].end());
        for (int it = 0; it < (int)colored[i].size(); it++) {
            int pos = colored[i][it].first;
            int color = colored[i][it].second;
            cur = binpow(SUM_A, pos - last - 1, cur);
            cur = A[color] * cur;
            last = pos;
        }
        cur = binpow(SUM_A, a[i] - 1 - last, cur);
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                for (int z = 0; z < 4; z++) {
                    int j = x * 4 * 4 + y * 4 + z;
                    _inc(dp[i][z], cur[j]);
                }
            }
        }
    }

    vector<vector<int>> DP(n + 1, vector<int>(4));

    DP[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                _inc(DP[i + 1][x ^ y], _mul(DP[i][x], dp[i][y]));
            }
        }
    }

    cout << DP[n][0] << "\n";

    return 0;
}