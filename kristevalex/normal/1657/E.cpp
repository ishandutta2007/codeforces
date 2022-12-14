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
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

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

const int MOD = 998244353 ;
typedef modint<MOD> mint;

std::vector<mint> factorial;
std::vector<mint> invfactorial;

inline mint C(int N, int K)
{
    if (N < K || K < 0)
        return mint();

    return factorial[N] * invfactorial[K] * invfactorial[N-K];
}

inline void SetupFactorial(int sz)
{
    ++sz;
    ::factorial.resize(sz);
    ::invfactorial.resize(sz);

    ::factorial[0] = 1;
    for (int i = 1; i < sz; ++i)
        ::factorial[i] = ::factorial[i-1] * mint(i);

    ::invfactorial[sz-1] = ::factorial[sz-1].inv();
    for (int i = sz-2; i >= 0; --i)
        ::invfactorial[i] = ::invfactorial[i+1]*mint(i+1);
}

int solve()
{
    cin >> n >> k;
    --n;

    vector<vector<mint>> pows(251, vector<mint>(251, mint(0)));
    for (int i = 0; i < 251; ++i)
    {
        for (int j = 0; j < 251; ++j)
        {
            pows[i][j] = mint(i)^j;
        }
    }

    vector<mint> invs(259, mint(0));
    for (int i = 1; i < invs.size(); ++i)
    {
        invs[i] = mint(i).inv();
    }



    vector<vector<vector<mint>>> dp(251, vector<vector<mint>>(251, vector<mint>(251, mint(0))));
    //mint dp[251][251][251] = {};
    dp[0][0][0] = mint(1);

    for (int i = 1; i <= n; ++i)
    {
        for (int l = 2; l <= i; ++l)
        {
            for (int j = 1; j <= k; ++j)
            {
                dp[i][l][j] = dp[i-1][l-1][j] * (invs[l]) * (/*mint(k-j+1)^(i-1)*/pows[k-j+1][i-1]);
                /*log(i);
                log(l);
                log(j);
                log(dp[i][l][j].x);
                cendl;*/
            }
        }

        vector<mint> sums(251, mint(0));
        for (int l = 0; l <= n; ++l)
        {
            for (int j = 0; j <= k; ++j)
            {
                sums[j] += dp[i-1][l][j];
            }
        }

        for (int j = 1; j < 251; ++j)
        {
            sums[j] += sums[j-1];
        }

        for (int j = 1; j <= k; ++j)
        {
            dp[i][1][j] = sums[j-1] * (/*mint(k-j+1)^(i-1)*/pows[k-j+1][i-1]);
            /*log(i);
            log(j);
            log(dp[i][1][j].x);
            cendl;*/
        }
    }

    mint anss(0);
    for (int l = 1; l <= n; ++l)
    {
        for (int j = 1; j <= k; ++j)
        {
            anss += dp[n][l][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        anss *= mint(i);
    }



    cout << anss.x << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}