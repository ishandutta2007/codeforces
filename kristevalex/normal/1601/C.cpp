//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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


vector<long long> fixarr;
vector<long long> fillarr;
vi anss;

long long a, b, k, n, m, tmp, ans = 0;

int GetAns(int id, int posl, int posr)
{
    int ret = posl;
    int minvl = INT_MAX;

    int tot = posr - posl;
    int lesser = 0;
    int bigger = 0;
    for (int i = posl; i < posr; ++i)
    {
        if (::fixarr[i] < ::fillarr[id])
            ++lesser;
        if (::fixarr[i] > ::fillarr[id])
            ++bigger;
        //cout << "!i: " << i << ", " << lesser << " " << bigger << endl;
    }

    int curl = 0;
    int curb = 0;
    for (int i = posl; i <= posr; ++i)
    {
        //cout << "i: " << i << ", " << lesser - curl + curb << endl;
        if (lesser - curl + curb < minvl)
        {
            minvl = lesser - curl + curb;
            ret = i;
        }


        if (i == posr)
            break;

        if (::fixarr[i] < ::fillarr[id])
            ++curl;
        if (::fixarr[i] > ::fillarr[id])
            ++curb;
    }




    ::anss[id] = ret;
    return ret;
}

pii GetAns(int idl, int idr, int posl, int posr)
{
    if (idl > idr)
        return {idr, idl};

    int mid = (idl + idr)/2;

    int midpos = GetAns(mid, posl, posr);


    pii l = GetAns(idl, mid - 1, posl, midpos);
    pii r = GetAns(mid + 1, idr, midpos, posr);

    pii ret = {min(midpos, l.ft), max(midpos, r.sd)};
    return ret;
}

vector<int> Compress(const vector<int>& arr)
{
    const int arraySize = arr.size();
    vector<pair<int, int>> indexedArr(arraySize);
    vector<int> ret(arraySize);
    for (int i = 0; i < arraySize; ++i)
        indexedArr[i] = {arr[i], i};
    sort(indexedArr.begin(), indexedArr.end());

    for (int i = 0; i < arraySize; ++i)
        ret[indexedArr[i].second] = i;

    return ret;
}

struct SegmentTree
{
    int sz;
    vector<ll> tree;



    SegmentTree() {}

    SegmentTree(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
    }

	inline ll getVal(int v)
	{
	    return tree[v];
	}

	inline ll mergeNodes(ll val1, ll val2)
	{
	    return val1 + val2;
	}

    ll query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
		if (tl >= l && tr <= r)
            return getVal(v);


        int tm = (tl + tr) / 2;
        auto nl = query(v*2, tl, tm, l, min(r,tm));
        auto nr = query(v*2+1, tm+1, tr, max(l,tm+1), r);

        return mergeNodes(nl, nr);
    }

    ll Query(int l, int r)
    {
        return query(1, 0, sz-1, l, r);
    }

    void update(int v, int tl, int tr, int id, int diff)
    {
        if (tr < id) return;
        if (id < tl) return;
		if (tl == id && tr == id)
        {
			tree[v] += diff;
			return;
		}

		int tm = (tl + tr) / 2;
        update (v*2, tl, tm, id, diff);
        update (v*2+1, tm+1, tr, id, diff);
        tree[v] = mergeNodes(getVal(2*v), getVal(2*v+1));
    }

    void Update(int id, int diff)
    {
        update(1, 0, sz-1, id, diff);
    }
};

int solve()
{
    ans = 0;
    cin >> n >> m;

    ::fixarr.resize(n);
    ::fillarr.resize(m);
    ::anss.resize(m);

    for (int i = 0; i < n; ++i)
        cin >> ::fixarr[i];

    for (int i = 0; i < m; ++i)
        cin >> ::fillarr[i];

    sort(all(fillarr));


    GetAns(0, m-1, 0, n);

    ans = 0;


    vi sm;
    int j = 0;
    for (int i = 0; i <= n; ++i)
    {
        while(j < m && ::anss[j] == i)
        {
            sm.pb(::fillarr[j]);
            ++j;
        }

        if (i == n)
            break;

        sm.pb(::fixarr[i]);
    }

    /*cout << "res: ";
    for (int i = 0; i < sm.size(); ++i)
    {
        cout << sm[i] << " ";
    }
    cendl;*/

    sm = Compress(sm);

    SegmentTree tree(sm.size());
    for (int i = 0; i < sm.size(); ++i)
    {
        ans += tree.Query(sm[i]+1, sm.size()-1);
        tree.Update(sm[i], 1);
    }

    cout << ans << endl;

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