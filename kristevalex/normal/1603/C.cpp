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

const int MOD = 998244353;
typedef modint<MOD> mint;

struct Node
{
    int sum;
    int mn;
    int res;

    Node(int val)
    {
        sum = val;
        mn = val;
        res = 1;
    }

    Node()
    {
        sum = 0;
        mn = 0;
        res = 1;
    }

    Node GetLesser(int maxvl)
    {

            //cout << "g1" << endl;
        Node ret(sum);

            //cout << "g: " << maxvl  << endl;
        ret.res = (sum + maxvl - 1)/maxvl;

            //cout << "g3" << endl;

        ret.mn = sum / ret.res;

            //cout << "g4" << endl;

        return ret;
    }

    bool operator== (Node over)
    {
        if (sum == over.sum && res == over.res)
            return true;

        return false;
    }
};



int a, b, k, n, m, tmp;

mint ans;
mint cur_ans;



int solve()
{
    ans = mint(0);
    cur_ans = mint(0);

    cin >> n;

    vector<Node> data(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> m;

        data[i] = Node(m);

        //cout << "i" << i << endl;

        for (int j = i-1; j >= 0; --j)
        {
            //cout << "g" << endl;
            Node nw = data[j].GetLesser(data[j+1].mn);

            //cout << "o" << endl;
            if (data[j] == nw)
                break;


            //cout << "c" << endl;

            cur_ans += mint(1ll * (j+1) * 1ll * (nw.res - data[j].res));
            //cout << (j+1)  << " add " << (nw.res - data[j].res) << endl;

            data[j] = nw;
        }
        //cout << "i" << i << endl;
        //cout <<"cur ans " << cur_ans.x << endl;



        ans += cur_ans;
    }



    cout << ans.x << endl;

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