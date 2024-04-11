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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;
    ++n;
    mint as(0);

    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    data.pb(0);

    int i = 0;
    int x = data[0] - 1;


    vector<mint> dpl(5e5);
    dpl[0] = mint(1);

    mint inv2 = mint(2).inv();
    for (int i = 1; i < dpl.size(); ++i)
    {
        dpl[i] = dpl[i-1]*inv2 + mint(1);
    }

    while(x >= 0 && i < n)
    {
        //log(i);
        //log(x);
        mint cr = C(i + x, i)*dpl[i+x];

        if (x+1 == data[i] && data[i] != data[i+1])
            as += cr;
        else
            as += cr * inv2;
        if (x == data[i+1] - 1)
        {
            ++i;
            continue;
        }
        if (x == data[i+1])
        {
            ++i;
            --x;
            continue;
        }

        --x;
    }




    cout << as.x << endl;

    return 0;
}


int main()
{
    FAST;

    SetupFactorial(1000000);

        solve();

    return 0;
}