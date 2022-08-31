#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

const int MOD = 998244353;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int LOG = 20;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);

struct Tree
{
    int mn[SZ];

    Tree() : mn() {}

    void setVal(int pos, int x)
    {
        pos += LEVEL;
        mn[pos] = x;
        while (pos > 1)
        {
            pos /= 2;
            mn[pos] = min(mn[2 * pos], mn[2 * pos + 1]);
        }
    }

    int getMin(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l)
            return SZ;
        if (l <= tl && tr <= r)
        {
            return mn[v];
        }
        int tm = (tl + tr) / 2;
        return min(
                getMin(2 * v, tl, tm, l, r),
                getMin(2 * v + 1, tm + 1, tr, l, r));
    }

    int getMin(int l, int r)
    {
        return getMin(1, 0, LEVEL - 1, l, r);
    }
} tree;

const int N = 2005;
const int M = (int) 1e6 + 100;
int a[M];
int fst[N], lst[N];

int dp[N][N];

vector <pair <int, int>> inner[N]; // segment
vector <pair <int, int>> ff, ll;
int ffpos[N], llpos[N];

/*    
for (int i = 0; i <= n; i++)
    {
        mn[i] = i;
        dp[i][i] = 1;
        dp[i][i + 1] = 1;
    }

    for (int len = 2; len <= n; len++)
        for (int l = 0; l + len <= n; l++)
        {
            int r = l + len;
            if (a[r - 1] < a[mn[l]])
                mn[l] = r - 1;
            int suml = 0, sumr = 0;
            int mid = mn[l];
            for (int j = l; j <= mid; j++)
                sadd(suml, mul(dp[l][j], dp[j][mid]));
            for (int j = mid + 1; j <= r; j++)
                sadd(sumr, mul(dp[mid + 1][j], dp[j][r]));
            dp[l][r] = mul(suml, sumr);
            //eprintf("%d %d : %d = %d * %d\n", l, r, dp[l][r], suml, sumr);
        }
    printf("%d\n", dp[0][n]);
*/

int solve(int l, int r) // segment
{
    //eprintf("l = %d, r = %d\n", l, r);
    if (l > r) return 1;
    if (fst[a[l]] != l || lst[a[r]] != r) return 0;
    if (dp[a[l]][a[r]] != -1) return dp[a[l]][a[r]];
    //dp[l][r] = 0; // TODO
    
    int mn = tree.getMin(l, r);
    if (fst[mn] < l || lst[mn] > r)
        return dp[a[l]][a[r]] = 0;
    int dpInner = 1;
    
    for (auto p : inner[mn])
    {
        //eprintf("inner: ");
        dpInner = mul(dpInner, solve(p.first, p.second));
    }
    //eprintf("mn = %d\n", mn);

    int fp = ffpos[mn], lp = llpos[mn];
    int dpl = 0, dpr = 0;
    while (fp >= 0 && ff[fp].first >= l)
    {
        int pos = ff[fp].first;
        //eprintf("left %d %d\n", mn, fst[mn]);
        sadd(dpl, mul(solve(l, pos - 1), solve(pos, fst[mn] - 1)));
        fp--;
    }
    //eprintf("%d .. %d ; %d .. %d\n", lp, (int) ll.size(), ll[lp].first, r);
    while (lp < (int) ll.size() && ll[lp].first <= r)
    {
        int pos = ll[lp].first;
      //  eprintf("right %d %d\n", pos, r);
        sadd(dpr, mul(solve(lst[mn] + 1, pos), solve(pos + 1, r)));
        lp++;
    }

    int ans = mul(dpl, dpr);
    ans = mul(ans, dpInner);
    //eprintf("dp[%d][%d] = %d\n", l, r, ans);
    return dp[a[l]][a[r]] = ans;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    memset(dp, -1, sizeof dp);

    int n, m;
    scanf("%d%d", &n, &m);
    memset(fst, -1, sizeof fst);
    memset(lst, -1, sizeof lst);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a[i]);
        tree.setVal(i, a[i]);
        if (lst[a[i]] != -1 && lst[a[i]] + 1 != i)
            inner[a[i]].emplace_back(lst[a[i]] + 1, i - 1);
        if (fst[a[i]] == -1)
            fst[a[i]] = i;
        lst[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        ff.emplace_back(fst[i], i);
    for (int i = 1; i <= n; i++)
        ll.emplace_back(lst[i], i);
    sort(ff.begin(), ff.end());
    sort(ll.begin(), ll.end());
    for (int i = 0; i < n; i++)
    {
        ffpos[ff[i].second] = i;
        llpos[ll[i].second] = i;
    }

    int ans = solve(0, m - 1);
    printf("%d\n", ans);


    return 0;
}