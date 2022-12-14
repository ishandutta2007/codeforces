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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl


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

const int MOD = 1000000007;
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

    SetupFactorial(1000);



    vector<vector<vector<mint>>> dp(211, vector<vector<mint>>(211, vector<mint>(211, mint(0))));
    //mint dp[251][251][251] = {};
    dp[0][0][1] = mint(n);

    vector<mint> totSums(211, mint(0));
    totSums[0] = mint(1);

    for (int i = 1; i <= k; ++i)
    {
        log(i);
        for (int l = 1; l <= i; ++l)
        {
            for (int j = 1; i + j <= n && j <= k; ++j)
            {
                dp[i][l][j] = dp[i-1][l-1][j] * mint(l) * (invs[l+1]) * mint(max(n-i-j+1, 0ll));
                log(l);
                log(j);
                log(dp[i][l][j].x);
                log(dp[i-1][l-1][j].x);
                log(n-l-2*j+2);
                log(n+1);

                totSums[i] += dp[i][l][j] * invfactorial[j];
                /*log(i);
                log(l);
                log(j);
                log(dp[i][l][j].x);
                cendl;*/
            }
        }

        vector<mint> sums(251, mint(0));
        for (int l = 1; l <= i; ++l)
        {
            for (int j = 1; i + j <= n && j <= k; ++j)
            {
                dp[i][0][j] += dp[i][l][j-1] * mint(max(n-i-j+1, 0ll));

                //log(i+0);
                //log(j+0);
                //log(dp[i][0][j].x);
                //log(n-l-2*j+2);
            }
        }

        /*for (int j = 1; j < 251; ++j)
        {
            sums[j] += sums[j-1];
        }

        for (int j = 1; j <= k; ++j)
        {
            dp[i][1][j] = sums[j-1] * (/*mint(k-j+1)^(i-1)*///pows[k-j+1][i-1]);
            /*log(i);
            log(j);
            log(dp[i][1][j].x);
            cendl;*/
        //}
    }

    for (ll l = 1; l <= k; ++l)
    {
        mint as(0);
        for (int i = l%2; i <= min(n, l); i += 2)
        {
            as += totSums[i];
        }
        cout << as.x << ' ';
    }




    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}