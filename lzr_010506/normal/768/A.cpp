#include <bits/stdc++.h>
using namespace std;
int n, ans;
int a[100010];
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
	for(int i = 1; i <= n; i ++)
        a[i] = read();
    sort(a + 1, a + n + 1);
    int x = a[1];
    int y = a[n];
    for(int i = 1; i <= n; i ++)
        if(a[i] != x && a[i] != y)
            ans ++;
    cout << ans;
	return 0;
}