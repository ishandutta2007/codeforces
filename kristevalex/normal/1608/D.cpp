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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl

template<int m>
struct modint
{
    long long x;

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

std::vector<mint> pow2;
std::vector<mint> factorial;
std::vector<mint> invfactorial;

inline mint C(int N, int K)
{
    if (N < K || K < 0)
        return mint(0);

    return factorial[N] * invfactorial[K] * invfactorial[N-K];
}

inline void SetupFactorial(int sz)
{
    ++sz;
    ::pow2.resize(sz);
    ::factorial.resize(sz);
    ::invfactorial.resize(sz);

    ::pow2[0] = 1;
    ::factorial[0] = 1;
    ::invfactorial[0] = 1;
    for (int i = 1; i < sz; ++i)
    {
        ::pow2[i] = ::pow2[i-1] * mint(2);
        ::factorial[i] = ::factorial[i-1] * mint(i);
        ::invfactorial[i] = ::factorial[i].inv();
    }
}


vector<long long> data;

long long a, b, k, n, m, tmp;



int solve()
{
    mint ans(0);
    cin >> n;

    vector<string> dt(n);

    for (int i = 0; i < n; ++i)
        cin >> dt[i];

    int numBft = 0;
    int numWft = 0;
    int numBsd = 0;
    int numWsd = 0;
    int BBnum = 0;
    int WWnum = 0;
    bool BWpos = true;
    bool WBpos = true;
    for (int i = 0; i < n; ++i)
    {
        if (dt[i][0] == 'B')
            numBft++;
        if (dt[i][0] == 'B')
            WBpos = false;
        if (dt[i][0] == 'W')
            numWft++;
        if (dt[i][0] == 'W')
            BWpos = false;
        if (dt[i][1] == 'B')
            numBsd++;
        if (dt[i][1] == 'B')
            BWpos = false;
        if (dt[i][1] == 'W')
            numWsd++;
        if (dt[i][1] == 'W')
            WBpos = false;
        if (dt[i][1] == 'B' && dt[i][0] == 'B')
            BBnum++;
        if (dt[i][1] == 'W' && dt[i][0] == 'W')
            WWnum++;
    }
    int leftft = n - numBft - numWft;
    int leftsd = n - numBsd - numWsd;


    for (int i = numBft; i <= n - numWft; ++i)
    {
        mint cur(1);
        cur *= C(leftft, i-numBft);
        cur *= C(leftsd, i-numWsd);

        ans += cur;
    }


    if (BBnum == 0 && WWnum == 0)
    {
        int left = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dt[i][1] == '?' && dt[i][0] == '?')
                ++left;
        }

        ans -= pow2[left];

        if (WBpos)
            ans += mint(1);
        if (BWpos)
            ans += mint(1);
    }

    cout << ans.x << endl;

    return 0;
}


int main()
{
    SetupFactorial(100009);

    FAST;

        solve();

    return 0;
}