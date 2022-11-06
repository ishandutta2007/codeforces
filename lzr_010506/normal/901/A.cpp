#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int h;
const int N = 200010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[N];
int F1[2 * N], F2[2 * N];

int main()
{
    h = read();
    rep(i, 0, h) a[i] = read();

   	bool flag = 0;
    int sum = 1;
    F1[1] = F2[1] = 0;
    rep(i, 1, h)
    {
        if (a[i - 1] > 1 && a[i] > 1)
        {
            flag = 1;
            rep(j, 1, a[i])
            {
                F1[sum + j] = sum;
                if (j < a[i]) F2[sum + j] = sum;
            }
            F2[sum + a[i]] = sum - 1;
        }
        else rep(j, 1, a[i]) F1[sum + j] = F2[sum + j] = sum;

        sum += a[i];
    }
    if (flag)
    {
        puts("ambiguous");
        rep(i, 1, sum) printf("%d ", F1[i]);
        puts("");
        rep(i, 1, sum) printf("%d ", F2[i]);
        puts("");
    }
    else puts("perfect\n");
    return 0;
}