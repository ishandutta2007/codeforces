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

    vvi data(2*n, vi(2*n));
    ans = 0;

    for (int i = 0; i < 2*n; ++i)
    {
        for (int j = 0; j < 2*n; ++j)
        {
            cin >> data[i][j];
            if (i >= n && j >= n)
                ans += data[i][j];
        }
    }

    int minx = 1e9;

    minx = min(minx, data[0][n]);
    minx = min(minx, data[n][0]);
    minx = min(minx, data[2*n-1][0]);
    minx = min(minx, data[0][2*n-1]);
    minx = min(minx, data[n-1][n]);
    minx = min(minx, data[n][n-1]);
    minx = min(minx, data[n-1][2*n-1]);
    minx = min(minx, data[2*n-1][n-1]);


    cout << ans + minx << endl;

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