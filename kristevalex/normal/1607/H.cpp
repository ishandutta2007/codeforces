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

    vector<pair<pii, pii>> data;

    ans = 0;
    vpii as(n);

    vpii old(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> m;
        data.pb({{a+b-m, min(a, a+b-m)}, {max(0ll, a-m), i}});
        old[i] = {a, b};
    }

    sort(all(data));

    int curtot = -1;
    int cura = 0;

    for (int i = 0; i < n; ++i)
    {
        if (data[i].ft.ft != curtot)
        {
            ++ans;
            curtot = data[i].ft.ft;
            cura = data[i].ft.sd;

            int id = data[i].sd.sd;
            as[id] = {cura, curtot - cura};
        }
        else if (data[i].sd.ft > cura)
        {
            ++ans;
            curtot = data[i].ft.ft;
            cura = data[i].ft.sd;

            int id = data[i].sd.sd;
            as[id] = {cura, curtot - cura};
        }
        else
        {
            int id = data[i].sd.sd;
            as[id] = {cura, curtot - cura};
        }
    }




    cout << ans << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << old[i].ft - as[i].ft << " " << old[i].sd - as[i].sd << endl;
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