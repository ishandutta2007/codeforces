#include <bits/stdc++.h>
using namespace std;
#define N 100100
double ans[N];
int n;
double a, d;

int main()
{
    scanf("%d%lf%lf", &n, &a, &d);
	double tmp = sqrt(d * 2 / a);
	for(int i = 1; i <= n; i ++)
	{
		double x, y;
		scanf("%lf%lf", &x, &y);
		double cur = y * y / a / 2;
		if (cur >= d) ans[i] = x + tmp;
		else ans[i] = x + y / a + (d - cur) / y;
	}
	for(int i = 1; i <= n; i ++)
	{
		ans[i] = max(ans[i], ans[i - 1]);
		printf("%.6lf\n",ans[i]);
	}
	return 0;
}