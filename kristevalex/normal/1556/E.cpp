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



long long a, b, k, n, m, tmp, ans = 0;


vll data;
vll prefs;





struct SegmentTree
{
    int sz;
    vector<pll> tree;



    SegmentTree() {}

    SegmentTree(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, {0, -1});
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
            tree[v] = {::prefs[tl], ::prefs[tl]};
        else
        {
            int tm = (tl + tr) / 2;
            build (v*2, tl, tm);
            build (v*2+1, tm+1, tr);

            tree[v] = mergeNodes(tree[2*v], tree[2*v + 1]);
        }

        //cout << "b "<< v << ": (" << tl << ", " << tr << ") = ";
        //tree[v].print();

    }

    void Build()
    {
        sz = ::prefs.size();
        tree.assign(4 * sz, {1e15, -1e15});
        build(1, 0, sz-1);
    }

    /*void push(int v)
    {
		adds[v * 2] = mergeNodes(adds[v], adds[v * 2]);
		adds[v * 2 + 1] = mergeNodes(adds[v], adds[v * 2 + 1]);
	}*/

	inline pll getVal(int v)
	{
	    return tree[v];
	}

	inline pll mergeNodes(pll val1, pll val2)
	{
	    return {min(val1.ft, val2.ft), max(val1.sd, val2.sd)};
	}

	/*void pushAndMerge(int v)
	{
	    push(v);
	    tree[v] = mergeNodes(getVal(2*v), getVal(2*v+1));
	}*/

    /*void update(int v, int tl, int tr, int l, int r, pii val)
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
    }*/

    pll query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return {1e15, -1e15};
		if (tl >= l && tr <= r)
            return getVal(v);


        int tm = (tl + tr) / 2;
        auto nl = query(v*2, tl, tm, l, min(r,tm));
        auto nr = query(v*2+1, tm+1, tr, max(l,tm+1), r);

        //cout << "q "<< v << ": (" << l << ", " << r << ") = ";
        //mergeNodes(nl, nr).print();

        return mergeNodes(nl, nr);
    }

    pll Query(int l, int r)
    {
        return query(1, 0, sz-1, l, r);
    }
};

SegmentTree tree;

inline pll getVL(int l, int r)
{
    pll ret = tree.Query(l, r+1);
    ret.ft -= ::prefs[l];
    ret.sd -= ::prefs[l];

    //cout << "vl for [" << l << ", " << r << "] = " << "(" << ret.ft << ", " << ret.sd << ")" <<endl;
    return ret;
}

inline ll getSM(int l, int r)
{
    return ::prefs[r+1] - ::prefs[l];
}

bool is_possible(int l, int r)
{
    pll vl = getVL(l, r);

    if (vl.sd > 0)
        return false;

    ll sm = getSM(l, r);
    if (sm - vl.sd < 0)
        return false;

    return true;
}

ll get_val(int l, int r)
{

    pll vl = getVL(l, r);

    ll sm = getSM(l, r);
    ll vl0 = max(abs(vl.ft), abs(vl.sd));
    ll vl1 = max(abs(sm - vl.ft), abs(sm - vl.sd));
    return max(vl0, vl1);
}

int solve()
{
    cin >> n >> m;
    ::data.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        ::data[i] -= tmp;
    }

    /*for (int i = 0; i < n; ++i)
    {
        cout << :: data[i] << " ";
    }
    cendl;
*/
    ::prefs.resize(n+1);
    ::prefs[0] = 0;
    //cout << ::prefs[0];
    for (int i = 1; i < ::prefs.size(); ++i)
    {
        ::prefs[i] = ::prefs[i-1] + ::data[i-1];
        //cout << " " << ::prefs[i];
    }
    //cendl;

    tree.Build();

    for (int i = 0; i < m; ++i)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        --tmp1;
        --tmp2;
        if (!is_possible(tmp1, tmp2))
            cout << -1 << endl;
        else
            cout << get_val(tmp1, tmp2) << endl;
    }



    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}