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
vector<long long> prefs;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    ::data.assign(n, 0);
    ::prefs.assign(n+1, 0);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    ::prefs[0] = 0;
    for (int i = 1; i < n+1; ++i)
    {
        ::prefs[i] = ::prefs[i-1] + ::data[i-1];
    }

    vvl dp(n, vector<ll>(500, -1));
    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = LLONG_MAX;
    }
    dp[n-1][1] = ::data[n-1];

    for (int i = n-2; i >= 0; --i)
    {
        //cout <<"hi" << i << endl;
        for (int j = 1; j < 500; ++j)
        {
            if (i + j >= n)
                break;

            if (dp[i+j][j-1] == -1)
                break;

            if (dp[i+j][j-1] > ::prefs[i+j] - ::prefs[i])
                dp[i][j] = ::prefs[i+j] - ::prefs[i];

            dp[i][j] = max(dp[i][j], dp[i+1][j]);
        }
    }

    for (int i = 499; i >= 0; --i)
    {
        if (dp[0][i] != -1)
        {
            cout << i << endl;
            return 0;
        }
    }





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