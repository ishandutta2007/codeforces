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

struct SegmentTreeMax
{
    int sz;
    std::vector<long long> tree;
    std::vector<int> tempr;


    SegmentTreeMax() {}

    SegmentTreeMax(int _sz)
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
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    SegmentTreeMax(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return LLONG_MIN;
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


long long a, b, k, n, m, tmp;
int ans = 0;

vpii data;

inline void updans(int x1, int y1, int x2, int y2)
{
    //if (i == j) return;

    ans = max(ans, abs(x1-y2) + abs(x2-y1) - abs(x1-y1) - abs(x2-y2));
}

inline void updans(int i, int j)
{
    //if (i == j) return;

    int x1 = ::data[i].ft;
    int y1 = -::data[i].sd;
    int x2 = ::data[j].ft;
    int y2 = -::data[j].sd;
    //log(x1);
    //log(y1);
    //log(x2);
    //log(y2);

    ans = max(ans, - abs(x1-y2) - abs(x2-y1) + abs(x1-y1) + abs(x2-y2));
}

int solve()
{
    cin >> n;

    ll tot = 0;

    ::data.resize(n);

    SegmentTreeMax tree(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i].ft;
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i].sd;

        tot += abs(::data[i].ft - ::data[i].sd);

        ::data[i].sd = -::data[i].sd;
    }

    vi maxonpref(n, 0);

    sort(all(::data));
    for (int i = 0; i < n; ++i)
    {
        if (i > 0)
            maxonpref[i] = maxonpref[i-1];

        int x = ::data[i].ft;
        int y = -::data[i].sd;

        if (x > y)
        {
            //log("get");
            //log(x);
            //log(y);
            if (i == 0) continue;
            int l = -1;
            int r = i;

            while(r-l > 1)
            {
                int mid = (l+r)/2;
                //log(i);
                //log(::data[mid].ft);
                //log(y);
                if (::data[mid].ft < y)
                    l = mid;
                else
                    r = mid;
            }
            //log(l);

            if (l != -1)
            {
                int ymax = maxonpref[l];

                ans = max(ans, (min(ymax, x)-y)*2);
            }
            int ll = r;
            int oldl = l;
            l = l;
            r = i;

            while(r-l > 1)
            {
                int mid = (l+r)/2;
                if (maxonpref[mid] < x)
                    l = mid;
                else
                    r = mid;
            }
            //log(l+0);
            //log(ll);
            //log(l);
            if (ll <= l)
            {
                int len = tree.Query(ll, l);
                ans = max(ans, len*2);
            }
            //if (r < i)
            //{
            //log(r);
            //log(i);
            updans(r, i);
            //}
        }
        else
        {
            //log("set");
            //log(x);
            //log(y);
            maxonpref[i] = max(maxonpref[i], y);
            tree.Update(i, y - x);
        }
        //log(ans);
    }


    //log(ans);

    cout << tot - ans << endl;

    return 0;
}


/*

3
5 10 4
9 4 6

*/

int main()
{
    FAST;

        solve();

    return 0;
}