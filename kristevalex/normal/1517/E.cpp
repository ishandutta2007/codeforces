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

vector<long long> dt;

long long a, b, k, n, m, tmp, ans = 0;

vl prefs2;
vl prefs;

mint inv2 = mint(2).inv();


// { <-> <-> <|> <-> }

mint getl(int l, int r, ll sum, int even, int len)
{ // l = 3 r = 2   l = 0 r = 5  - - -
    int oldl = l;
    int oldr = r-len;
    l = l-2;
    r = r - len+1;
    //log(l);
    //log(r);
    //log(oldl);
    //log(oldr);
    while(r-l > 1)
    {
        int mid = (l+r)/2;
        //log(mid);
        ll sumc = prefs[mid+1] - prefs[oldl];
        //log(sumc);
        sumc += (prefs2[oldr+1] - prefs2[mid+1])*(1-even*2);
        //log(sumc);

        if (sum > sumc)
            l = mid;
        else
            r = mid;
    }
    //log(l);

    int ll = l;


    if (l == oldl - 2)
        return mint(0);

    l -= oldl-2;
    ++l;
    l /=2;


    mint as(l);
    //log(as.x);

    //if (ll == oldr)
    //    as -= inv2;

    return as;
}

mint get(int l, int r, ll sum, int even)
{
    mint as(0);

    for (int i = 0; i <= r-l+1; ++i)
    {

        //cout << "getl(l<"<<l<<">, r<"<<r<<">, sum<"<<sum<<">, even<"<<even<<">, i<"<<i<<">)\n";
        //log(even);
        //log((r-i+2)%2);
        if ((r-i+2)%2 == even)
        {
            auto tm = getl(l, r, sum, even, i);
            //cout << "   " << tm.x << endl;
            as += tm;
        }
        sum += dt[r-i];
    }

    return as;
}

mint Get(int l, int r, ll sum)
{
    return get(l, r, sum, 0) + get(l, r, sum, 1);
}

// PPPPP, CPPPP, PCPPP, CCPPP, PCCPP, PCPCP, PPPPC, CPPPC, PCPPC, PPPCC


/*

1
5
1 1 1 1 1

1
1
1

1
4
9 2 2 2




*/

// PPPP3, PCPP2, PCCP, PPPC, PCPC1, PPCC(last), PCCC

int solve()
{
    cin >> n;

    dt.resize(n);
    cin >> dt;

    //log("1");



    prefs2.resize(n+1);
    prefs2[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        prefs2[i+1] = prefs2[i] + (1 - (i%2)*2)*dt[i];
    }

    prefs.resize(n+1);
    prefs[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        prefs[i+1] = prefs[i] + dt[i];
    }
    //log("hi");

    //log((getl(0, n-1, 0, 0, 0).x));
    //log((getl(0, n-1, 0, 1, 0).x));
    //return 0;


    mint as(0);
    as += Get(0, n-1, 0);
    if (dt.size() >= 3)
        as += Get(3, n-1, - dt[1] - dt[2] + dt[0]);
    if (dt.size() >= 3)
        as += Get(0, n-4, - dt[n-1] + dt[n-2] + dt[n-3]);
    if (dt.size() >= 6)
        as += Get(3, n-4, - dt[1] - dt[2] + dt[0] - dt[n-1] + dt[n-2] + dt[n-3]);


    if (n >= 4)
    {
        int l = 0;
        int r = n-2;

        while(r-l > 1)
        {
            int mid = (l+r)/2;
            if (prefs[mid+1]*2 > prefs[n])
                r = mid;
            else
                l = mid;
        }

        as += n-2 - r;
    }

    cout << as.x << endl;

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