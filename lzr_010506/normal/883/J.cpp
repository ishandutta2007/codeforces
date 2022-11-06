#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 300005;
const int M = 300005;

int n,m,ans,tp;
int s[N];
ll tot;
ll a[N],b[N],p[N];
vector<ll> c[N];

int main()
{
    n = read();
    m = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, m) b[i] = read();
    rep(i, 1, m) p[i] = read();
    rep(i, 1, n)
    {
        while (tp && a[i] >= a[s[tp]]) -- tp;
        s[++ tp] = i;
    }
    rep(i, 1, m)
    {
        if (b[i] > a[s[1]]) continue;
        int l = 1, r = tp, pos = 0;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (a[s[mid]] >= b[i]) pos = mid, l = mid + 1;
            else r = mid - 1;
        }
        c[s[pos]].pb(p[i]);
    }

	priority_queue<ll> Q;
    rep(i, 1, n)
    {
    	int x = c[i].size();
        sort(c[i].begin(), c[i].begin() + x);
        tot += a[i];
        rep(j, 0, x - 1)
            if (c[i][j] <= tot)
            {
                tot -= c[i][j];
                Q.push(c[i][j]);
                ans ++;
            }
            else
            {
                if (Q.empty())continue;
                ll tmp = Q.top();
                if (tmp > c[i][j])
                {
                    Q.pop();
                    Q.push(c[i][j]);
                    tot += tmp - c[i][j];
                }
            }
    }
    printf("%d\n",ans);
    return 0;
}