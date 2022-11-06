#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1z
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
const int N = 1e6 + 10;
vi ans;
int a[N], cnt[N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		ans.clear();
		rep0(i, n)
			a[i] = read();
		while(1) 
		{
	        bool flag = true;
	        rep(i, 1, n - 1) if (a[i - 1] > a[i]) {flag = false; break;}
	        if (flag) break;
	        rep0(i, n) cnt[a[i]] ++;
	        int mex = 0;
	        while (cnt[mex] > 0) mex ++;
	        rep0(i, n) cnt[a[i]] --;
	        if (mex >= n) 
			{
				rep0(i, n) if (a[i] != i) {a[i] = mex; mex = i; break; }
			}
	        else a[mex] = mex;
	        ans.pb(mex);
	    }
		printf("%d\n", sz(ans));
		for(auto x : ans) printf("%d ", x + 1);
		puts("");
	}

	return 0;
}