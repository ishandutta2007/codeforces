#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
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
int a[N], cnt;
vi ans;
int vis[N];
bool flag = 1;
int main()
{
	int T = read();
	while(T --)
	{
	    ans.clear();
		int n = read();
		rep(i, 1, n) a[i] = 0, vis[i] = 0;
		bool xx = 0;
		rep(i, 1, n)
		{
			int x = read();
			a[i] = i - x;
			if(x == 0)
			{
				if(xx != 1) printf("1\n%d\n", i);
				xx = 1;
			}
		}
		if(xx) continue;
		rep(i, 1, n)
			if(!vis[i])
			{
				int nw = i;
				while(!vis[nw])
				{
					vis[nw] = i;
					nw = a[nw];
				}
				if(vis[nw] == i)
				{
					//printf("%d\n", cnt + 1);
					int p = a[nw]; ans.pb(nw);
					while(p != nw)
					{
						ans.pb(p);
						p = a[p];
					} 
					printf("%d\n", ans.size());
					for(auto x : ans) printf("%d ", x);
					puts("");
					break;
				}
				
			}
	}
 
	return 0;
}