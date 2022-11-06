#include <bits/stdc++.h>
#define ll long long 
#define N 100010
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n;
int t[N], A[N], B[N];
ll f[N];

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++) t[i] = read();
	for(int i = 1; i <= n; i ++)
	{
		A[i] = A[i - 1];
		while(t[i] - t[A[i] + 1] >= 90) A[i] ++;
 		B[i] = B[i - 1];
 		while(t[i] - t[B[i] + 1] >= 1440) B[i] ++;
	}
	for(int i = 1; i <= n; i ++)
		f[i] = min(f[i - 1] + 20, min(f[A[i]] + 50, f[B[i]] + 120));
	for(int i = 1; i <= n; i ++)
		printf("%I64d\n", f[i] - f[i - 1]);
	return 0;
}