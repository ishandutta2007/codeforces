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


    int len = (1 << n);

    vi dt(len);
    for (int i = 0; i < dt.size(); ++i)
    {
        dt[i] = i;
    }

    while(dt.size() >= 4)
    {
        vi dtnw;

        for (int i = 0; i < dt.size(); i += 4)
        {
            cout << "? " << dt[i]+1 << ' ' << dt[i+2]+1 << endl;
            int as;
            cin >> as;

            int left1, left2;

            if (as == 0)
            {
                left1 = i+1;
                left2 = i+3;
            }
            if (as == 1)
            {
                left1 = i;
                left2 = i+3;
            }
            if (as == 2)
            {
                left1 = i+1;
                left2 = i+2;
            }

            cout << "? " << dt[left1]+1 << ' ' << dt[left2]+1 << endl;
            cin >> as;

            if (as == 1)
                dtnw.pb(dt[left1]);
            else
                dtnw.pb(dt[left2]);
        }

        dt = dtnw;
    }

    if (dt.size() == 1)
    {
        cout << "! " << dt[0]+1 << endl;
    }
    else
    {
        cout << "? " << dt[0]+1 << ' ' << dt[1]+1 << endl;
        int as;
        cin >> as;
        if (as == 1)
            cout << "! " << dt[0]+1 << endl;
        else
            cout << "! " << dt[1]+1 << endl;
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