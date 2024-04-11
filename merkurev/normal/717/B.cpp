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

const int N = 1000 * 1000;
const ll inf = LLONG_MAX >> 1;
struct Q {
    ll q[N];
    ll sum = 0;
    int cnt[N];
    int qs = 0, qsize = 0;
    Q() {}
    inline void add(ll val, int c) {
        sum += c;
        if (empty()) {
            q[qs] = val;
            cnt[qs] = c;
            ++qsize;
            return;
        }
        if (qsize == N) return;
        int ps1 = qs + qsize - 1;
        if (ps1 >= N) ps1 -= N;
        int ps2 = qs + qsize;
        if (ps2 >= N) ps2 -= N;
        if (q[ps1] == val) {
            cnt[ps1] += c;
            return;
        }
        q[ps2] = val;
        cnt[ps2] = c;
        qsize++;
    }
    inline bool empty() const {
        return qsize == 0;
    }
    inline pair<ll, int> min() const {
        if (empty()) return mp(inf, 1);
        return mp(q[qs], cnt[qs]);
    }
    inline pair<ll, int> max() const {
        if (empty()) return mp(-inf, 1);
        int ps1 = qs + qsize - 1;
        if (ps1 >= N) ps1 -= N;
        return mp(q[ps1], cnt[ps1]);
    }
    inline void pop() {
        sum -= cnt[qs];
        ++qs;
        --qsize;
        if (qs == N) qs = 0;
    }
};

Q q[2];

const int MAGIC = 100000;

inline void solve() {
    int n = nxt();
    ll c[2];
    c[0] = nxt();
    c[1] = nxt();
    if (c[0] == 0 || c[1] == 0) {
        ll m = c[0] + c[1];
        cout << (n - 1) * m << "\n";
        return;
    }
    q[0].add(0, 1);

    ll ans = 0;
    pair<ll, int> mi[2];
    pair<ll, int> ma[2];
    --n;
    while (n > 0) {
        forn(j, 2) {
            mi[j] = q[j].min();
            ma[j] = q[j].max();
        }
        int id = 0;
        if (mi[1].first < mi[0].first) id = 1;

        ll k = n;
        if (c[id]) {
            k = (mi[id ^ 1].first - ma[id].first) / c[id];
        }
        remin(k, (n / q[id].sum));

        if (k == 0 || q[id ^ 1].qsize < MAGIC) {
            int cc = min(mi[id].second, n);
            n -= cc;
            ans -= mi[id].first * cc;
            ans += mi[id].first * cc + c[0] * cc;
            ans += mi[id].first * cc + c[1] * cc;
            mi[id].second -= cc;
            if (mi[id].second == 0) {
                q[id].pop();
            }
            q[0].add(mi[id].first + c[0], cc);
            q[1].add(mi[id].first + c[1], cc);
        } else {
//            cerr << k << "\n";
//            cerr << q[id].qsize << "\n";
            vector<pair<ll, int> > w;
            while (!q[id].empty()) {
                w.push_back(q[id].min());
                q[id].pop();
            }
            for (auto pa : w) {
                ans -= pa.first * pa.second;
            }
            for (auto pa : w) {
//                cerr << pa.first * pa.second + k * c[id] * pa.second << "\n";
//                cerr << k * pa.first * pa.second + k * (k - 1) / 2 * c[id] + k * c[id ^ 1] * pa.second << "\n";
                ans += pa.first * pa.second + k * c[id] * pa.second;
                ans += k * pa.first * pa.second + k * (k - 1) / 2 * c[id] + k * c[id ^ 1] * pa.second;
                q[id].add(pa.first + k * c[id], pa.second);
            }
            n -= k * q[id].sum;
        }
    }
    cout << ans << "\n";
}

void prepare() {

}

int main() {
#ifdef LOCAL
    //freopen("input.txt", "r", stdin);
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
    //14999999850000000
    //195405044762803700
    //9999999999999999
    //100000000 1 100000000
    //20042860182236000
    cerr << "Time " << clock() / (double) CLOCKS_PER_SEC << endl;
    return 0;
}