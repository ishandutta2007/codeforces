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

    vi data(n, -1);

    for (int st = 0; st < n; ++st)
    {
        if (data[st] != -1)
            continue;

        while(true)
        {
            cout << "? " << st+1 << endl;
            int in;
            cin >> in;
            --in;
            if (in == st) break;
        }

        vi cyc;
        while(true)
        {
            cout << "? " << st+1 << endl;
            int in;
            cin >> in;
            --in;
            cyc.pb(in);
            if (in == st) break;
        }

        for (int i = 0; i < cyc.size(); ++i)
        {
            data[cyc[(i+cyc.size() - 1)%cyc.size()]] = cyc[i];
        }
    }






    cout << "!";
    for (int i = 0; i < n; ++i)
    {
        cout << " " << data[i] + 1;
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