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

int n = 0;
const int N = 100010;
int sum[N], low[4 * N];

int ans = 0;
char str[N];

int main() 
{
    memset(low, 0x3f, sizeof(low));
    scanf("%d", &n);
    scanf("%s", str+1);
    rep(i, 1, n) sum[i] = sum[i - 1] + (str[i] == '1');
    rep(i, 1, n)
    {
        low[i - 2 * sum[i - 1] + 2 * N] = min(low[i - 2 * sum[i - 1] + 2 * N], i);
        ans = max(ans, i - low[i - 2 * sum[i] + 1 + 2 * N] + 1);
    }
    printf("%d\n", ans);
    return 0;
}