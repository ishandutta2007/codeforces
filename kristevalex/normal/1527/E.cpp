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


    SegmentTreeMin() {}

    SegmentTreeMin(int _sz)
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


long long a, b, k, n, m, tmp, ans = 0;

/*

8 1
1 2 3 1 2 1 3 2

8 2
1 2 3 1 2 1 3 2

8 3
1 2 3 1 2 1 3 2

8 4
1 2 3 1 2 1 3 2

8 5
1 2 3 1 2 1 3 2

8 6
1 2 3 1 2 1 3 2

8 7
1 2 3 1 2 1 3 2

8 8
1 2 3 1 2 1 3 2

*/



int solve()
{
    cin >> n >> k;
    --k;

    vi cnt(100000, -1);

    vpii gaps;

    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (cnt[x] != -1)
        {
            //log(x);
            gaps.pb({cnt[x]+2, i+2});
        }

        cnt[x] = i;
    }

    int curMax = 1;

    vector<SegmentTreeMin> dp(k+1, SegmentTreeMin(n+5));

    for (int id = 0; id < gaps.size(); ++id)
    {
        int st = gaps[id].ft;
        int en = gaps[id].sd;

        /*cendl;
        log(id);
        log(st);
        log(en);
        cendl;*/

        for (int i = curMax; i < en; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                int prevj = max(j-1, 0);
                int val = dp[prevj].Query(0, curMax-1);

                /*if (id == 1)
                {
                    log(j);
                    log(val);
                }*/

                if (j == 0 || i < st)
                {
                    val += en - st;
                }
                /*if (id == 1)
                {
                    log(j);
                    log(val);
                    log(i);
                    cendl;
                }*/

                dp[j].Update(i, i, val);
            }
        }

        int enFilled = min(curMax - 1, st - 1);
        dp[0].Update(0, curMax-1, en - st);
        for (int i = 1; i <= k; ++i)
            dp[i].Update(0, enFilled, en - st);

        curMax = en;

        /*for (int i = 0; i < curMax; ++i)
        {
            cout << dp[k].Query(i, i) << ' ';
        }
        cendl;*/
    }



    if (curMax > 0)
        --curMax;

    cout << dp[k].Query(0, curMax) << endl;

    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}