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
const int N = 200010;
const int mod = 1e9 + 7;
vector<pii>E[N];
vector<pair<long long,int> >dis;
long long a[N] ,Dep[N];
int ans[N], n;

void dfs(int x)
{
    ans[x] ++;
    int p=lower_bound(ALL(dis), mp(Dep[x] - a[x], -1)) - dis.begin() - 1;
    if(p >= 0) ans[dis[p].Y] --;
    dis.pb(mp(Dep[x], x));
    for(auto& v : E[x])
    {
        Dep[v.X] = Dep[x] + v.Y;
        dfs(v.X);
        ans[x] += ans[v.X];
    }
    dis.pop_back();
}
int main()
{
	n = read();
	rep(i, 1, n)
		a[i] = read();
	rep(i, 2, n)
    {
        int p, w;
        p = read();
        w = read();
        E[p].pb(mp(i, w));
    }
    dfs(1);
    rep(i, 1, n)
        cout << ans[i] - 1 << " ";
    return 0;
}