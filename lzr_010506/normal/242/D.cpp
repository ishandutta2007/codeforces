#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls x << 1
#define rs x << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
int a[N], ans[N];
int n, m, x, y, cnt;
vi g[N];
int main()
{
    n = read();
    m = read();
    set<pii> t;
    set<pii>::iterator v;
    rep(i, 1, m)
    {
    	x = read();
    	y = read();
        g[x].pb(y);
        g[y].pb(x);
    }
    rep(i, 1, n)
    {
        a[i] = read();
        t.insert(mp(a[i], i));
    }
    while (!t.empty())
    {
        v = t.begin();
        pii tt = *v;
        if (tt.X != 0) break;
        else
        {
            int x = tt.Y;
            ans[++ cnt] = x;
            for (int i = 0; i < g[x].size(); i ++)
	            if (a[g[x][i]] >= 0)
	            {
	                t.erase(mp(a[g[x][i]], g[x][i]));
	                if (a[g[x][i]]) t.insert(mp(a[g[x][i]] - 1, g[x][i]));
	                a[g[x][i]] --;
	            }
            t.erase(mp(a[x], x));
            a[x] --;
        }
    }
    cout << cnt << endl;
    rep(i, 1, cnt) cout << ans[i] << " ";
 	return 0;
 }