#include <bits/stdc++.h>
using namespace std;
char f[505][505];
int a[505][505], as[505000], hv[500000];
int aN, tots, n, k;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

inline int max(int a, int b)
{
	if(a < b) return b;
	return a;
}

void dfs(int i, int j)
{
	for(int k = 0; k < 4; k ++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if(x < 0 || y < 0 || x >= n || y >= n || f[x][y] == 'X' || a[x][y]) continue;
		as[a[i][j]] ++;
		a[x][y] = a[i][j];
		dfs(x, y);
	}
}

void asq(int x, int y)
{
	if(f[x][y] == 'X') return;
	int r = a[x][y];
	if(!hv[r]) tots += as[r];
	hv[r] ++;
}

void rsq(int x, int y)
{
	if(f[x][y] == 'X') return;
	int r = a[x][y];
	hv[r] --;
	if(!hv[r]) tots -= as[r];
}

int main()
{
	cin >> n >> k;
	for(int i = 0; i < n; i ++)
		scanf("%s", f[i]);
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < n; j ++)
		{
			if(f[i][j] == 'X' || a[i][j]) continue;
			a[i][j] = ++ aN;
			as[a[i][j]] ++;
			dfs(i,j);
		}
	int ans = 0;
	for(int X = 0; X < n - k + 1; X ++)
	{
		for(int j = 0; j <= aN; j ++)
			hv[j] = 0;
		tots = 0;
		for(int x = X; x < X + k; x ++)
			for(int y = 0; y < k; y ++)
				asq(x, y);
		if(X + k < n)
			for(int y = 0; y < k; y ++)
				asq(X + k, y);
		if(X - 1 >= 0)
		for(int y = 0; y < k; y ++)
			asq(X - 1, y);
		if(k < n)
			for(int x = X; x < X + k; x ++)
				asq(x, k);
		
		for(int x = X; x < X + k; x ++)
			for(int y = 0; y < k; y ++)
				if(f[x][y] == 'X')
					tots ++;
		
		ans = max(ans, tots);
		for(int Y = 1; Y <= n - k; Y ++)
		{
			if(Y > 1)
				for(int x = X; x < X + k; x ++) 
					rsq(x, Y - 2);
			
			for(int x = X; x < X + k; x ++)
			{
				if(f[x][Y - 1] == 'X') -- tots;
				if(f[x][Y + k - 1] == 'X') ++ tots;
			}
			if(Y + k < n)
				for(int x = X; x < X + k; x ++)
					asq(x, Y + k);
			if(X) asq(X - 1, Y + k - 1), rsq(X - 1, Y - 1);
			
			if(X + k < n) asq(X + k, Y + k - 1), rsq(X + k, Y - 1);
			ans = max(ans, tots);
		}
	}
	cout << ans;
	return 0;
}