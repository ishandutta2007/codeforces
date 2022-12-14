#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

             #include<vector>

#include<vector>

struct SegmentTreeMin
{
    int sz;
    std::vector<long long> tree;
    std::vector<int> tempr;


    SegmentTreeMin() {}

    SegmentTreeMin(int _sz)
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
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }

    SegmentTreeMin(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    long long query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 1e8;
		if (tl >= l && tr <= r)
            return tree[v];

        int tm = (tl + tr) / 2;

        return min(query(v * 2, tl, tm, l, std::min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
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
			tree[v] = val;
			return;
		}

		int tm = (tl + tr) / 2;
        update (v * 2, tl, tm, id, val);
        update (v * 2 + 1, tm + 1, tr, id, val);
        tree[v] = min(tree[2 * v], tree[2 * v + 1]);
    }

    inline void Update(int id, int val)
    {
        update(1, 0, sz - 1, id, val);
    }
};

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


long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    vi data(n);

    for (int i = 0; i < n; ++i)
        cin >> data[i];


    vi minst(n, 0);
    vi maxst(n, 0);


    set<pii> minvs;
    set<pii> maxvs;

    for (int i = n-1; i >= 0; --i)
    {
        while(!minvs.empty())
        {
            auto it = minvs.begin();
            if (-it->ft > data[i])
            {
                minst[it->sd] = i+1;
                minvs.erase(it);
            }
            else
                break;
        }

        while(!maxvs.empty())
        {
            auto it = maxvs.begin();
            if (it->ft < data[i])
            {
                maxst[it->sd] = i+1;
                maxvs.erase(it);
            }
            else
                break;
        }

        minvs.insert({-data[i], i});
        maxvs.insert({data[i], i});
    }


    /*for (int i = 0; i < n; ++i)
    {
        log(minst[i]);
        log(maxst[i]);
    }*/


    vi dp(n, 0);

    SegmentTreeMin mins(n);
    SegmentTreeMin maxs(n);

    set<pii> minvals;
    set<pii> maxvals;
    minvals.insert({-data[0], 0});
    maxvals.insert({data[0], 0});


    for (int i = 1; i < n; ++i)
    {
        while(!minvals.empty())
        {
            auto it = minvals.begin();
            if (-it->ft > data[i])
            {
                mins.Update(it->sd, n);
                minvals.erase(it);
            }
            else
                break;
        }

        while(!maxvals.empty())
        {
            auto it = maxvals.begin();
            if (it->ft < data[i])
            {
                maxs.Update(it->sd, n);
                maxvals.erase(it);
            }
            else
                break;
        }

        int mx = maxs.Query(minst[i], i-1);
        int mn = mins.Query(maxst[i], i-1);
        dp[i] = min(mx, mn)+1;

        minvals.insert({-data[i], i});
        maxvals.insert({data[i], i});

        maxs.Update(i, dp[i]);
        mins.Update(i, dp[i]);
    }


    cout << dp[n-1] << endl;

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