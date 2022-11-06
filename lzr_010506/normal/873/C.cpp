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
using namespace std;

const int N = 110;

int val[N][N];
int n, m, k;
int minr = 0, maxv = 0, rp = 0;

int main() 
{
	n = read();
	m = read();
	k = read();
	rep(i, 1, n)
		rep(j, 1, m)
			val[i][j] = read();
    int ans1 = 0, ans2 = 0;
    rep(i, 1, m)
    {
        minr = maxv = rp = 0;
        rep(j, 1, n)
        {
            int tmp = 0;
            for (int t = 1; t <= k && j + t - 1 <= n; t ++) 
                if (val[j + t - 1][i] == 1) 
                    tmp ++;
            if (tmp > maxv) 
            {
                maxv = tmp;
                minr = rp;
            }
            rp += (val[j][i] == 1);
        }
        ans1 += maxv;
        ans2 += minr;
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}