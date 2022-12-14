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

long long k, n, m, tmp, ans = 0;

ll inf = 1e15;

int solve()
{
    cin >> n;

    vi a(n);
    vi b(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    ll sum = 0;

    ans = 0;
    vl dp(10005, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        vl dpnw(10005, inf);
        for (int j = 0; j < dp.size(); ++j)
        {
            if (j + a[i] < dp.size() && sum >= j)
                dpnw[j + a[i]] = min(dpnw[j + a[i]], dp[j] + 2*j*a[i] + 2*(sum-j)*b[i]);
            if (j + b[i] < dp.size() && sum >= i)
                dpnw[j + b[i]] = min(dpnw[j + b[i]], dp[j] + 2*j*b[i] + 2*(sum-j)*a[i]);
        }
        dp = dpnw;
        sum += a[i];
        sum += b[i];
    }

    ans = inf;
    for (int i = 0; i < dp.size(); ++i)
    {
        ans = min(ans, dp[i]);
    }




    for (int i = 0; i < n; ++i)
    {
        ans += (n-1)*(a[i]*a[i] + b[i]*b[i]);
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