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


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

#include<vector>

struct SegmentTreeMax
{
    int sz;
    std::vector<long long> tree;
    std::vector<int> tempr;


    SegmentTreeMax() {}

    SegmentTreeMax(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, -1000000000);
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
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    SegmentTreeMax(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, -1000000000);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return -100000000000;
		if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;

        return max(query(v * 2, tl, tm, l, std::min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    inline long long Query(int l, int r)
    {
        return query(1, 0, sz - 1, l, r);
    }

    void update(int v, int tl, int tr, int id, long long val)
    {
        if (tr < id) return;
        if (id < tl) return;
		if (tl == id && tr == id)
        {
			tree[v] = val;
			return;
		}

		int tm = (tl + tr) / 2;
        update (v * 2, tl, tm, id, val);
        update (v * 2 + 1, tm + 1, tr, id, val);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    inline void Update(int id, long long val)
    {
        update(1, 0, sz - 1, id, val);
    }
};



int solve()
{
    ans = 0;
    cin >> n;

    ::data.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> ::data[i];

    vl sums(n+1, 0);
    for (int i = 0; i < n; ++i)
    {
        sums[i+1] = sums[i] + ::data[i];
    }
    //log("y");

    vpll sumo(n+1);
    for (int i = 0; i < sumo.size(); ++i)
    {
        sumo[i] = {sums[i], i};
    }
    sort(all(sumo));

    vi order(n+1);
    for (int i = 0; i < order.size(); ++i)
    {
        order[sumo[i].sd] = i;
    }

    /*for (int i = 0; i < order.size(); ++i)
    {
        log(i);
        log(order[i]);
    }*/

    SegmentTreeMax tree(n+1);
    tree.Update(order[0], 0);

    vl sumsmx = sums;
    for (int i = n-1; i >= 0; --i)
    {
        sumsmx[i] = max(sumsmx[i], sumsmx[i+1]);
    }
    //log("x");

    vi ends(n, n-1);

    vvi starts(n);
    for (int i = 0; i < n; ++i)
    {
        int l = i;
        int r = n;

        while(r-l > 1)
        {
            int mid = (l+r)/2;
            if (sumsmx[mid+1] > sums[i])
                l = mid;
            else
                r = mid;
        }

        ends[i] = l;
        //log(i);
        //log(ends[i]);
        if (sums[l+1]-sums[i] > 0)
            starts[l].pb(i);
    }

    vl dp(n+1, 0);

    for (int i = 1; i <= n; ++i)
    {
        //log(i);
        if (::data[i-1] < 0)
            dp[i] = dp[i-1]-1;
        if (::data[i-1] > 0)
            dp[i] = dp[i-1]+1;
        if (::data[i-1] == 0)
            dp[i] = dp[i-1];

        ll reqsum = sums[i] - 1;

        int l = -1;
        int r = n;
        while(r-l > 1)
        {
            int mid = (l+r)/2;
            if (sumo[mid].ft <= reqsum)
                l = mid;
            else
                r = mid;
        }
        ll resp = tree.Query(0, l);
        //log(l);
        //log(resp);
        resp += i;
        dp[i] = max(dp[i], resp);
        //log(dp[i]);

        tree.Update(order[i], dp[i]-i);
    }




    cout << dp[n] << endl;

    return 0;
}

/*


3
8
-1 -1 -4 7 -3 -3 -3 -3
5
1 -5 5 -1 -1
3
0 0 0



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