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

const int N = 200 * 1000 + 10;
int col[N];
vector<int> g[N];
int cnt[N];

void dfs(int v, int p = -1) {
    cnt[v] = col[v] == 0;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
        cnt[v] += cnt[to];
    }
}


void dfs2(int v, int p = -1) {
    cout << v + 1 << " ";
    for (int to : g[v]) {
        if (to == p) continue;
        if (cnt[to] == 0) continue;
        col[to] ^= 1;
        dfs2(to, v);
        col[v] ^= 1;
        cout << v + 1 << " ";
    }
    if (col[v] == 0) {
        if (p == -1) {
            int ch = g[v][0];
            cout << ch + 1 << " " << v + 1 << " " << ch + 1 << " ";
        } else {
            col[p] ^= 1;
            cout << p + 1 << " " << v + 1 << " ";
        }
    }
}

inline void solve() {
    int n = nxt();
    forn(i, n) {
        col[i] = nxt();
        if (col[i] == -1) {
            col[i] = 0;
        }
    }
    forn(i, n - 1) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    dfs2(0);
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