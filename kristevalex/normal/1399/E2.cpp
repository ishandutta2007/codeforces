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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ft first
#define sd second
#define cendl cout << endl


vector<vector<pair<int, pii>>> g;
vi w;
multiset<pair<ll, pii>> s1;
multiset<pair<ll, pii>> s2;

long long a, b, k, n, m, tmp, ans = 0;


pli dfs(int cur, int prev)
{
    pli ret = {0, 0};
    int next_id = -1;
    for (int i = 0; i < g[cur].size(); ++i)
    {
        auto next = g[cur][i];
        if (next.ft == prev)
        {
            next_id = i;
        }
        else
        {
            pli next_ans = dfs(next.ft, cur);
            ret.sd += next_ans.sd;
            ret.ft += 1ll * next_ans.sd * next.sd.ft;
            ret.ft += next_ans.ft;
            //cout << "adding " << 1ll * next_ans.sd * next.sd.ft << endl;
        }
    }

    if (ret.sd == 0)
        ret.sd = 1;

    if (next_id != -1)
    {
        auto next = g[cur][next_id];

        ll diff = next.sd.ft - next.sd.ft/2;
        if(next.sd.sd == 1)
        {
            s1.insert({-diff * ret.sd, {next.sd.ft, ret.sd}});
        }
        else
        {
            s2.insert({-diff * ret.sd, {next.sd.ft, ret.sd}});
        }
    }

    return ret;
}

pair<ll, pii> getNext(pair<ll, pii> cur)
{
    cur.sd.ft /= 2;
    ll diff = cur.sd.ft - cur.sd.ft/2;
    cur.ft = -diff * cur.sd.sd;
    return cur;
}


int solve()
{
    cin >> n >> m;


    int tmp1, tmp2, weight, cost;

    g.assign(n, vector<pair<int, pii>>(0));

    for (int i = 0; i < n-1; ++i)
    {
        cin >> tmp1 >> tmp2 >> weight >> cost;
        tmp1--;
        tmp2--;
        g[tmp1].push_back({tmp2, {weight, cost}});
        g[tmp2].push_back({tmp1, {weight, cost}});
    }


    s1.clear();
    s2.clear();

    pli dfs_ret = dfs(0, -1);
    m = dfs_ret.ft - m;

    ll m_ = m;

    if (m <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    ans = 0;

    auto s1c = s1;
    auto s2c = s2;



    while (m > 0)
    {
        //cout <<"!" << m  << endl;
        auto doub = s2.begin();
        auto sing1 = s1.begin();
        auto sing2 = sing1;
        if (sing2 != s1.end())
            ++sing2;


        ll db = 0, sg1 = 0, sg2 = 0;
        if (doub != s2.end())
            db = doub->ft;
        if (sing1 != s1.end())
        {
            sg1 = sing1->ft;
            auto ntval = getNext(*sing1);
            sg1 += ntval.ft;

        }
        if (sing2 != s1.end())
        {
            sg2 = sing1->ft + sing2->ft;
        }

        if (db <= sg1 && db <= sg2)
        {
            auto ntval = getNext(*doub);
            m += doub->ft;
            s2.erase(doub);
            s2.insert(ntval);
        }
        else if (sg1 <= sg2)
        {
            auto ntval = getNext(*sing1);
            m += sing1->ft;
            m += ntval.ft;
            ntval = getNext(ntval);
            s1.erase(sing1);
            s1.insert(ntval);
        }
        else
        {
            auto ntval1 = getNext(*sing1);
            auto ntval2 = getNext(*sing2);
            m += sing1->ft;
            m += sing2->ft;
            s1.erase(sing1);
            s1.insert(ntval1);
            s1.erase(sing2);
            s1.insert(ntval2);
        }
        ans += 2;
    }


    s1 = s1c;
    s2 = s2c;
    if (s1.size() > 0)
    {
        m = m_;

        ll ansdb = ans;
        ans = 1;


        auto doub = s2.begin();
        auto sing1 = s1.begin();
        auto sing2 = sing1;

        auto ntval_ = getNext(*sing1);
        m += sing1->ft;
        s1.erase(sing1);
        s1.insert(ntval_);


        while (m > 0)
        {
            doub = s2.begin();
            sing1 = s1.begin();
            sing2 = sing1;
            if (sing2 != s1.end())
                ++sing2;


            ll db = 0, sg1 = 0, sg2 = 0;
            if (doub != s2.end())
                db = doub->ft;
            if (sing1 != s1.end())
            {
                sg1 = sing1->ft;
                auto ntval = getNext(*sing1);
                sg1 += ntval.ft;

            }
            if (sing2 != s1.end())
            {
                sg2 = sing1->ft + sing2->ft;
            }

            if (db <= sg1 && db <= sg2)
            {
                auto ntval = getNext(*doub);
                m += doub->ft;
                s2.erase(doub);
                s2.insert(ntval);
            }
            else if (sg1 <= sg2)
            {
                auto ntval = getNext(*sing1);
                m += sing1->ft;
                m += ntval.ft;
                ntval = getNext(ntval);
                s1.erase(sing1);
                s1.insert(ntval);
            }
            else
            {
                auto ntval1 = getNext(*sing1);
                auto ntval2 = getNext(*sing2);
                m += sing1->ft;
                m += sing2->ft;
                s1.erase(sing1);
                s1.insert(ntval1);
                s1.erase(sing2);
                s1.insert(ntval2);
            }
            ans += 2;
        }



        ans = min(ans, ansdb);
    }

    cout << ans << endl;





    //cout << dfs_ret.ft << " " << dfs_ret.sd << endl;

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