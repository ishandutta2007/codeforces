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


long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi data(n);
    ans = 0;
    a = 0;
    b = 0;
    int nonzer = 0;
    int val = -1;

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    for (int i = 1; i < n-1; ++i)
    {
        b += data[i]/2;
        a += data[i]%2;
        if (data[i] > 0)
            {++nonzer;
            val = data[i];}
    }

    //log(a);
    //log(b);

    if (a > 0 && b == 0)
    {
        cout << -1 << endl;
        return 0;
    }


    if(a > 1 || a == 0 || nonzer != 1)
    {
        cout << a + b << endl;
        return 0;
    }

    if (n == 3)
    {
        cout << -1 << endl;
        return 0;
    }

    if (val >= 5)
    {
        cout << (val+3) / 2 << endl;
    }
    else
        cout << -1 << endl;



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