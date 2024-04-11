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



set<pii> st;

int Get(int id)
{
    auto it = st.upper_bound({id, 5});
    if (it == st.end())
        return 0;
    return 1 - it->sd;
}

void add(int id)
{
    int curval = Get(id);

    if (st.find({id, curval}) != st.end())
    {
        st.erase({id, curval});
    }
    else
    {
        st.insert({id, 1-curval});
    }

    if (curval == 0)
    {
        if (st.find({id+1, 1-curval}) != st.end())
        {
            st.erase({id+1, 1-curval});
        }
        else
        {
            st.insert({id+1, curval});
        }
    }
    else
    {
        auto it = st.lower_bound({id+1, -1});
        auto cur = *it;
        st.erase(cur);
        st.insert({cur.ft, 1});
        if (st.find({cur.ft+1, 1}) != st.end())
        {
            st.erase({cur.ft+1, 1});
        }
        else
        {
            st.insert({cur.ft+1, 0});
        }
    }
}

void ret(int id)
{
    int curval = Get(id);




    if (st.find({id, curval}) != st.end())
    {
        st.erase({id, curval});
    }
    else
    {
        st.insert({id, 1-curval});
    }

    if (curval == 1)
    {

        if (st.find({id+1, 1-curval}) != st.end())
        {
            st.erase({id+1, 1-curval});
        }
        else
        {
            st.insert({id+1, curval});
        }
    }
    else
    {
        auto it = st.lower_bound({id+1, -1});
        auto cur = *it;
        st.erase(cur);
        st.insert({cur.ft, 0});
        if (st.find({cur.ft+1, 0}) != st.end())
        {
            st.erase({cur.ft+1, 0});
        }
        else
        {
            st.insert({cur.ft+1, 1});
        }
    }
}


void print()
{
    for (int i = 0; i < 10; ++i)
    {
        cout << Get(i);
    }
    cendl;
    for (auto it = st.begin(); it != st.end(); ++it)
    {
        cout << "  <" << it->ft << " " << it->sd << ">  ";
    }
    cendl;
}

int solve()
{
    cin >> n >> m;

    vector<int> cnt(1000000, 0);

    vi data(n);

    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        cnt[val]++;
        data[i] = val;
    }

    for (int i = 0; i < cnt.size(); ++i)
    {
        if (cnt[i] > 1)
        {
            cnt[i+1] += cnt[i]/2;
            cnt[i] %= 2;
        }
    }

    st.insert({0, cnt[0]});

    /*for (int i = 0; i < 20; ++i)
    {
        cout << cnt[i];
    }
    cendl;*/

    for (int i = 1; i < cnt.size(); ++i)
    {

        if (cnt[i] != cnt[i-1])
        {
            st.insert({i, cnt[i]});
        }
    }

    //print();

    for (int i = 0; i < m; ++i)
    {
        int id, vl;
        cin >> id >> vl;
        --id;

        ret(data[id]);
        //print();
        add(vl);
        //print();

        auto it = st.end();
        --it;
        cout << it->ft-1 << endl;
        //cendl;
        //cendl;

        data[id] = vl;
    }





    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}