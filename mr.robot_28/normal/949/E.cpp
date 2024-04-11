#include<bits/stdc++.h>
 
using namespace std;

const int N=1e5+5;
int n,a[N],d[N],b[21][N],a2[25],ans[N];
void dfs(int x)
{
	if(x > 20)
	{
		if(d[0] < ans[0])
		{
			for(int i = 0; i <= d[0]; i++)
			{
				ans[i] = d[i];
			}
		}
		return;
	}
	int pos = 0;
	for(int i = 1; i <= n; i++)
	{
		pos |= a[i] & a2[x];
	}
	if(!pos)
	{
		dfs(x + 1);
	}
	else
	{
		int n0 = n;
		for(int i = 1; i <= n0; i++)
		{
			b[x][i] = a[i];
		}
		d[++d[0]] = a2[x];
		for(int i = 1; i <= n0; i++)
		{
			if(b[x][i] & a2[x])
			{
				a[i] = b[x][i] - a2[x];
			}
			else
			{
				a[i] = b[x][i];
			}
		}
		sort(a + 1, a + n0 + 1);
		n = 0;
		for(int i = 1; i <= n0; i++)
		{
			if(i == 1 || a[i] != a[i - 1])
			{
				a[++n] = a[i];
			}
		}
		dfs(x + 1);
		d[d[0]] = -a2[x];
		n = 0;
		for(int i = 1; i <= n0; i++)
		{
			if(b[x][i] & a2[x])
			{
				a[i] = b[x][i] + a2[x];
			}
			else
			{
				a[i] = b[x][i];
			}
		}
		for(int i = 1; i <= n0; i++)
		{
			if(i == 1 || a[i] != a[i - 1])
			{
				a[++n] = a[i];
			}
		}
		dfs(x + 1);
		d[0]--;
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	a2[0] = 1;
	for(int i= 1; i <= 20; i++)
	{
		a2[i] = a2[i - 1] * 2;
	}
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	ans[0] = 30;
	dfs(0);
	cout << ans[0] << "\n";
	for(int i= 1; i <= ans[0]; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}