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
#define ALL(x) (x).begin(), (x).end()
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
const int N = 510;
char ch[N][N];
int a[N][N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		rep(i, 1, n)
			scanf("%s", ch[i] + 1);
		rep(i, 1, n)
			rep(j, 1, m)
				a[i][j] = 0;
		rep(i, 1, n)
			rep(j, 1, m)
				a[i][j] = a[i][j - 1] + (ch[i][j] == '*');
		int ans = 0;
		rep(i, 1, n)
			rep(j, 1, m)
				if(ch[i][j] == '*')
				{
					ans ++;
					rep(k, i + 1, n)
					{
						if(j - k + i <= 0) break;
						if(j + k - i > m) break;
						if(a[k][j + (k - i)] - a[k][j - (k - i) - 1] != 2 * (k - i) + 1) break;
						ans ++;
					}
				}
		printf("%d\n", ans);
			
	}

	return 0;
}