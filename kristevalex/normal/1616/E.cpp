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


#include<vector>

struct SegmentTreeMax
{
    int sz;
    std::vector<std::pair<int, int>> tree;
    std::vector<int> adds;
    std::vector<int> tempr;


    SegmentTreeMax() {}

    SegmentTreeMax(int _sz)
    {
        sz = _sz;
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
    }

    inline std::pair<int, int> getValue(int v)
    {
        std::pair<int, int> ret = tree[v];
        ret.first += adds[v];
        return ret;
    }

    void push(int v)
    {
        adds[2 * v] += adds[v];
        adds[2 * v + 1] += adds[v];
        adds[v] = 0;
    }

    inline std::pair<int, int> mergeVal(std::pair<int, int> val1, std::pair<int, int> val2)
    {
        return max(val1, val2);
    }

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            tree[v] = {tempr[tl], tl};
            return;
        }

        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));
    }

    SegmentTreeMax(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    void Build(const std::vector<int>& dt)
    {
        sz = dt.size();
        tree.assign(4 * sz, {0, 0});
        adds.assign(4 * sz, 0);
        tempr = dt;
        build(1, 0, sz - 1);
    }

    std::pair<int, int> query(int v, int tl, int tr, int l, int r)
    {

        //cout << "query: " << v << " " << tl << " " << tr << " " << l << " " << r << endl;
        if (l > r)
            return {-1400000000, -1};
		if (tl >= l && tr <= r)
            return getValue(v);

        int tm = (tl + tr) / 2;

        push(v);
        tree[v] = mergeVal(getValue(2 * v), getValue(2 * v + 1));

        return mergeVal(query(v * 2, tl, tm, l, std::min(r, tm)),
                        query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
    }

    inline std::pair<int, int> Query(int l, int r)
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

long long a, b, k, n, m, tmp, ans = 0;
const ll inf = 1000000000000;



int solve()
{
    cin >> n;

    string s;
    string t;
    cin >> s >> t;
    ans = inf;

    SegmentTreeMax correction(n);


    vector<set<int>> sts(30);

    ll cur_sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sts[s[i]-'a'].insert(i);
    }

    //cout <<"h1" <<endl;

    for (int i = 0; i < n; ++i)
    {


        if (cur_sum >= ans)
            break;

        int cr = t[i] - 'a';

        for (int lw = 0; lw < cr; ++lw)
        {
            if (!sts[lw].empty())
            {
                int pos = *(sts[lw].begin());

                int len = pos - correction.Query(pos, pos).ft;

                ans = min(ans, cur_sum + len);
            }
        }

        if (sts[cr].empty())
            break;
        else
        {
            int pos = *(sts[cr].begin());
    //cout <<"h " << i << " csum: " << cur_sum <<endl;

    //cout << "pos: " << pos << endl;

            int q = correction.Query(pos, pos).ft;
    //cout <<"h " << i << " csum: " << cur_sum <<endl;

            int len = pos - q;
            cur_sum += len;


    //cout <<"h " << i << " csum: " << cur_sum <<endl;
            correction.Update(pos, n-1, 1);


            sts[cr].erase(pos);
        }
    }


    if (ans != inf)
        cout << ans << endl;
    else
        cout << -1 << endl;

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