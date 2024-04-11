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
const int N = 1e6 + 10;

int a[1005][1005], cnt[1005][1005];
int tmp[1000000];
int num = 1;
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int x, int y) 
{
	cnt[x][y] = num;
	tmp[num] ++;
	rep0(i, 4)
		if (a[x + dx[i]][y + dy[i]] && !cnt[x + dx[i]][y + dy[i]])
			dfs(x + dx[i], y + dy[i]);
}
int main() 
{
	n = read();
	m = read();
	rep(i, 1, n)
		rep(j, 1, m)
		{
			char c;
			cin >> c;
			if (c == '.') a[i][j] = 1;
		}
	rep(i, 1, n)
		rep(j, 1, m)
			if (a[i][j] && !cnt[i][j])
			{
				dfs(i, j);
				num ++;
			}
	rep(i, 1, n)
	{
		rep(j, 1, m)
			if (!a[i][j]) 
			{
				vector<int> v;
				int ans = 1;
				for (int k = 0; k < 4; k++) 
					if (a[i + dx[k]][j + dy[k]])
					{
						int r = 0;
						for (r = 0; r < v.size(); r++) 
							if (cnt[i + dx[k]][j + dy[k]] == v[r]) 
								break;
						if (r < v.size());
						else 
						{
							v.pb(cnt[i + dx[k]][j + dy[k]]);
							ans += tmp[cnt[i + dx[k]][j + dy[k]]];
						}
					}
				cout << ans % 10;
			}
			else cout << '.';
		puts("");
	}
	return 0;
}