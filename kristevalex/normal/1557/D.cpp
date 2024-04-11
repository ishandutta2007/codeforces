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



struct SegmentTree
{
    int sz;
    vector<pii> tree;
    vector<pii> adds;



    SegmentTree() {}

    SegmentTree(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, {0, -1});
		adds.assign(4 * sz, {0, -1});
    }

    void push(int v)
    {
		adds[v * 2] = mergeNodes(adds[v], adds[v * 2]);
		adds[v * 2 + 1] = mergeNodes(adds[v], adds[v * 2 + 1]);
	}

	pii getVal(int v)
	{
	    return ((tree[v].ft > adds[v].ft)? tree[v]:adds[v]);
	}

	pii mergeNodes(pii val1, pii val2)
	{
	    return (val1.ft > val2.ft)? val1:val2;
	}

	void pushAndMerge(int v)
	{
	    push(v);
	    tree[v] = mergeNodes(getVal(2*v), getVal(2*v+1));
	}

    void update(int v, int tl, int tr, int l, int r, pii val)
    {
        if (l > r) return;
		if (tl >= l && tr <= r)
        {
			adds[v] = val;
			//cout << "tree[" << v << "][" << tl << ", " << tr << "]: (" << val.ft << ", " << val.sd << ")!" << endl;
			return;
		}

		push(v);
		int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r, tm), val);
        update (v*2+1, tm+1, tr, max(l, tm+1), r, val);
        tree[v] = mergeNodes(getVal(2*v), getVal(2*v+1));
        tree[v] = getVal(v);
        //cout << "tree[" << v << "][" << tl << ", " << tr << "]: (" << val.ft << ", " << val.sd << ")!" << endl;
    }

    void Update(int l, int r, pii val)
    {
        update(1, 0, sz-1, l, r, val);
    }

    pii query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return {0, -1};
		if (tl >= l && tr <= r)
            return getVal(v);


		push(v);
        int tm = (tl + tr) / 2;
        pii nl = query(v*2, tl, tm, l, min(r,tm));
        pii nr = query(v*2+1, tm+1, tr, max(l,tm+1), r);

        //cout << "q "<< v << ": (" << l << ", " << r << ") = ";
        //mergeNodes(nl, nr).print();

        return mergeNodes(nl, nr);
    }

    pii Query(int l, int r)
    {
        return query(1, 0, sz-1, l, r);
    }
};


int solve()
{
    cin >> n >> m;

    vector<vector<pii>> data(n);
    vi ids;
    int max_id = 0;
    int max_val = 0;
    int cur_num = 0;
    vpii dp(n);

    for (int i = 0; i < m; ++i)
    {
        int id, tmp1, tmp2;
        cin >> id >> tmp1 >> tmp2;
        --id;
        data[id].pb({tmp1, tmp2});
        ids.pb(tmp1);
        ids.pb(tmp2);
    }

    sort(all(ids));
    map<int, int> mp;
    for (int i = 0; i < ids.size(); ++i)
    {
        mp[ids[i]] = i;
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < data[i].size(); ++j)
        {
            data[i][j].ft = mp[data[i][j].ft];
            data[i][j].sd = mp[data[i][j].sd];
        }

        sort(all(data[i]));
    }

    SegmentTree tree(ids.size());

    for (int i = 0; i < n; ++i)
    {
        pii maxx = {0, -1};
        for (int j = 0; j < data[i].size(); ++j)
        {
            pii cur = tree.Query(data[i][j].ft, data[i][j].sd);
            //cout << "q" << i+1 << "[" << data[i][j].ft << ", " << data[i][j].sd << "]: (" << cur.ft << ", " << cur.sd << ")" << endl;
            if (cur.ft > maxx.ft)
                maxx = cur;
        }

        maxx.ft++;

        dp[i] = maxx;
        maxx.sd = i;
        for (int j = 0; j < data[i].size(); ++j)
        {

            //cout << "u" << i+1 << "[" << data[i][j].ft << ", " << data[i][j].sd << "]: (" << maxx.ft << ", " << maxx.sd << ")" << endl;
            tree.Update(data[i][j].ft, data[i][j].sd, maxx);
        }
    }

    int maxvl = 0;
    int maxid = -1;
    for (int i = 0; i < n; ++i)
    {//cout << "dp[" << i << "]: (" << dp[i].ft << ", " << dp[i].sd << ")" << endl;
        if (dp[i].ft > maxvl)
        {
            maxvl = dp[i].ft;
            maxid = i;
        }
    }

    vi cnt(n, 0);

    cout << n - maxvl << endl;
    while(maxid >= 0)
    {
        cnt[maxid] = 1;
        maxid = dp[maxid].sd;
    }


    for (int i = 0; i < n; ++i)
    {
        if (cnt[i] == 0)
            cout << i + 1 << " ";
    }


    cendl;




    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}