#include <vector>

template<int m>
struct modint
{
    int x;

    modint() :
        x(0) {}

    modint(long long arg)
    {
        arg%= m;
        if (arg < 0) x = arg + m;
        else x = arg;
    }

    modint& operator+= (const modint& other)
    {
        x += other.x;
        if (x >= m) x -= m;

        return *this;
    }

    modint& operator*= (const modint& other)
    {
        x = (x * 1ll * other.x) % m;
        return *this;
    }

    modint& operator-= (const modint& other)
    {
        x+= m - other.x;
        if (x >= m) x-= m;

        return *this;
    }

    modint operator+ (const modint& other) const
    {
        modint tmp = *this;
        tmp += other;
        return tmp;
    }

    modint operator- (const modint& other) const
    {
        modint tmp = *this;
        tmp -= other;
        return tmp;
    }

    modint operator* (const modint& other) const
    {
        modint tmp = *this;
        tmp *= other;
        return tmp;
    }

    explicit operator int () const
    {
        return x;
    }

    modint& operator++ ()
    {
        ++x;
        if (x == m) x = 0;

        return *this;
    }

    modint& operator-- ()
    {
        if (x == 0) x = m-1;
        else --x;

        return *this;
    }

    modint operator++ (int)
    {
        modint tmp = *this;
        ++*this;

        return tmp;
    }

    modint operator-- (int)
    {
        modint tmp = *this;
        --*this;

        return tmp;
    }

    bool operator== (const modint& other) const
    {
        return x == other.x;
    }

    bool operator!= (const modint& other) const
    {
        return x != other.x;
    }

    template<class T>
    modint operator^ (T arg) const
    {
        if (arg == 0) return 1;
        if (arg == 1) return x;

        auto t = *this ^ (arg >> 1);
        t*= t;

        if (arg & 1) t*= *this;

        return t;
    }

    modint inv() const // works clearly only when 'm' is prime number
    {
        return *this ^ (m-2);
    }
};

const int MOD = 998244353;
typedef modint<MOD> mint;
const int root = 31;
const int root_1 = 128805723;
const int root_pw = 1 << 23;
const mint mroot = mint(root);
const mint mroot_1 = mint(root_1);

void fft (std::vector<mint>& a, bool invert)
{
    int n = a.size();

    for (int i = 1, j = 0; i < n; ++i)
    {
        int bit = n >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j)
            std::swap (a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1)
    {
        mint wlen = invert ? mroot_1 : mroot;
        for (int i = len; i < root_pw; i <<= 1)
            wlen *= wlen;
        for (int i = 0; i < n; i += len)
        {
            mint w(1);
            for (int j = 0; j < len/2; ++j)
            {
                mint u = a[i + j];
                mint v = a[i + j + len/2] * w;
                a[i + j] = u + v;
                a[i + j + len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
    {
        mint nrev = mint(n).inv();
        for (int i = 0; i < n; ++i)
            a[i] *= nrev;
    }
}

void multiply (const std::vector<mint>& a, const std::vector<mint>& b, size_t sz, size_t ressz, std::vector<mint>& res)
{
    size_t n = 1;
    while (n < sz)  n <<= 1;
    n <<= 1;

    std::vector<mint> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
    fa.resize(n), fb.resize(n);

    for (int i = sz; i < n; ++i)
    {
        fa[i] = mint();
        fb[i] = mint();
    }


    fft (fa, false),  fft (fb, false);
    for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);

    n = std::min(n, ressz);
    if (res.size() < n)
        res.resize(n);
    for (size_t i = 0; i < n; ++i)
        res[i] = fa[i];
}
#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

vector<int> get_del(int val)
{
    vi nm;
    vi inv;
    for (int i = 1; i*i <= val; ++i)
    {
        if (val%i != 0)
            continue;

        nm.pb(i);
        if (i*i != val)
            inv.pb(val/i);
    }

    for (int i = inv.size()-1; i >= 0; --i)
    {
        nm.pb(inv[i]);
    }

    return nm;
}

vvi g;

pair<mint, mint> dfs(int cur, int prev, int del)
{
    mint curval(1);
    int sum = 0;
    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;

        auto curres = dfs(next, cur, del);
        if (del == 1)
        {
            curres.ft += curres.sd;
            curres.sd = 0;
        }

        if (curres.ft.x == 0)
        {
            curval *= curres.sd;
        }
        else
        {
            curval *= curres.ft;
            sum++;
        }
    }
    pair<mint, mint> as = {0, 0};
    sum %= del;
    if (sum == 0)
        as.ft = curval;
    if (sum == del - 1)
        as.sd = curval;

    return as;
}

int solve()
{
    cin >> n;

    g.assign(n, vi());

    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].pb(v);
        g[v].pb(u);
    }

    vi dels = get_del(n-1);

    vector<mint> as(n+1);

    for (int i = 0; i < dels.size(); ++i)
    {
        as[dels[i]] = dfs(0, -1, dels[i]).ft;
    }

    for (int i = as.size()-1; i > 0; --i)
    {
        for (int j = 2*i; j < as.size(); j += i)
        {
            as[i] -= as[j];
        }
    }


    for (int i = 1; i <= n; ++i)
    {
        cout << as[i].x << ' ';
    }
    cout << '\n';

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}