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
    cin >> n >> m;

    vi data(n);
    vpii l(n);
    vpii r(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> data[i] >> l[i].ft >> l[i].sd >> r[i].ft >> r[i].sd;
    }

    multiset<int> pl;
    multiset<int> pr;

    if (l[0].ft <= data[0] && data[0] <= l[0].sd)
        pl.insert(0);
    if (r[0].ft <= data[0] && data[0] <= r[0].sd)
        pr.insert(0);

    vvi tracesli(n);
    vvi tracesri(n);
    vvi tracesle(n);
    vvi tracesre(n);

    for (int i = 1; i < n; ++i)
    {
        int prs = pr.size();
        int pls = pl.size();

        if (prs != 0)
        {
            pl.insert(data[i-1]);

            //log(i);
            //log(data[i-1]);
            tracesli[i].pb(data[i-1]);
        }
        int maxdel, mindel;
        if (l[i].ft <= data[i] && data[i] <= l[i].sd)
        {
            maxdel = r[i].ft-1;
            mindel = r[i].sd+1;
            //log(i);
            //log(maxdel);
            //log(mindel);
        }
        else
        {
            maxdel = 1e9;
            mindel = 0;
        }

        while(pl.begin() != pl.end())
        {
            auto it = pl.begin();
            if (*it > maxdel)
                break;
            tracesle[i].pb(*it);
            pl.erase(it);
        }

        while(pl.begin() != pl.end())
        {
            auto it = pl.end();
            --it;
            if (*it < mindel)
                break;
            tracesle[i].pb(*it);
            pl.erase(it);
        }

        //----------------

        if (pls != 0)
        {
            pr.insert(data[i-1]);
            tracesri[i].pb(data[i-1]);
        }
        if (r[i].ft <= data[i] && data[i] <= r[i].sd)
        {
            maxdel = l[i].ft-1;
            mindel = l[i].sd+1;
        }
        else
        {
            maxdel = 1e9;
            mindel = 0;
        }

        while(pr.begin() != pr.end())
        {
            auto it = pr.begin();
            if (*it > maxdel)
                break;
            tracesre[i].pb(*it);
            pr.erase(it);
        }

        while(pr.begin() != pr.end())
        {
            auto it = pr.end();
            --it;
            if (*it < mindel)
                break;
            tracesre[i].pb(*it);
            pr.erase(it);
        }
    }


    if (pl.size() != 0 || pr.size() != 0)
    {
        cyes;
        vi as(n, 0);
        int ct = 0;
        if (pl.size() == 0)
            ct = 1;
        int nt;
        if (ct == 0)
            nt = *(pl.begin());
        else
            nt = *(pr.begin());

        as[n-1] = ct;

        /*cout << "pl: ";
        for (int val : pl)
            cout << val << " ";
        cendl;
        cout << "pr: ";
        for (int val : pr)
            cout << val << " ";
        cendl;
        cendl;*/

        for (int i = n-2; i >= 0; --i)
        {
            for (int val : tracesle[i+1])
                pl.insert(val);
            for (int val : tracesli[i+1])
                pl.erase(pl.find(val));
            for (int val : tracesre[i+1])
                pr.insert(val);
            for (int val : tracesri[i+1])
                pr.erase(pr.find(val));

            /*cout << "pl: ";
            for (int val : pl)
                cout << val << " ";
            cendl;
            cout << "pr: ";
            for (int val : pr)
                cout << val << " ";
            cendl;
            cendl;*/

            if (data[i] == nt)
            {


                //as[i] = ct;
                ct = 1 - ct;

                if (ct == 0)
                {
                    if (pl.size() != 0)
                        nt = *(pl.begin());
                    else
                        ct = 1 - ct;
                }
                else
                {
                    if (pr.size() != 0)
                        nt = *(pr.begin());
                    else
                        ct = 1 - ct;
                }

                as[i] = ct;
            }
            else
            {
                as[i] = ct;
            }
        }

        for (int i = 0; i < n; ++i)
        {
            cout << as[i] << " ";
        }
        cendl;
    }
    else
        cno;

    return 0;
}

/*

3 100
2
2 3
0 1
0
0 1
0 1
3
2 3
0 1

*/


int main()
{
    FAST;
        solve();

    return 0;
}