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
using vll = vector<ll>;
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


vector<long long> data;

long long k, n, m, tmp;



int solve()
{
    cin >> n;

    vll a(n);
    vll b(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    b[0] = 0;


    vll fixed(n, 0);
    vll one(n, 0);

    for (int i = 0; i < n; ++i)
    {
        ll delta = b[i] - a[i];
        fixed[i] = delta;
        for (int j = i; j < n; j += (i+1))
        {
            a[j] += delta;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        a[i] = 0;
    }
    a[0] = -1;

    for (int i = 0; i < n; ++i)
    {
        ll delta = -a[i];
        one[i] = delta;
        for (int j = i; j < n; j += (i+1))
        {
            a[j] += delta;
        }
    }
    int q;

    vl ans(1000001, 0);



    /*for (int i = 0; i < n; ++i)
    {
        cout << fixed[i] << " ";
    }
    cendl;*/

    vector<pair<ll, pair<ll, ll>>> fll(n);
    for (int i = 0; i < n; ++i)
    {

            one[i] = -one[i];
        if (one[i] < 0)
        {
            fixed[i] = -fixed[i];
            one[i] = -one[i];
        }

        fll[i].sd.ft = fixed[i];
        fll[i].sd.sd = one[i];

        if (one[i] != 0)
            fll[i].ft = fixed[i] / one[i];
        else
            fll[i].ft = LLONG_MAX;
    }

    sort(all(fll));

    /*for (int i = 0; i < n; ++i)
    {
        cout << "fll " << fll[i].sd.ft << " " << fll[i].sd.sd << endl;
    }*/

    int curid = 0;
    ll leftans = 0;
    ll leftadd = 0;
    ll rightadd = 0;
    ll curans = 0;

    for (int i = 0; i < n; ++i)
    {
        rightadd += abs(one[i]);
        curans += abs(fixed[i]);
    }

    //cout << "for0: " << curans << endl;
    //cout << "radd: " << rightadd << endl;

    for (int i = 1; i < ans.size(); ++i)
    {
        curans += leftadd;
        for (; curid < n; ++curid)
        {
            if (fll[curid].sd.sd*i > fll[curid].sd.ft)
            {
                curans += abs(fll[curid].sd.sd*i - fll[curid].sd.ft) - abs(fll[curid].sd.sd*(i-1) - fll[curid].sd.ft);

                rightadd -= fll[curid].sd.sd;
                leftadd += fll[curid].sd.sd;
            }
            else
                break;
        }
        curans -= rightadd;

        /*if (i < 10)
            {cout << "for" << i << ": " << curans << endl;
    cout << "radd: " << rightadd << endl;}*/

        ans[i] = curans;
    }




    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        cin >> tmp;
        cout << ans[tmp] << endl;
    }

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}