#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
long long a, b, n;
int main()
{
	cin >> n >> a >> b;
	rep(x, 0, n)
	{
	    if(a * x > n) break;
		if((n - a * x) % b == 0)
		{
			puts("YES");
			printf("%d ", x);
			printf("%d\n", (n - a * x) / b);
			return 0;
		}
	}
	puts("NO");
	return 0;
}