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
    cin >> n >> m;

    vl data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    vl maxs(n+1, -1e11);
    maxs[0] = 0;

    for (int i = 0; i < n; ++i)
    {
        ll cursum = 0;
        for (int j = i; j < n; ++j)
        {
            cursum += data[j];
            maxs[j-i+1] = max(maxs[j-i+1], cursum);
        }
    }



    if (m > 0)
    {
        for (int i = 0; i <= n; ++i)
        {
            ll as = 0;
            for (int j = 0; j <= n; ++j)
            {
                as = max(as, maxs[j] + min(i, j)*m);
            }
            cout << as << ' ';
        }
        cendl;
    }
    else
    {
        for (int i = 0; i <= n; ++i)
        {
            ll as = 0;
            for (int j = 0; j <= n; ++j)
            {
                as = max(as, maxs[j] + max(j - (n-i), 0ll)*m);
            }
            cout << as << ' ';
        }
        cendl;
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