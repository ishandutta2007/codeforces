#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, m, ans;
string a[N], b[N];
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= m; i ++) cin >> b[i];
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(a[i] == b[j]) ans ++;
	if(n - ans / 2 > m - (ans + 1) / 2)  printf("YES");
	else printf("NO");
	return 0;
}