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


struct Node
{
    ll val;
    int lLen;
    ll lVal;
    int rLen;
    ll rVal;
    int sz;

    Node () :
        val(0),
        lLen(0),
        lVal(0),
        rLen(0),
        rVal(0),
        sz(0) {}

    Node (int vl) :
        val(1),
        lLen(1),
        lVal(vl),
        rLen(1),
        rVal(vl),
        sz(1) {}

    void print()
    {
        cout << " val[" << val << "], lLen[" << lLen<< "], rLen[" << rLen <<"] " << endl;
    }
};

struct SegmentTree
{
    int sz;
    vector<Node> tree;

    vector<int> temprorary;


    SegmentTree() {}

    SegmentTree(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
    }

    SegmentTree(vector<int> dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        temprorary = dt;

        build(1, 0, sz - 1);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
            tree[v] = Node(temprorary[tl]);
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

	inline int getVal(int v)
	{
	    return tree[v].val;
	}

	inline Node mergeNodes(Node n1, Node n2)
	{
	    if (n2.sz == 0)
            return n1;
        if (n1.sz == 0)
            return n2;

	    Node ret;

	    ret.val = n1.val + n2.val;
	    ret.sz = n1.sz + n2.sz;
	    ret.lLen = n1.lLen;
	    ret.lVal = n1.lVal;
	    ret.rLen = n2.rLen;
	    ret.rVal = n2.rVal;

	    if (n1.rVal <= n2.lVal)
        {
            if (n1.rLen == n1.sz)
                ret.lLen = n1.sz + n2.lLen;

            if (n2.lLen == n2.sz)
                ret.rLen = n2.sz + n1.rLen;

            ret.val += 1ll*(n1.rLen + n2.lLen)*(n1.rLen + n2.lLen + 1)/2 - 1ll*(n1.rLen)*(n1.rLen + 1)/2 - 1ll*(n2.lLen)*(n2.lLen + 1)/2;
        }

	    return ret;
	}

    void update(int v, int tl, int tr, int pos, int value)
    {
        if (pos > tr || pos < tl) return;
		if (tl == pos && tr == pos)
        {
			tree[v] = Node(value);
			//cout << "u "<< v << ": (" << tl << ", " << tr << ") = ";
            //tree[v].print();
			return;
		}

		int tm = (tl + tr) / 2;
        update (v*2, tl, tm, pos, value);
        update (v*2+1, tm+1, tr, pos, value);
        tree[v] = mergeNodes(tree[2 * v], tree[2 * v + 1]);

        //cout << "u "<< v << ": (" << tl << ", " << tr << ") = ";
        //tree[v].print();
    }

    void Update(int pos, int diff)
    {
        update(1, 0, sz-1, pos, diff);
    }

    Node query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return Node();
		if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;
        Node nl = query(v*2, tl, tm, l, min(r,tm));
        Node nr = query(v*2+1, tm+1, tr, max(l,tm+1), r);

        //cout << "q "<< v << ": (" << l << ", " << r << ") = ";
        //mergeNodes(nl, nr).print();

        return mergeNodes(nl, nr);
    }

    ll GetVal(int l, int r)
    {
        return query(1, 0, sz-1, l, r).val;
    }
};


vi data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    SegmentTree tree(::data);

    //cout << "hi" << endl;

    for (int i = 0; i < m; ++i)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            tree.Update(l-1, r);

            //cout << "t1" << endl;
        }
        else
        {
            cout << tree.GetVal(l-1, r-1) << endl;
        }
    }



    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}