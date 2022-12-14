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
#define ft first
#define sd second
#define cendl cout << endl

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

const int MOD = 1000000009;
typedef modint<MOD> mint;



long long a, b, k, n, m, tmp, oddcnt = 0;



int solve()
{
    cin >> n >> m;

    vpii data(m);
    vi compid(n);
    vi compsz(n);
    vvi comp(n);

    for (int i = 0; i < m; ++i)
    {
        cin >> data[i].ft >> data[i].sd;
        --data[i].ft;
        --data[i].sd;
    }

    mint ans(1);
    for (int i = 0; i < n; ++i)
    {
        compid[i] = i;
        compsz[i] = 1;
        comp[i].pb(i);
    }

    for (int i = 0; i < m; ++i)
    {
        if (compid[data[i].ft] == compid[data[i].sd])
        {
            ans *= mint(2);
        }
        else
        {
            int smaller = data[i].ft, biger = data[i].sd;
            if (compsz[compid[smaller]] >= compsz[compid[biger]])
            {
                smaller = data[i].sd;
                biger = data[i].ft;
            }
            int sid = compid[smaller], bid = compid[biger];
            compsz[bid] += compsz[sid];

            for (int j = 0; j < comp[sid].size(); ++j)
            {
                compid[comp[sid][j]] = bid;
                comp[bid].pb(comp[sid][j]);
            }
        }

        /*for (int j = 0; j < n; ++j)
        {
            cout << compid[j] << " ";
        }
        cendl;*/


        cout << ans.x - 1 << endl;
    }

    return 0;
}
/*
7 10
1 2
2 3
3 4
1 4
5 7
6 2
6 5
1 5
3 7
4 7
*/

int main()
{
    FAST;
        solve();

    return 0;
}