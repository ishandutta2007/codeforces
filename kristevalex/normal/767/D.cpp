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
#define ft first
#define sd second
#define cendl cout << endl



int a, b, k, n, m, tmp, ans = 0;


struct SegmentTree
{
    int sz;
    vector<int> tree;
    vector<int> adds;

    vector<int> temprorary;


    SegmentTree() {}

    SegmentTree(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
		adds.assign(4 * sz, 0);
    }

    SegmentTree(vector<int> dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
		adds.assign(4 * sz, 0);
        temprorary = dt;

        build(1, 0, sz - 1);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = temprorary[tl];
        }
        else
        {
            int tm = (tl + tr) / 2;
            build (v*2, tl, tm);
            build (v*2+1, tm+1, tr);

            tree[v] = mergeNodes(2*v, 2*v + 1);
        }
    }

    void push(int v)
    {
		adds[v * 2] += adds[v];
		adds[v * 2 + 1] += adds[v];
		adds[v] = 0;
	}

	int getVal(int v)
	{
	    return tree[v] + adds[v];
	}

	int mergeNodes(int v1, int v2)
	{
	    return min(getVal(v1), getVal(v2));
	}

	void pushAndMerge(int v)
	{
	    push(v);
	    tree[v] = mergeNodes(2 * v, 2 * v + 1);
	}

    void update(int v, int tl, int tr, int l, int r, int diff)
    {
        if (l > r) return;
		if (tl >= l && tr <= r)
        {
			adds[v] += diff;
			return;
		}

		push(v);
		int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), diff);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, diff);
        tree[v] = mergeNodes(2 * v, 2 * v + 1);
    }

    void Update(int l, int r, int diff)
    {
        update(1, 0, sz-1, l, r, diff);
    }

    int GetMin()
    {
        return getVal(1);
    }
};


int solve()
{
    cin >> n >> m >> k;

    vi data(2000002, 0);
    data[0] = k;
    for (int i = 1; i < data.size(); ++i)
    {
        data[i] = min(m + n + 10, data[i-1] + k);
    }

    SegmentTree tr(data);

    vi init(n);
    for (int i = 0; i < n; ++i)
        cin >> init[i];

    vpii post(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> post[i].ft;
        post[i].sd = i + 1;
        if (post[i].ft >= data.size())
            post[i].ft = data.size();
    }
    sort(all(post));

    for (int i = 0; i < n; ++i)
    {

    //cout << "!" << tr.GetMin() << endl;

        if (init[i] >= data.size())
            init[i] = data.size();
        tr.Update(init[i], data.size() - 1, -1);
    }


    //cout << "!" << tr.GetMin() << endl;
    if (tr.GetMin() < 0)
    {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> as;

    for (int i = post.size() - 1; i >= 0; --i)
    {
        tr.Update(post[i].ft, data.size() - 1, -1);

        if (tr.GetMin() < 0)
            break;

        as.push_back(post[i].sd);
    }




    cout << as.size() << "\n";
    for (int i = 0; i < as.size(); ++i)
    {
        cout << as[i] << " ";
    }
    cout << "\n";

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}