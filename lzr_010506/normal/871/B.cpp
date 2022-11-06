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
const int mod = 1e9 + 7;
int a[200010][3], p[10010], c[10010], b[10010], ans;
bool flag[10010];
int main()
{
	int n;
	cin >> n;
	rep(i, 0, n - 1)
	{
		printf("? %d %d\n", i, (i + 1) % n);
		fflush(stdout);
		a[i][0] = read();
		printf("? %d %d\n", (i + 1) % n, (i + 1) % n);
		fflush(stdout);
		a[i][1] = read();
	}
	rep(i, 0, n - 1)
	{
		p[0] = i;
		rep(j, 1, n - 1)
			p[j] = (p[j - 1] ^ a[j - 1][0] ^ a[j - 1][1]);
		memset(flag, 0, sizeof(flag));
		bool pp = 1;
		rep(j, 0, n - 1)
			if(flag[p[j]] == 1) {pp = 0; break;}
			else flag[p[j]] = 1;
		if(!pp) continue;
		rep(j, 0, n - 1)
			b[p[j]] = j;
		
		rep(j, 0, n - 1)
		{
		    int k;
		    if(j == n - 1) k = 0;
		    else k = j + 1;
		    if(((p[j] ^ b[k]) != a[j][0]) || ((p[k] ^ b[k]) != a[j][1]))
				{pp = 0; break;}
		}
		if(!pp) continue;
		ans ++;
		if(ans == 1) memcpy(c, p, sizeof(c));
	}
	printf("!\n");
	fflush(stdout);
	printf("%d\n", ans);
	fflush(stdout);
	if(ans == 0) return 0;
	rep(i, 0, n - 1)
	{
		printf("%d ", c[i]);
		fflush(stdout);
	}
	return 0;
}