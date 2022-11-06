#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
const int N = 1e6 + 10;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, fa[N], dp[N], mx[N], mx2[N];
ll ans;
int main()
{
	n = read();
	rep(i, 2, n + 1)
	{
		fa[i] = read();
		dp[i] = 1;
		int t = i;
		while(t != 1)
		{
			if(dp[t] > mx2[fa[t]]) mx2[fa[t]] = dp[t];
			if(mx2[fa[t]] > mx[fa[t]]) swap(mx[fa[t]], mx2[fa[t]]);
			t = fa[t];
			if(max(mx[t], mx2[t] + 1) == dp[t]) break;
			else dp[t] = max(mx[t], mx2[t] + 1);
		}
        cout << mx[1] << " ";
	}
	return 0;
}