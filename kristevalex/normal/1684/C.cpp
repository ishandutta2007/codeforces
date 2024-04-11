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


vector<vi> dt;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    dt.resize(n);

    vi nums(m, 0);

    for (int i = 0; i < n; ++i)
    {
        dt[i].resize(m);
        for (int j = 0; j < m; ++j)
        {
            cin >> dt[i][j];
        }
    }
    //cendl;

    for (int i = 0; i < n; ++i)
    {
        vi cop = dt[i];
        sort(all(cop));
        for (int j = 0; j < m; ++j)
        {
            if (cop[j] != dt[i][j])
                nums[j]++;
        }
    }

    vi ns;

    for (int i = 0; i < m; ++i)
    {
        if (nums[i] == 0)
            continue;

        ns.pb(i);
    }


    if (ns.size() == 0)
    {
        cout << 1 << ' ' << 1 << endl;
        return 0;
    }

    if (ns.size() == 2)
    {
        for (int i = 0; i < n; ++i)
        {
            vi cop = dt[i];
            swap(dt[i][ns[0]], dt[i][ns[1]]);
            sort(all(cop));
            for (int j = 0; j < m; ++j)
            {
                if (cop[j] != dt[i][j])
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }


        cout << ns[0]+1 << ' ' << ns[1]+1 << endl;
        return 0;
    }

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