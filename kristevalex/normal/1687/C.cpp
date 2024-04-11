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

    vl da(n), db(n);

    for (int i = 0; i < n; ++i)
        cin >> da[i];
    for (int i = 0; i < n; ++i)
        cin >> db[i];

    vl pdiff(n+1, 0);
    for (int i = 0; i < n; ++i)
    {
        pdiff[i+1] = pdiff[i] + da[i] - db[i];
    }

    queue<pii> Q;
    set<pii> segs;
    set<pii> segsi;

    set<int> nonzeros;

    for (int i = 0; i < n+1; ++i)
    {
        //log(pdiff[i]);
        if (pdiff[i] != 0)
            nonzeros.insert(i);
    }

    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        if (pdiff[l] != 0 || pdiff[r] != 0)
        {
            segs.insert({l, r});
            segsi.insert({r, l});
        }
        else
        {
            Q.push({l, r});
        }
    }

    if (pdiff[n] != 0)
    {
        cno;
        return 0;
    }
    //log(Q.size());

    while(!Q.empty())
    {
        pii cur = Q.front();
        int l = cur.ft;
        int r = cur.sd;
        Q.pop();

        auto it = nonzeros.upper_bound(l);
        while(it != nonzeros.end())
        {
            if (*it >= r)
                break;

            int val = *it;
            nonzeros.erase(it);
            pdiff[val] = 0;

            auto it1 = segs.lower_bound({val, -1});
            while(it1 != segs.end())
            {
                if (it1->ft > val)
                    break;

                int ll = it1->ft;
                int rr = it1->sd;

                if (pdiff[it1->sd] == 0)
                {
                    ++it1;
                    Q.push({ll, rr});
                    segs.erase({ll, rr});
                    segsi.erase({rr, ll});
                }
                else
                    ++it1;
            }

            auto it2 = segsi.lower_bound({val, -1});
            while(it2 != segsi.end())
            {
                if (it2->ft > val)
                    break;

                int rr = it2->ft;
                int ll = it2->sd;

                if (pdiff[it2->sd] == 0)
                {
                    ++it2;
                    Q.push({ll, rr});
                    segs.erase({ll, rr});
                    segsi.erase({rr, ll});
                }
                else
                    ++it2;
            }

            it = nonzeros.upper_bound(l);
        }

    }


    if (nonzeros.empty())
        cyes;
    else
        cno;

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