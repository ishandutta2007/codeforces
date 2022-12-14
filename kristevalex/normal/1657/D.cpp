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
    vl res(1e6+10, 0);

    cin >> n >> m;


    for (int i = 0; i < n; ++i)
    {
        ll c, d, h;
        cin >> c >> d >> h;
        res[c] = max(res[c], d*h);
    }

    for (int i = 1; i < res.size(); ++i)
    {
        for (int j = 2; i*j < res.size(); ++j)
        {
            res[i*j] = max(res[i*j], res[i]*j);
        }
    }

    for (int i = 1; i < res.size(); ++i)
    {
        res[i] = max(res[i], res[i-1]);
    }

    cin >> n;
    for (int id = 0; id < n; ++id)
    {
        ll d, h;
        cin >> d >> h;
        d*=h;

        if (res[m] <= d)
        {
            cout << -1 << endl;
            continue;
        }

        int l = -1;
        int r = m;
        while(r-l > 1)
        {
            int mid = (l+r)/2;
            if (res[mid] > d)
                r = mid;
            else
                l = mid;
        }
        cout << r << endl;
    }




    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}