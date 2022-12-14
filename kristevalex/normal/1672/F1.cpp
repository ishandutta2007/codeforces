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
    cin >> n;

    vi data(n);
    vpii cnt(n+1, {0, 0});
    for (int i = 0; i < n+1; ++i)
    {
        cnt[i].sd = i;
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
        cnt[data[i]].ft++;
    }

    sort(all(cnt));
    reverse(all(cnt));

    vi order(n+1, 0);

    vvi groups(n+1);
    for (int i = 0; i < n+1; ++i)
    {
        order[cnt[i].sd] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        groups[order[data[i]]].pb(i);
    }

    for (int id = 0; id < groups[0].size(); ++id)
    {
        vi curcyc;
        for (int i = 0; i < groups.size(); ++i)
        {
            if (groups[i].size() <= id)
                break;

            curcyc.pb(groups[i][id]);
        }

        if (curcyc.size() < 2)
            break;

        for (int i = 0; i < curcyc.size()-1; ++i)
        {
            int p1 = curcyc[i];
            int p2 = curcyc[i+1];
            int val = data[p1];
            data[p1] = data[p2];
            data[p2] = val;
        }
    }




    for (int i = 0; i < n; ++i)
    {
        cout << data[i] << ' ';
    }
    cout << "\n";

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