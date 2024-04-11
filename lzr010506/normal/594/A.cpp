#include <bits/stdc++.h>
#define N 200010
using namespace std;
int a[N], n;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	n = read();
	for(int i = 0; i < n; i ++)
		a[i] = read();
	sort(a, a + n);
	int m = n / 2;
	if(n & 1) m --;
	if(m == 0) m ++;
	int ans = 2e9;
	for (int i = 0; i + m < n; i ++)
		ans = min(ans, a[i + m] - a[i]);
	printf("%d", ans);
	return 0;
}