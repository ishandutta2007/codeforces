#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define N 200010
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int n, x;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
    int T;
    T = read();
    while(T --)
    {
        x = read();
        bool flag = 0;
        for (int j = 0; j * 3 <= x; j ++)
        {
            int rest = x - j * 3;
            if (rest % 7 == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag) puts("YES");
        else puts("NO");
    }
    return 0;
}