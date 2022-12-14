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



long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];

    if (n == 2)
    {
        cout << data[1] << " " << -data[0] << endl;
    }
    else if (n < 50000 || n%2 == 0)
    {
        int i = 0;
        if (n % 2 == 1)
        {
            if (data[1] + data[2] != 0)
                cout << data[1] + data[2] << " " << -data[0] << " " << -data[0] << " ";
            else if (data[0] + data[2] != 0)
                cout << -data[1]<< " " << data[0] + data[2] << " " << -data[1] << " ";
            else if (data[0] + data[1] != 0)
                cout << -data[2]<< " " << -data[2] << " " << data[0] + data[1] << " ";
            i = 3;
        }

        for (; i < n; i+=2)
        {
            cout << data[i+1] << " " <<-data[i] << " ";
        }

        cendl;
    }
    else
    {
        vvi cnt(10001);
        vi anss(n, 0);
            int _0, _1, _2;
        for (int i = 0; i < n; ++i)
        {
            cnt[abs(data[i])].pb(i);
        }

        for (int i = 0; i < cnt.size(); ++i)
        {
            if (cnt[i].size() >= 3)
            {
                _0 = cnt[i][0];
                _1 = cnt[i][1];
                _2 = cnt[i][2];
                if (data[_0] > 0)
                    anss[_0] = 1;
                else
                    anss[_0] = -1;
                if (data[_1] > 0)
                    anss[_1] = 1;
                else
                    anss[_1] = -1;
                if (data[_2] > 0)
                    anss[_2] = -2;
                else
                    anss[_2] = 2;
                break;
            }
        }
        int last = -1;
        for (int i = 0; i < n; ++i)
        {
            if (anss[i] != 0)
                continue;
            if (last == -1)
            {
                last = i;
                continue;
            }

            anss[i] = data[last];
            anss[last] = -data[i];

            last = -1;
        }

        for (int i = 0; i < n; ++i)
        {
            cout << anss[i] << " ";
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