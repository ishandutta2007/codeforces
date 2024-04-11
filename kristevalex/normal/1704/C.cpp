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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> m >> n;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    sort(all(::data));

    vi lens;

    for (int i = 0; i < ::data.size(); ++i)
    {
        int st = ::data[i];
        int en = ::data[(i+1)%n];
        if (i == n-1)
            en += m;
        log(st);
        log(en);

        if (en - st > 0)
        {
            int ln = en-st-1;
            lens.pb(ln);
        }
    }

    sort(all(lens));
    ll cnt = 0;
    ans = 0;


    for (int i = lens.size()-1; i >= 0; --i)
    {
        int ln = lens[i];

        int left = ln - 2*cnt;

        log(ln);
        log(cnt);
        if (left == 1 || left == 2)
        {
            ans += 1;
            log(ans);
            cnt += 1;
            continue;
        }

        if (left <= 0)
            continue;

        ans += left - 1;
        cnt += 2;
    }




    cout << m-ans << endl;

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