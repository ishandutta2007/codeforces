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
#define srt(x, y) min(x, y), max(x, y)
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl


vvi g;

vi prevs;



struct snm
{
    int sz;
    vector<int> values;
    vector<int> groupIDs;
    vector<vector<int>> groups;

    snm (const vector<int>& init)
    {
        values = init;
        sz = values.size();
        groupIDs.resize(sz);
        groups.resize(sz);

        for (int i = 0; i < sz; ++i)
        {
            groupIDs[i] = i;
            groups[i] = vector<int>(1, i);
        }
    }

    snm (int szz)
    {
        sz = szz;
        values.assign(sz, 0);
        groupIDs.resize(sz);
        groups.resize(sz);

        for (int i = 0; i < sz; ++i)
        {
            groupIDs[i] = i;
            groups[i] = vector<int>(1, i);
        }
    }

    bool mergeByID(int id1, int id2, int val)
    {
        //cout << "merge " << id1 << " " << id2 << " = " << val << endl;

        int gr1 = groupIDs[id1];
        int gr2 = groupIDs[id2];


        //cout << "gr " << gr1 << " " << gr2 << endl;

        if (gr1 == gr2)
            return ((val + values[id1] + values[id2])%2 == 0);

        if (groups[gr1].size() < groups[gr2].size())
        {
            int tm = gr1;
            gr1 = gr2;
            gr2 = tm;
        }

        if ((val + values[id1] + values[id2])%2 == 1)
        {
            //cout << "ch!" << endl;
            for (int i = 0; i < groups[gr2].size(); ++i)
            {
                values[groups[gr2][i]] ^= 1;
            }
        }

        for (int i = 0; i < groups[gr2].size(); ++i)
        {
            groups[gr1].pb(groups[gr2][i]);
            groupIDs[groups[gr2][i]] = gr1;
        }

        groups[gr2] = vi();


        /*for (int i = 0; i < sz; ++i)
        {
            cout << values[i] << " ";
        }
        cendl;*/

        return true;
    }
};




long long a, b, k, n, m, tmp, ans = 0;

int dfs(int cur = 0, int prev = -1)
{
    ::prevs[cur] = prev;

    //cout << "dfs " << cur << " " << prev << endl;

    for (int i = 0; i < ::g[cur].size(); ++i)
    {
        int next = ::g[cur][i];
        if (next != prev)
        {
            dfs(next, cur);
        }
    }
}

int solve()
{
    cin >> n >> m;

    map<pii, int> m_;


    vector<pair<pii, int>> toadd;

    ::g.assign(n, vi());
    ::prevs.assign(n, -1);

    for (int i = 0; i < n-1; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2 >> tmp;

        --t1;
        --t2;

        ::g[t1].pb(t2);
        ::g[t2].pb(t1);

        if (tmp >= 0)
        {
            m_[{srt(t1, t2)}] = tmp;

            int sum = 0;
            while(tmp > 0)
            {
                if (tmp & 1)
                    ++sum;
                tmp /= 2;
            }

            toadd.pb({{t1, t2}, sum%2});
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2 >> tmp;

        --t1;
        --t2;

        toadd.pb({{t1, t2}, tmp});
    }

    dfs();

    /*cout << "prevs: " << endl;
    for (int i = 0; i < n; ++i)
    {
cout << i <<":= " << prevs[i] << endl;
    }

*/

    snm SNM(n);

    //cout << "hi!" << endl;

    for (int i = 0; i < toadd.size(); ++i)
    {
    //cout << "hi! " << i << endl;
        if (!SNM.mergeByID(toadd[i].ft.ft, toadd[i].ft.sd, toadd[i].sd))
        {
            cno;
            return 0;
        }
    }

    cyes;

    for (int i = 1; i < n; ++i)
    {

        cout << i+1 << " " << (::prevs[i]+1) << " ";
        if(m_.count({srt(i, ::prevs[i])}) != 0)
            cout << m_[{srt(i, prevs[i])}] << endl;
        else
            cout << (SNM.values[i] ^ SNM.values[prevs[i]]) << endl;
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