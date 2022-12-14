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


vi data;

long long a, b, k, n, m, tmp, ans = 0;
ll cur_sum = 0;
ll cur_ans = 0;

const int Maxvl = 300002;



struct SegmentTree
{
    int sz;
    vector<ll> tree;
    vector<ll> adds;
    vi tempr;



    SegmentTree() {}

    SegmentTree(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
        adds.assign(4 * sz, 0);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = tempr[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2*v, tl, tm);
        build(2*v+1, tm+1, tr);
        tree[v] = mergeNodes(getVal(2*v, tl, tm), getVal(2*v+1, tm+1, tr));
    }

    SegmentTree(vi dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz-1);
    }

	inline ll getVal(int v, int tl, int tr)
	{
	    return tree[v] + adds[v] * (tr - tl + 1ll);
	}

	inline ll mergeNodes(ll val1, ll val2)
	{
	    return val1 + val2;
	}

	inline void push(int v)
	{
	    adds[2*v] += adds[v];
	    adds[2*v+1] += adds[v];
	    adds[v] = 0;
	}

    ll query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
		if (tl >= l && tr <= r)
            return getVal(v, tl, tr);


        int tm = (tl + tr) / 2;

        push(v);
        tree[v] = mergeNodes(getVal(2*v, tl, tm), getVal(2*v+1, tm+1, tr));

        auto nl = query(v*2, tl, tm, l, min(r,tm));
        auto nr = query(v*2+1, tm+1, tr, max(l,tm+1), r);

        return mergeNodes(nl, nr);
    }

    ll Query(int l, int r)
    {
        return query(1, 0, sz-1, l, r);
    }

    void update(int v, int tl, int tr, int l, int r, int diff)
    {
        if (tr < l) return;
        if (r < tl) return;
		if (tl == l && tr == r)
        {
			adds[v] += diff;
            //cout << "upd[" << v << "](" << tl << ", " << tr << "): vl: " << tree[v] << ", adds: " << adds[v] << endl;
			return;
		}

		push(v);

		int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r, tm), diff);
        update (v*2+1, tm+1, tr, max(l, tm+1), r, diff);
        tree[v] = mergeNodes(getVal(2*v, tl, tm), getVal(2*v+1, tm+1, tr));


        //cout << "upd[" << v << "](" << tl << ", " << tr << "): vl: " << tree[v] << ", adds: " << adds[v] << endl;
    }

    void Update(int l, int r, int diff)
    {
        update(1, 0, sz-1, l, r, diff);
    }
};

struct SegmentTreeSum
{
    int sz;
    std::vector<long long> tree;
    std::vector<int> tempr;


    SegmentTreeSum() {}

    SegmentTreeSum(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = tempr[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    SegmentTreeSum(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
		if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;

        return query(v * 2, tl, tm, l, std::min(r, tm)) +
               query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
    }

    inline long long Query(int l, int r)
    {
        return query(1, 0, sz - 1, l, r);
    }

    void update(int v, int tl, int tr, int id, int val)
    {
        if (tr < id) return;
        if (id < tl) return;
		if (tl == id && tr == id)
        {
			tree[v] += val;
			return;
		}

		int tm = (tl + tr) / 2;
        update (v * 2, tl, tm, id, val);
        update (v * 2 + 1, tm + 1, tr, id, val);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    inline void Update(int id, int val)
    {
        update(1, 0, sz - 1, id, val);
    }
};


template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

struct Fenwick{
    int sz;
    vector<ll> tree;
    Fenwick() {}
    Fenwick(int _n) {
        sz = _n;
        tree.assign(sz, 0);
    }
    void Update(int pos, ll val) {
        for (; pos < sz; pos |= pos + 1) {
            tree[pos] += val;
        }
        // tree[pos] += val;
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    ll Query(int l, int r) {
        chkmax(l, 0);
        chkmin(r, sz - 1);
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

int solve()
{
    cin >> n;


    SegmentTree mass(Maxvl);

    Fenwick sing(Maxvl);




    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;
        cur_ans += x * i;
        cur_ans += cur_sum;
        cur_sum += x;



        cur_ans -= mass.Query(x, x);

        int st = x;
        int en = 2*st - 1;
        int crval = 1;

        while(true)
        {
            en = min(en, Maxvl-1);
            mass.Update(st, en, crval * x);
            cur_ans -= sing.Query(st, en) * x * crval;

            if (en == Maxvl-1)
                break;

            en += x;
            st += x;
            ++crval;
        }

        sing.Update(x, 1);




        cout << cur_ans << endl;
    }

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}