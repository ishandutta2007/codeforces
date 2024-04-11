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
const int N = 3e5 + 10;
int n;
int a[N], ans[N];
vector<int> v[N];

int main()
{
	int T = read();
	while (T --)
	{
		n = read();
		rep(i, 1, n) v[i].clear();
		rep(i, 1, n) a[i] = read(), v[a[i]].pb(i);
		rep(i, 1, n) ans[i] = 0;
		int l = 1, r = n;
		rep(i, 1, n) 
		{
			if (!v[i].size()) break;
			ans[n - i + 1] = 1;
			if (a[l] != i && a[r] != i) break;
			else if (a[l] == i) 
			{
				if (v[i].size() == 1) l ++;
				else break;
			}
			else if (a[r] == i) 
			{
				if (v[i].size() == 1) r --;
				else break;
			}
			else break;
		}
		bool fl = 1;
		rep(i, 1, n) if (v[i].size() != 1) fl = 0;
		ans[1] = fl;
		rep(i, 1, n) printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}