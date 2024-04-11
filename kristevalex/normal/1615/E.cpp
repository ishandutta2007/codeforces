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


vvi g;

vi nums;
vi leafid;
vi prevs;
vpii range;

long long a, b, k, n, m, tmp, ans = 0, curorder = 0;


#include<vector>

struct SegmentTreeMax
{
    int sz;
    std::vector<std::pair<int, int>> tree;
    std::vector<int> adds;
    std::vector<int> tempr;


    SegmentTreeMax() {}

    SegmentTreeMax(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, {0, 0});
    }

    inline std::pair<int, int> getValue(int v)
    {
        std::pair<int, int> ret = tree[v];
        ret.first += adds[v];
        return ret;
    }

    void push(int v)
    {
        adds[2 * v] += adds[v];
        adds[2 * v + 1] += adds[v];
        adds[v] = 0;
    }

    inline std::pair<int, int> mergeVal(std::pair<int, int> val1, std::pair<int, int> val2)
    {
        return max(val1, val2);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = {tempr[tl], tl};
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));
    }

    SegmentTreeMax(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    void Build(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    std::pair<int, int> query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return {INT_MAX, -1};
		if (tl >= l && tr <= r)
            return getValue(v);

        int tm = (tl + tr) / 2;

        push(v);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));

        return mergeVal(query(v * 2, tl, tm, l, std::min(r, tm)),
                        query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    inline std::pair<int, int> Query(int l, int r)
    {
        return query(1, 0, sz - 1, l, r);
    }

    void update(int v, int tl, int tr, int l, int r, int diff)
    {

        if (tr < l) return;
        if (r < tl) return;
		if (tl == l && tr == r)
        {
			adds[v] += diff;

            //cout << "in update: v[" << v << "]; [" << tl << ", " << tr << "]; := {" << tree[v].ft << ", " << tree[v].sd << "} : " << adds[v] << endl;
			return;
		}

		int tm = (tl + tr) / 2;

		push(v);

        update (v * 2, tl, tm, l, std::min(r, tm), diff);
        update (v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, diff);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));


        //cout << "in update: v[" << v << "]; [" << tl << ", " << tr << "]; := {" << tree[v].ft << ", " << tree[v].sd << "} : " << adds[v] << endl;
    }

    inline void Update(int l, int r, int diff)
    {
        update(1, 0, sz - 1, l, r, diff);
    }
};

pii netral = {10000000, -1};

pii dfs(int cur = 0, int prev = -1, int depth = 1)
{
    pii mm = netral;
    ::prevs[cur] = prev;

    for (int i = 0; i < ::g[cur].size(); ++i)
    {
        int next = ::g[cur][i];
        if (next != prev)
        {
            pii res = dfs(next, cur, depth+1);
            mm = {min(mm.ft, res.ft), max(mm.sd, res.sd)};
        }
    }

    if (mm == netral)
    {
        mm = {curorder, curorder};
        nums.pb(depth);
        leafid.pb(cur);
        ++curorder;
    }

    range[cur] = mm;
    return mm;
}

int solve()
{
    cin >> n >> k;

    ::g.resize(n);
    ::range.resize(n);
    ::prevs.resize(n);

    for (int i = 0; i < n-1; ++i)
    {
        int t1, t2;
        cin >> t1 >> t2;
        --t1;
        --t2;

        ::g[t1].pb(t2);
        ::g[t2].pb(t1);
    }

    dfs();

    if (k >= nums.size())
    {
        if (n/2 < nums.size())
            ans = (n - nums.size()) * 1ll * nums.size();
        else
            ans = (n - min(n/2, k)) * 1ll * (min(n/2, k));

        cout << ans << endl;

        return 0;
    }

    SegmentTreeMax tree(::nums);

    /*for (int i = 0; i < nums.size(); ++i)
    {
        cout << "nums[" << i << "] = " << nums[i] << endl;
    }*/


    ll used = 0;
    for (int ix = 0; ix < k; ++ix)
    {
        auto mx = tree.Query(0, ::nums.size()-1);

        //cout << "Query : " << mx.ft << " | " << mx.sd << endl;



        used += mx.ft;

        int cur = leafid[mx.sd];
        while(cur != -1)
        {
            if (::range[cur].ft < 0)
                break;

            tree.Update(::range[cur].ft, ::range[cur].sd, -1);

            //cout << "Update : [" << ::range[cur].ft << " | " << ::range[cur].sd << "]" << endl;

            ::range[cur].ft = -1;

            cur = prevs[cur];
        }
    }
    ans = (ll)1e17;

    //cout << "used: " << used << endl;

    for (int i = 0; i <= n-used; ++i)
    {
        //cout << "! " << (k - i) * 1ll * (n - k - i) << endl;
        ans = min(ans, (k - i) * 1ll * (n - k - i));
    }


    cout << ans << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}