#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
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
const int N = 410;
char s[N][N];
int A[N][N], sum[N][N], a[N], b[N];
int main()
{
    int T = read();
    while(T --)
    {
        int n, m;
        int ans = 400 * 400;
        n = read();
        m = read();
        rep(i, 1, n)
            scanf("%s", s[i] + 1);
        rep(i, 1, n)
            rep(j, 1, m)
            {
                sum[i][j] = A[i][j] = s[i][j] - '0';
                sum[i][j] += sum[i - 1][j];
            }

        rep(i, 1, n)
            rep(j, i + 4, n)            
            {
                rep(k, 1, m)
                {
                    a[k] = j - i - 1 - (sum[j - 1][k] - sum[i][k]);
                    b[k] = (sum[j - 1][k] - sum[i][k]) + (1 - A[i][k]) + (1 - A[j][k]);
                    b[k] += b[k - 1];
                }
                int pre = 160000;
                rep(k, 4, m)
                {
                   // cout << k << endl;
                    pre = min(pre, a[k - 3] - b[k - 3]);
                    ans = min(ans, pre + b[k - 1] + a[k]);
                }
            }
        printf("%d\n", ans);
    }

    return 0;
}