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

inline void solve() {
    int n = nxt();
    vector<ll> a(n);
    forn(i, n) {
        a[i] = nxt();
    }
    sort(all(a));
    const ll mod = 10000 + 7;
    ll ans = 0;
    forn(i, n) {
        ans += a[i] * a[n - 1 - i] % mod;
    }
    ans %= mod;
    cout << ans << "\n";
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