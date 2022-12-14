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
#define cyes cout << "YES\n"
#define cno cout << "NO\n"
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl


long long m;
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

int MOD = 1000000007;
#define mint modint


vector<long long> data;

long long k, n, tmp, ans = 0;
int a, b;



int solve()
{
    int q;
    cin >> n >> q >> m;
    int zeros = 0;


    vector<mint> fib(n+7);
    fib[0] = mint(1);
    fib[1] = mint(1);
    for (int i = 2; i < fib.size(); ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    vi A(n);
    vi B(n);
    vector<mint> diffs(n);

    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < n; ++i)
        cin >> B[i];

    mint old(0);
    mint nw(0);

    diffs[0] = mint(A[0]) - mint(B[0]);
    diffs[1] = (mint(A[1]) - mint(B[1])) - (mint(A[0]) - mint(B[0]));
    for (int i = 2; i < n; ++i)
    {
        mint cur = mint(A[i]) - mint(B[i]);
        cur -= mint(A[i-1]) - mint(B[i-1]);
        cur -= mint(A[i-2]) - mint(B[i-2]);
        diffs[i] = cur;
    }
    for (int i = 0; i < n; ++i)
    {
        //log(diffs[i].x);
        if (diffs[i].x == 0)
            zeros++;
    }

    for (int i = 0; i < q; ++i)
    {
        char s;
        cin >> s >> a >> b;
        mint sign(1);
        if (s == 'B')
            sign = mint(-1);

        --a;
        --b;

        if (diffs[a].x == 0)
            zeros--;
        diffs[a] += sign;
        if (diffs[a].x == 0)
            zeros++;

        if (b+1 < diffs.size())
        {
            if (diffs[b+1].x == 0)
                zeros--;
            diffs[b+1] += mint(-1) * sign * fib[b-a+1];
            if (diffs[b+1].x == 0)
                zeros++;
        }
        if (b+2 < diffs.size())
        {
            if (diffs[b+2].x == 0)
                zeros--;
            diffs[b+2] += mint(-1) * sign * fib[b-a];
            if (diffs[b+2].x == 0)
                zeros++;
        }

        /*for (int i = 0; i < n; ++i)
        {
            log(diffs[i].x);
        }*/

        if (zeros == n)
            cyes;
        else
            cno;

    }





    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}