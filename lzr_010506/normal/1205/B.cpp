#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
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
#define All(x) (x).begin(), (x).end()
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
int dis[1010][1010], mp[1010][1010];
ll a[1000010];
int cnt[10010];
vector<ll> b;

int main()
{
	int n = read();
	b.push_back(0);
	rep(i, 1, n)
	{
		a[i] = read1();
		rep0(j, 63)
			if((a[i] >> j) & 1)
				cnt[j] ++;
		if(a[i]) b.pb(a[i]);
	}
	rep0(i, 63)
		if (cnt[i] >= 3)
		{
			cout << 3;
			return 0;
		}
	n = sz(b) - 1; 
	rep(i, 1, n)
		rep(j, 1, n)
			mp[i][j] = dis[i][j] = INF;

	rep(i, 1, n)
		rep(j, i + 1, n)
			if (b[i] & b[j]) mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = 1;

	int MinCost = INF;
	rep(k, 1, n)
	{
		rep(i, 1, k - 1)
			rep(j, i + 1, k - 1)
				if (dis[i][j] != INF && mp[i][k] != INF && mp[k][j] != INF)
					MinCost = min(MinCost, dis[i][j] + mp[i][k] + mp[k][j]);
		rep(i, 1, n)
			rep(j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	}
	if (MinCost <= n) cout << MinCost;
	else puts("-1");
	return 0;
}