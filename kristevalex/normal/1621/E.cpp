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



#include<vector>

struct SegmentTreeMin
{
    int sz;
    std::vector<int> tree;
    std::vector<int> adds;
    std::vector<int> tempr;


    SegmentTreeMax() {}

    SegmentTreeMax(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, 0);
        adds.assign(4 * sz, 0);
    }

    inline int getValue(int v)
    {
        return tree[v] + adds[v];
    }

    inline void push(int v)
    {
        adds[2 * v] += adds[v];
        adds[2 * v + 1] += adds[v];
        adds[v] = 0;
    }

    inline int mergeVal(int val1, int val2)
    {
        return min(val1, val2);
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
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));
    }

    SegmentTreeMin(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    void Build(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    int query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 1400000000;
		if (tl >= l && tr <= r)
            return getValue(v);

        int tm = (tl + tr) / 2;

        push(v);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));

        return mergeVal(query(v * 2, tl, tm, l, std::min(r, tm)),
                        query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    inline int Query(int l, int r)
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
			return;
		}

		int tm = (tl + tr) / 2;

		push(v);

        update (v * 2, tl, tm, l, std::min(r, tm), diff);
        update (v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, diff);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));
    }

    inline void Update(int l, int r, int diff)
    {
        update(1, 0, sz - 1, l, r, diff);
    }
};


vector<long long> data;

long long a, b, k, n, m, tmp;


int GetId(int minvl)
{
    int l = -1;
    int r = n;

    while(r - l > 1)
    {
        int mid = (l+r)/2;
        if (::data[mid] >= minvl)
            r = mid;
        else
            l = mid;
    }

    return r;
}



int solve()
{
    cin >> n >> m;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    sort(all(::data));

    vi bs (n+1);
    for (int i = 0; i < n+1; ++i)
        bs[i] = n-i;

    SegmentTreeMin tree(bs);


    vvi childr(m);
    vl chsum(m, 0);

    for (int i = 0; i < m; ++i)
    {
        int sz, vl;
        cin >> sz;
        childr[i].resize(sz);

        for (int j = 0; j < sz; ++j)
        {
            cin >> vl;
            chsum[i] += vl;
            childr[i][j] = vl;
        }

        int id = GetId((chsum[i] + childr[i].size() - 1ll) / childr[i].size());
        tree.Update(0, id, -1);
    }

    string ans;

    for (int i = 0; i < m; ++i)
    {
        int baseID = GetId((chsum[i] + childr[i].size() - 1) / childr[i].size());
        tree.Update(0, baseID, 1);

        int sz = childr[i].size();
        for (int j = 0; j < sz; ++j)
        {
            int newID = GetId((chsum[i] - childr[i][j] + sz - 2) / (sz-1));

            tree.Update(0, newID, -1);

            if (tree.Query(0, n) >= 0)
                ans.pb('1');
            else
                ans.pb('0');

            tree.Update(0, newID, 1);

        }


        tree.Update(0, baseID, -1);
    }



    cout << ans << endl;

    return 0;
}

/*


1
2 2
2 2
3
2 1 3
2
1 4

*/


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}