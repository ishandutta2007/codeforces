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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
    {
        ll cur = 0;
        for (int j = 0; j < m; ++j)
        {
            ll x;
            cin >> x;
            cur += j * x;
        }
        ::data[i] = cur;
    }

    ll mx = -1;
    ll mn = ::data[0];
    ll mxid = -1;

    for (int i = 0; i < n; ++i)
    {
        mn = min(mn, ::data[i]);

        if (::data[i] > mx)
        {
            mxid = i;
            mx = ::data[i];
        }
    }




    cout << mxid + 1 << ' ' << mx - mn << endl;

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