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
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
char s[1010];
int a[1010], c[1010][1010];
int n, p;
int main() 
{
	scanf("%d%d", &n, &p);
	scanf("%s", s + 1);
	rep(i, 1, n) a[i] = s[i] - 'a';
	a[0] = -1;
	memset(c, -1, sizeof(c));
	rep(i, 1, n)
	{
		rep(j, 1, i - 1) c[i][j] = a[j];
		rep(j, a[i] + 1, p - 1) 
			if(i == 1) { c[i][i] = j; break; }
			else if(j != a[i - 1] && j != a[i - 2]) { c[i][i] = j; break; }
		rep(j, i + 1, n)
			rep(k, 0, p - 1)
				if(k != c[i][j - 1] && k != c[i][j - 2]) 
				{
					c[i][j] = k;
					break;
				}
	}
	int flag = 1, temp = 0;
	rrep(i, n, 1)
	{
		flag = 0;
		temp = i;
		rep(j, 1, n)
			if(c[i][j] == -1) { flag = 1; break; }
		if(!flag) break;
	}
	if(!flag) 
		for(int i = 1 ; i <= n ; i++) 
			putchar(c[temp][i] + 'a');
	else puts("NO");
	
	return 0;
}