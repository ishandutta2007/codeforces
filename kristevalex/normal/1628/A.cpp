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
        cin >> data[i];

    vi cnt(n+2);

    for (int i = 0; i < n; ++i)
    {
        cnt[data[i]]++;
    }
    int min0 = n+3;

    for (int i = n+1; i >= 0; --i)
    {
        if (cnt[i] == 0)
            min0 = i;
    }

    int minn = min0;

    vi as;
    int id = 0;
    while (id < n)
    {
        min0 = minn;
        vi cn(min0, 0);
        int sum = 0;
        if (data[id] < cn.size())
        {
            cn[data[id]] = 1;
            ++sum;
        }
        cnt[data[id]]--;
        if (cnt[data[id]] == 0 && data[id] < minn)
            minn = data[id];
        ++id;
        as.pb(min0);
        while(sum < cn.size() && id < n)
        {
            if (data[id] < cn.size())
            {
                if (cn[data[id]] == 0)
                {
                    cn[data[id]] = 1;
                    ++sum;
                }
            }

            cnt[data[id]]--;
            if (cnt[data[id]] == 0 && data[id] < minn)
                minn = data[id];
            ++id;
        }
    }


    cout << as.size() << endl;
    for (int i = 0; i < as.size(); ++i)
    {
        cout << as[i] << " ";
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