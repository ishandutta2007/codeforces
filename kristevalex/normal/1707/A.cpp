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


vector<long long> dt;

long long a, b, k, n, m, tmp;

vi ans;

bool check(ll target)
{
    ll last = min(m, target);
    int cur = 0;
    for (int i = n-1; i >= 0; --i)
    {
        ans[i] = 0;
        if (dt[i] <= cur)
        {
            --target;
            ans[i] = 1;
        }
        else if (cur < m)
        {
            ++cur;
            --target;
            ans[i] = 1;
        }
    }

    return target <= 0;
}


int solve()
{
    cin >> n >> m;

    dt.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i)
    {
        ans[i] = 1;
    }

    for (int i = 0; i < n; ++i)
        cin >> dt[i];

    if (n <= m)
    {
        //log(ans.size());
        for (int i = 0; i < n; ++i)
        {
            cout << ans[i];
        }
        cendl;
        return 0;
    }

    int l = 0;
    int r = n+1;
    while(r-l > 1)
    {
        int mid = (l+r)/2;
        if (check(mid))
        {
            l = mid;
        }
        else
            r = mid;
    }
    //log(l);

    check(l);


    for (int i = 0; i < n; ++i)
    {
        cout << ans[i];
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