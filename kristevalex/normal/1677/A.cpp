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

    for (int i = 0; i < n; ++i)
        {cin >> data[i]; --data[i];}

    vvi ls(n, vi(n, 0));
    vvi mr(n, vi(n, 0));

    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = 0; j < n; ++j)
        {
            if (data[j] < i)
                ++cur;

            ls[j][i] = cur;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        int cur = 0;
        for (int j = n-1; j >= 0; --j)
        {
            if (data[j] < i)
                ++cur;

            mr[j][i] = cur;
        }
    }

    ans = 0;

    for (int i = 1; i < n; ++i)
    {
        for (int j = i+1; j < n-1; ++j)
        {

            ll l = ls[i-1][data[j]];
            ll r = mr[j+1][data[i]];

            /*if (l*r > 0)
            {
                log(i);
                log(j);
                log(l);
                log(r);
                cendl;
            }*/

            ans += l*r;
        }
    }





    cout << ans << endl;

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