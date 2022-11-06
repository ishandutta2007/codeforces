#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> a[100010];
int n,s[100010], sg[100010];
map<int, int>f;

inline void dfs(int x)
{
	for(int i = 0; i < a[x].size(); i ++)
	{
		int now = a[x][i];
		sg[now] = sg[x] + 1;
		dfs(now);
	}
}
inline bool fz(int &a, int b)
{
	return a < b ? a = b, 1 : 0;
}
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		s[i] = read();
	for(int i = 2; i <= n; i ++)
	{
		int x;
		x = read();
		a[x].push_back(i);
	}
	dfs(1);
	int now = 0;
	for(int i = 1; i <= n; i ++)
		fz(now, sg[i]);
	for(int i = 1; i <= n; i ++)
		sg[i] = (sg[i] ^ now) & 1;
	int sum = 0, cnt = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i ++)
		if(!sg[i])
			sum ^= s[i], cnt ++;
	if(!sum)
		ans = (ll)cnt * (cnt - 1) / 2 + (ll)(n - cnt) * (n - cnt - 1) / 2;
	for(int i = 1; i <= n; i ++)
		if(!sg[i])
			f[sum ^ s[i]] ++;
	for(int i = 1; i <= n; i ++)
		if(sg[i])
			ans += f[s[i]];
	cout << ans;
	return 0;
}