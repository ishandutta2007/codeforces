#include <bits/stdc++.h>

#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define clr(x) memset((x), 0, sizeof((x)));
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long i64;
typedef unsigned long long ull;

template<class T>
bool remin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool remax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

ll gcd(ll a, ll b) {
    a = abs(a);
    b = abs(b);
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef ll ptdata;

struct pt {
    ptdata x, y;

    pt() {}

    pt(ptdata x, ptdata y) : x(x), y(y) {}

    inline pt operator-(const pt &r) const {
        return pt(x - r.x, y - r.y);
    }

    inline pt operator+(const pt &r) const {
        return pt(x + r.x, y + r.y);
    }

    inline pt operator*(const ld &r) const {
        return pt(x * r, y * r);
    }

    inline ptdata sqlen() const {
        return abs(x * x + y * y);
    }

    inline bool operator<(const pt &r) const {
        if (x != r.x) return x < r.x;
        return y < r.y;
    }

    inline bool operator==(const pt &r) const {
        return x == r.x && y == r.y;
    }
};

ostream &operator<<(ostream &os, const pt &p) {
    return os << "(" << p.x << "," << p.y << ")";
}

inline ptdata cross(const pt &l, const pt &r) {
    return l.x * r.y - l.y * r.x;
}

inline ptdata dot(const pt &l, const pt &r) {
    return l.x * r.x + l.y * r.y;
}


ll pwmod(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

template<typename T>
inline T sqr(T x) {
    return x * x;
}

mt19937 gen;
const int N = 50 * 1000 + 10;
vector<int> g[N];
vector<int> t[N];
const int M = 1000 * 1000 + 10;
int col[M];
int n;

inline bool check() {
    forn(i, n) {
        char c[2];
        memset(c, 0, sizeof(c));
        forn(j, t[i].size()) {
            c[col[t[i][j]]] = 1;
        }
        if (!c[0] || !c[1]) {
            return false;
        }
    }
    return true;
}
int p[N][2];
int cc[N];

inline void solve() {
    n = nxt();
    int m = nxt();
    forn(i, m) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].pb(b);
        g[b].pb(a);
    }
    int K = 0;
    forn(i, n) {
        int k = nxt();
        t[i].resize(k);
        forn(j, k) {
            t[i][j] = nxt() - 1;
            remax(K, t[i][j] + 1);
        }
    }

    while (true) {
        forn(i, K) {
            col[i] = gen() & 1;
        }
        if (check()) {
            break;
        }
    }
    forn(i, n) {
        forn(j, t[i].size()) {
            p[i][col[t[i][j]]] = t[i][j];
        }
    }
    memset(cc, -1, sizeof(cc));
    forn(i, n) {
        int cnt[2];
        memset(cnt, 0, sizeof(cnt));
        for (int to : g[i]) {
            if (cc[to] == -1) continue;
            cnt[cc[to]]++;
        }
        if (cnt[0] > cnt[1]) {
            cc[i] = 1;
        } else {
            cc[i] = 0;
        }
    }
    forn(i, n) {
        if (i) cout << " ";
        cout << p[i][cc[i]] + 1;
    }
    cout << "\n";
    forn(i, K) {
        if (i) cout << " ";
        cout << col[i] + 1;
    }
    cout << "\n";
}

void prepare() {

}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    prepare();

    int t = 1;
    //t = nxt();
    forn(i, t) {
        solve();
    }

    //cerr << "Time " << clock() / (double) CLOCKS_PER_SEC << endl;
    return 0;
}