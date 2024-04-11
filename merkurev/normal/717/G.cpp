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


typedef long long D;
const D INF = LLONG_MAX;

struct Edge {
    int fr, to;
    D c, cost, f;
    Edge() {}
    Edge(int fr, int to, D c, D cost) : fr(fr), to(to), c(c), cost(cost), f(0) {}
};

const int N = 510;
struct G {
    vector<Edge> e;
    vector<int> g[N];
    char u[N];
    D d[N];
    int q[N];
    int p[N];
    int n, s, t;

    void addEdge(int fr, int to, D c, D cost) {
        g[fr].pb(int(e.size()));
        e.pb(Edge(fr, to, c, cost));
        g[to].pb(int(e.size()));
        e.pb(Edge(to, fr, 0, -cost));
    }

    bool fb() {
        memset(p, -1, n * sizeof(int));
        memset(d, 0x3f, n * sizeof(D));
        memset(u, 0, n * sizeof(char));
        d[s] = 0;
        u[s] = 1;
        int q1 = 0, q2 = 0;
        q[q2++] = s;
        while (q1 != q2) {
            int v = q[q1++];
            if (q1 == N) q1 = 0;
            u[v] = 0;
            for (int id : g[v]) {
                if (e[id].f == e[id].c) continue;
                int to = e[id].to;
                D len = e[id].cost;
                if (d[to] > d[v] + len) {
                    d[to] = d[v] + len;
                    p[to] = id;
                    if (!u[to]) {
                        q[q2++] = to;
                        if (q2 == N) q2 = 0;
                        u[to] = 1;
                    }
                }
            }
        }
        return p[t] != -1;
    }

    D push(D pushed = INF) {
        int v = t;
        while (v != s) {
            pushed = min(pushed, e[p[v]].c - e[p[v]].f);
            v = e[p[v]].fr;
        }
        v = t;
        while (v != s) {
            e[p[v]].f += pushed;
            e[p[v] ^ 1].f -= pushed;
            v = e[p[v]].fr;
        }
        return pushed;
    }

    pair<D, D> minCostFlow(int S, int T, D need) {
        s = S, t = T;
        D flow = 0;
        D cost = 0;
        while (fb() && need > 0) {
            D add = push(need);
            cost += add * d[t];
            flow += add;
        }
        return make_pair(flow, cost);
    }
};


char buf[10000];

inline void solve() {
    int n = nxt();
    scanf("%s", buf);
    string s = buf;
    int m = nxt();
    vector<pair<string, int> > a(m);
    forn(i, m) {
        scanf("%s", buf);
        string t = buf;
        int c = nxt();
        a[i].x = t;
        a[i].y = c;
    }
    int x = nxt();
    G g;
    g.n = n + 2;
    forn(i, n + 1) {
        g.addEdge(i, i + 1, x, 0);
    }
    forn(i, m) {
        forn(j, max(0, int(n - a[i].x.length() + 1))) {
            if (s.substr(j, a[i].x.length()) == a[i].x) {
                g.addEdge(j + 1, j + a[i].x.length() + 1, 1, -a[i].y);
            }
        }
    }
    auto res = g.minCostFlow(0, n + 1, x);
    cout << -res.y << "\n";
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