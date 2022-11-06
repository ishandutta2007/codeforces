#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
int t, cnt, ans[200010], a[200010];
bool vis[1000005];
set<int> st;
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		rep(i, 1, n) a[i] = read();
		memset(vis, 1, sizeof vis);
		st.clear();

		rep(i, 1, n)
			rep(j, i + 1, n)
				st.insert(abs(a[i] - a[j]));
		if (st.count(0)) st.erase(st.find(0));

		cnt = 0;
		rep(i, 1, 1000000)
			if (vis[i])
			{
				ans[++ cnt] = i;
				if (cnt == n) break;
				for (int j : st) vis[i + j] = 0;
			}
		if (cnt == n)
		{
			puts("YES");
			rep(i, 1, n) printf("%d ", ans[i]);
			puts("");
		}
		else puts("NO");
	}
	return 0;
}