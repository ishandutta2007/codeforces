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


std::vector<mint> factorial;
std::vector<mint> invfactorial;

inline mint C(int N, int K)
{
    if (K == 0 && N == -1)
        return mint(1);

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

mint Get(int l, int r)
{
    if (l == -1 || r == -1)
        return 1;

    mint as(0);

    for (int i = 0; i <= min(l, r)+1; ++i)
    {
        as += C(l+1, i)*C(r+1, i);
    }

    return as;
}

int solve()
{
    cin >> n;

    vi dt(n);
    cin >> dt;

    mint ways(1);

    int l0 = -1;
    int r0 = n;

    for (int i = 0; i < n; ++i)
    {
        if (dt[i] == 0)
            l0 = i;
        else
            break;
    }

    for (int i = n-1; i >= 0; --i)
    {
        if (dt[i] == 0)
            r0 = i;
        else
            break;
    }
    if (l0 >= r0)
    {
        mint _2 = mint(2);

       _2 = _2 ^(n-1);

        cout << _2.x << endl;
        return 0;
    }

    ways = Get(l0, n-r0-1);



    ll suml = 0;
    ll sumr = 0;
    int idl = l0;
    int idr = r0;

    while(idr - idl > 1)
    {
        if (suml <= sumr)
        {
            ++idl;
            suml += dt[idl];
        }
        else
        {
            --idr;
            sumr += dt[idr];
        }

        if (sumr == suml)
        {
            int l0 = idl;
            int r0 = idr;

            for (int i = idl+1; i < n; ++i)
            {
                if (dt[i] == 0)
                    l0 = i;
                else
                    break;
            }

            for (int i = idr-1; i >= 0; --i)
            {
                if (dt[i] == 0)
                    r0 = i;
                else
                    break;
            }
            if (l0 >= r0 || idr - idl == 1)
            {
                mint _2 = mint(2);

                _2 = _2 ^ (idr-idl);

                cout << (ways*_2).x << endl;
                return 0;
            }

            ways *= Get(l0-idl, idr-r0);
            idl = l0;
            idr = r0;
        }
    }





    cout << ways.x << endl;

    return 0;
}


int main()
{
    FAST;

    SetupFactorial(3000000);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}