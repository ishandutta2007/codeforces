#include <cstdio>
#include <iostream>
#define MN 50100

double dp[MN];
double c[MN], d[MN];
int n;

void solve(double C, double D, int &a, int &b)
{
	a = b = 0;

	for(int i = 1; i <= n; i++)
	{
		int opt = 0;
		dp[i] = dp[i - 1];
		
		if(dp[i - 1] + c[i] - C >= dp[i])
		{
			dp[i] = dp[i - 1] + c[i] - C;
			opt = 1;
		}
		
		if(dp[i - 1] + d[i] - D >= dp[i])
		{
			dp[i] = dp[i - 1] + d[i] - D;
			opt = 2;
		}
		
		if(dp[i - 1] + c[i] + d[i] - c[i] * d[i] - C - D >= dp[i])
		{
			dp[i] = dp[i - 1] + c[i] + d[i] - c[i] * d[i] - C - D;
			opt = 3;
		}
		
		a += opt & 1;
		b += opt >> 1;
	}
}

int main()
{
	int a, b; scanf("%d%d%d", &n, &a, &b);
	
	for(int i = 1; i <= n; i++) scanf("%lf", &c[i]);
	for(int i = 1; i <= n; i++) scanf("%lf", &d[i]);
	
	double lc = 0, rc = 1;
	double ld = 0, rd = 1;
	int A = 0, B = 0;
	
	for(int i = 1; i <= 50; i++)
	{
		double mc = (lc + rc) / 2;
		ld = 0, rd = 1;
		
		for(int j = 1; j <= 50; j++)
		{
			double md = (ld + rd) / 2;
			solve(mc, md, A, B); 
			if(B > b) ld = md;
			else rd = md;
		}
		
		if(A > a) lc = mc;
		else rc = mc;
	}
	
	printf("%.5lf\n", dp[n] + a * lc + b * ld);
	return 0;
}