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


vector<mint> factorial;
vector<mint> factorial_inv;

void setup_factorial(int sz)
{
    ++sz;
    factorial.resize(sz);
    factorial_inv.resize(sz);
    factorial[0] = mint(1);
    factorial_inv[0] = mint(1);

    for (int i = 1; i < sz; ++i)
    {
        factorial[i] = factorial[i-1]*mint(i);
        factorial_inv[i] = factorial[i].inv();
    }
}

mint C(int N, int K)
{
    if (K < 0 || N < 0 || K > N)
        return mint(0);

    return factorial[N] * factorial_inv[K] * factorial_inv[N-K];
}

long long a, b, k, n, m, tmp;



int solve()
{
    cin >> n >> a >> b;

    ll full = min(b-n, 1-a);
    full = max(full, 0ll);

    mint ans(0);

    mint add = mint(full) * C(n, n/2);
    if (n%2 == 1)
        add *= mint(2);
    ans += add;

    //cout << ans.x << endl;

    for (int i = full+1; i < full+n+2; ++i)
    {
        ll occl = max(a+i-1, 0ll);
        ll occr = max(n-b+i, 0ll);

        //cout << "occ " << occl << " " << occr << ":= " << C(n - occl - occr, n/2 - occl).x << endl;

        ans += C(n - occl - occr, n/2 - occl);
        if (n%2 == 1)
            ans += C(n - occl - occr, n/2 + 1 - occl);
    }






    cout << ans.x << endl;

    return 0;
}


int main()
{
    FAST;

    setup_factorial(300000);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}