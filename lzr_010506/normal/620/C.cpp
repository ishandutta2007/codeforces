#include <bits/stdc++.h>
#include <algorithm>
#include <set>
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
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
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
const int N = 3e6 + 10, MOD = 998244353;
set<int> s;
int cnt, ans[N];
int main()
{
	int n = read();
	ans[++ cnt] = 1;
	rep(i, 1, n)
	{
		int x = read();
		if(s.count(x))
		{
			ans[++ cnt] = i;
			ans[++ cnt] = i + 1;
			s.clear();
		}
		else s.insert(x);
	}
	if(cnt == 1) {puts("-1"); return 0;}
	cnt --;
	ans[cnt] = n;
	printf("%d\n", cnt / 2);
	rep(i, 1, cnt)
	{
		printf("%d", ans[i]);
		if(i % 2 == 1) printf(" ");
		else printf("\n");
	}
	
	return 0; 
}