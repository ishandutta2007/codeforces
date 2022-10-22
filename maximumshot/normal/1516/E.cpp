#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int mod = inf + 7;

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

vector<int> slow(int N, int K) {
    vector<int> res(K + 1);
    set<vector<int>> Q;
    {
        vector<int> id(N + 1);
        for (int i = 1; i <= N; i++)
            id[i] = i;
        Q.insert(id);
    }
    for (int k = 1; k <= K; k++) {
        set<vector<int>> NQ;
        for (auto p : Q) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j < i; j++) {
                    auto q = p;
                    swap(q[i], q[j]);
                    NQ.insert(q);
                }
            }
        }
        Q = NQ;
        res[k] = (int) Q.size();
        if (0 && k == K) {
            map<pii, int> CNT;
            for (auto p : Q) {
                int comp = 0;
                int loop = 0;
                vector<int> used(N + 1);
                for (int i = 1; i <= N; i++) {
                    if (p[i] == i)
                        loop++;
                    if (used[i])
                        continue;
                    comp++;
                    for (int x = i; !used[x]; x = p[x])
                        used[x] = 1;
                }
                CNT[{comp, loop}]++;
                for (int i = 1; i <= N; i++)
                    cout << p[i] << " ";
                cout << "\n";
            }
            for (auto item : CNT) {
                cout << item.first.first << " " << item.first.second << " : " << item.second << "\n";
            }
            cout << "total = " << (int) Q.size() << "\n";
        }
    }
    return res;
}

vector<int> fast(int N, int K) {
    int maxn = 2 * K;
    int maxc = 2 * K;
    vector<int> A(maxn + 1);
    A[0] = 1;
    for (int n = 1; n <= maxn; n++) {
        A[n] = _mul(A[n - 1], N - n + 1);
    }
    vector<vector<int>> C(maxn + 1, vector<int>(maxn + 1));
    for (int i = 0; i <= maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = _sum(C[i - 1][j - 1], C[i - 1][j]);
    }
    vector<int> fact(maxn + 1), rfact(maxn + 1);
    fact[0] = 1;
    for (int i = 1; i <= maxn; i++)
        fact[i] = _mul(fact[i - 1], i);
    for (int i = 0; i <= maxn; i++)
        rfact[i] = _binpow(fact[i], mod - 2);
    vector<vector<int>> f(maxn + 1, vector<int>(maxc + 1));
    f[0][0] = 1;
    for (int n = 1; n <= maxn; n++) {
        for (int c = 1; c <= maxc; c++) {
            for (int l = 2; l <= n; l++) {
                int cf = _mul(C[n][l], fact[l - 1]);
                cf = _mul(cf, f[n - l][c - 1]);
                _inc(f[n][c], cf);
            }
        }
    }
    for (int n = 1; n <= maxn; n++) {
        for (int c = 1; c <= maxc; c++) {
            f[n][c] = _mul(f[n][c], rfact[c]);
        }
    }
    vector<int> res(K + 1);
    for (int j = 1; j <= K; j++) {
        auto& cnt = res[j];
        if (j % 2 == 0)
            _inc(cnt, 1);
        for (int n = 1; n <= N && n <= maxn; n++) {
            for (int c = 1; c <= maxc; c++) {
                if (n - c <= j && (n - c) % 2 == j % 2) {
                    int cf = _mul(f[n][c], _mul(A[n], rfact[n]));
//                    if (j == K) {
//                        cout << (N - n + c) << " " << N - n << " : " << cf << " : " << f[n][c] << "\n";
//                    }
                    _inc(cnt, cf);
                }
            }
        }
    }
    return res;
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 6;
    const int MAXK = 8;
    while (1) {
        int n = rnd() % MAXN + 2;
        int k = rnd() % MAXK + 1;
        auto fs = fast(n, k);
        auto sl = slow(n, k);
        if (fs == sl) {
            cout << "OK( "; for (int i = 1; i <= k; i++) cout << fs[i] << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (int i = 1; i <= k; i++) cout << sl[i] << " "; cout << "\n";
            cout << "fnd = "; for (int i = 1; i <= k; i++) cout << fs[i] << " "; cout << "\n";
            cout << n << " " << k << "\n";
            break;
        }
    }
}

void work() {
    int n, k;
    cin >> n >> k;
    //slow(n, k);
    auto fs = fast(n, k);
    for (int j = 1; j <= k; j++)
        cout << fs[j] << " ";
    cout << "\n";
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