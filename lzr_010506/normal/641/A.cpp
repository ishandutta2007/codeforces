#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 10;
int n, a[N], vis[N];
char s[N];
int main()
{
	n = read();
	scanf("%s", s + 1);
	rep(i, 1, n) a[i] = read();
	memset(vis, 0, sizeof(vis));
	int pos = 1;
	bool flag;
	while(1)
	{
	    vis[pos] = 1;
	    if(s[pos] == '<') pos -= a[pos];
	    else pos += a[pos];
	    if(pos < 1 || pos > n) { flag = 1; break; }
	    if(vis[pos]) { flag = 0; break; }
	}
	puts(flag ? "FINITE" : "INFINITE");
	return 0;
}