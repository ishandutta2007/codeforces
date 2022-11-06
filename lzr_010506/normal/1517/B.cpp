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
vector<pii> num;

bool ud[110][110];
int T, n, m, nw[110], ans[110][110];

int main() 
{
	int T = read();
	while(T --)
	{
		num.clear();
		n = read();
		m = read();
		rep(i, 1, n)
			rep(j, 1, m)
			{
				int t = read();
				nw[i] = 1; 
				ud[i][j] = 0; 
				num.pb((mp)(t, i));
			}


		int tot = num.size();
		sort(num.begin(), num.end());
		rep0(i, m)
		{
			pii *p = &num[i];
			ans[p -> second][i + 1] = p -> first; 
			ud[p -> second][i + 1] = 1;
		}
		rep(i, m, tot - 1)
		{
			pii *p = &num[i];
			for (; ud[p -> second][nw[p -> second]]; ++ nw[p-> second]);
			ans[p-> second][nw[p -> second]] = p -> first; ud[ p-> second][nw[p -> second]] = 1;
		}
		rep(i, 1, n)
		{
			rep(j, 1, m)
				printf("%d ", ans[i][j]);
			puts("");
		}
	}

	return 0;
}