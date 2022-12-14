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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >>  a  >> b;

    if (abs(a-b) > 1)
    {
        cout << -1 << endl;
        return 0;
    }
    if (a+b > n-2)
    {
        cout << -1 << endl;
        return 0;
    }

    tmp = a;
    a = b;
    b = tmp;


    ::data.resize(n);
    int maxx = n;
    int minx = 1;

    bool lv = true;

    int id = 0;
    if (a > b)
    {
        for (; id < n-a-b-1; ++id)
        {
            ::data[id] = n-id;
            maxx = n-id-1;
        }
    }
    else
    {

        for (; id < n-a-b-1; ++id)
        {
            ::data[id] = id+1;
            minx = id+2;
        }
    }

    for (int i = id; i < n; ++i)
    {
        if (::data[i-1] > maxx)
        {
            ::data[i] = minx;
            ++minx;
        }
        else
        {
            ::data[i] = maxx;
            maxx--;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << ::data[i] << " ";
    }
    cendl;

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