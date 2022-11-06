#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
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
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).cntd()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;

const int N = 500111;
vector<int> G[N];
int n, m, p[N], ans[N];

bool cmp(int x,int y)
{
	return p[x] < p[y];
}

int main()
{
	n = read();
	m = read();
	rep(i, 1, m)
	{
		int u = read();
		int v = read();
		G[u].pb(v);
		G[v].pb(u);
	}
	rep(i, 1, n) p[i] = read();

	bool flag = 1;
	rep(i, 1, n)
	{
		set<int> st;
		for(auto to : G[i]) st.insert(p[to]);
		rep(j, 1, p[i] - 1) if(st.find(j) == st.end()) flag = 0;
		if(st.find(p[i]) != st.end()) flag = 0;
	}
	if(flag)
	{
		rep(i, 1, n) ans[i] = i;
		sort(ans + 1, ans + n + 1, cmp);
		rep(i, 1, n) printf("%d ",ans[i]);
	}
	else puts("-1");
	return 0;
}