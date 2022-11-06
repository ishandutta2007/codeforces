#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define N 100010
bool vis[N], vn[N];
int p[N];
int main()
{
	int n = read();
	int m = read();
	for(int i = 1; i <= m; i ++)
	{
		int k = read();
		bool flag = 0;
		for(int j = 1; j <= k; j ++) p[j] = read();
		for(int j = 1; j <= k; j ++)
			if(p[j] > 0)
			{
				if(vn[p[j]])
				{
					flag = 1;
					break;
				}
				else vis[p[j]] = 1;
			}
			else
			{
				if(vis[-p[j]])
				{
					flag = 1;
					break;
				}
				else vn[-p[j]] = 1;
			}

		for(int j = 1; j <= k; j ++)
			vn[abs(p[j])] = vis[abs(p[j])] = 0;
		if(!flag)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}