#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
using namespace std;
const int INF = 1e9;
const int N = 160;
int n, K, s, ans;
int a[N], f[N][N * N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	int i, j, k;
	n = read();
	K = read();
	s = read();
    rep(i, 1, n)
        a[i] = read();
    memset(f,0x3f,sizeof(f));
    f[0][0] = 0;
    rep(k, 1, n)
        for(int i = k - 1; i >= 0; i --)
        	rep(j, 0, k * i)
                if(f[i][j] != 0x3f3f3f3f)
                    f[i + 1][j + k - (i + 1)] = min(f[i + 1][j + k - (i + 1)], f[i][j] + a[k]);
    ans = INF;
    for(int j = 0; j <= min(s, (n * (n))); j ++)
        ans = min(ans, f[K][j]);
    printf("%d\n",ans);
    return 0;
}