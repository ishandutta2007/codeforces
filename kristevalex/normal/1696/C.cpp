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

vpll calc (vl dt)
{
    vpll ret;
    for (int i = 0; i < dt.size(); )
    {
        //log(i);
        ll cur = dt[i];
        while (cur % m == 0)
        {
            cur /= m;
        }

        ll curvl = dt[i] / cur;
       // log(curvl);
        //log(cur);



        while(i < dt.size())
        {
            ++i;
            if (i >= dt.size())
                break;

            ll cur2 = dt[i];
            while (cur2 % m == 0)
            {
                cur2 /= m;
            }

            if (cur != cur2)
                break;

            curvl += dt[i] / cur;

            //log(curvl);
        }

        ret.pb({cur, curvl});
    }

    //cendl;
    //cendl;
    return ret;
}


/*

3
5 2
3 6 5 10 3
5
3 5 5 10 3


*/


int solve()
{
    cin >> n >> m;

    vl da(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> da[i];
    }

    cin >> k;

    vl db(k);

    for (int i = 0; i < k; ++i)
    {
        cin >> db[i];
    }

    auto aa = calc(da);
    auto ab = calc(db);

    /*for (int i = 0; i < aa.size(); ++i)
    {log(aa[i].ft);
    log(aa[i].sd);
    }

    cendl;

    for (int i = 0; i < ab.size(); ++i)
    {log(ab[i].ft);
    log(ab[i].sd);
    }

    cendl;*/

    if (aa.size() != ab.size())
    {
        cno;
        return 0;
    }

    for (int i = 0; i < aa.size(); ++i){
        if (aa[i] != ab[i])
        {

            cno;
            return 0;
        }
    }




    cyes;

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