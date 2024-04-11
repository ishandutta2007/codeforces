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
        x+= other.x;
        if (x >= m) x-= m;

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
        tmp+= other;
        return tmp;
        }

    modint operator- (const modint& other) const
        {
        modint tmp = *this;
        tmp-= other;
        return tmp;
        }

    modint operator* (const modint& other) const
        {
        modint tmp = *this;
        tmp*= other;
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

vector<long long> data;

long long a = 0, b = 0, k, n, m, tmp;

mint ans;

vector<mint> factorial(300000);
vector<mint> _2pow(300000);
vector<mint> invfactorial(300000);


mint C(int N, int K)
{
    if (N < K || N < N-K)
        return mint(0);

    return factorial[N] * invfactorial[K] * invfactorial[N-K];
}



int solve()
{
    cin >> n;

    mint _2 (2);
    mint inv2 = _2.inv();

    ::factorial[0] = 1;
    ::invfactorial[0] = 1;
    ::_2pow[0] = 1;
    for (int i = 1; i < factorial.size(); ++i)
    {

        ::factorial[i] = ::factorial[i-1] * mint(i);
        ::invfactorial[i] = ::factorial[i].inv();
        ::_2pow[i] = ::_2pow[i-1] * _2;
        //if (i  < 10 )
        //    cout << ::factorial[i].x << " " << ::invfactorial[i].x << " " << ::_2pow[i].x << endl;
    }

    ans = mint(0);

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            ::data[i] = 0;
            while(x%2 == 0)
            {
                x/=2;
                ::data[i]++;
            }
        }

    sort(all(::data));

    /*for (int i = 0; i < n; ++i)
    {
        cout << ::data[i] << " ";
    }
    cendl;*/

    vi pws;

    int curtotal = 0;
    int total = 0;
    int curval = 0;
    for (int i = 0; i < n; )
    {
        curval = ::data[i];
        curtotal = 0;
        while(i < n)
        {
            if (::data[i] != curval)
                break;

            ++i;
            ++curtotal;
        }

        if (curval == 0)
            a = curtotal;
        else
            pws.pb(curtotal);

        /*for (int i = 2; i <= curtotal; ++i)
        {
            ans += (_2pow[total] - mint(1))*C(curtotal, i);

        }

        total += curtotal;*/

    }
    b = n - a;

    //cout << a << ":" << b << endl;


    ans += _2pow[b] * (_2pow[a] - mint(1));

    for (int i = 0; i < pws.size(); ++i)
    {
        b-=pws[i];
        for (int j = 2; j <= pws[i]; j+=2)
        {
            ans += (_2pow[b])*C(pws[i], j);
        }
    }


    cout << ans.x << endl;


    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}