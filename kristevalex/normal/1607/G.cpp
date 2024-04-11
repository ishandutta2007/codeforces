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
    cin >> n >> m;

    vector<pair<pii, pii>> data;

    ans = 0;
    vpii as(n);

    vpii old(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b;
        data.pb({{a+b-m, min(a, a+b-m)}, {max(0ll, a-m), i}});

        //cout << "!" << max(0ll, a-m) << " " << min(a, a+b-m) << endl;
        old[i] = {a, b};
    }

    ll ressum = 0;
    for (int i = 0; i < n; ++i)
    {
        ressum += data[i].ft.ft;
    }

    ll left = ressum / 2;

    for (int i = 0; i < n; ++i)
    {
        left -= data[i].sd.ft;
    }


    int curtot = -1;
    int cura = 0;

    for (int i = 0; i < n; ++i)
    {
        /*if (left <= 0)
        {
            curtot = data[i].ft.ft;
            cura = data[i].sd.ft;
            as[i] = {cura, curtot - cura};
        }
        else
        {*/
            ll diff = data[i].ft.sd - data[i].sd.ft;

            //cout << "i" << i << " diff" << diff << endl;
            diff = min(diff, left);
            diff = max(diff, 0ll);

            curtot = data[i].ft.ft;
            cura = data[i].sd.ft + diff;
            left -= diff;

            as[i] = {cura, curtot - cura};
        //}
    }


    ll atot = ressum/2 - left;



    cout << abs(ressum - 2*atot) << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << old[i].ft - as[i].ft << " " << old[i].sd - as[i].sd << endl;
    }

    return 0;
}

/*
1
3 6
1 8
1 9
30 10
*/


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}