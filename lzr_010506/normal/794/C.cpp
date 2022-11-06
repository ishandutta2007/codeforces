#include <bits/stdc++.h>
using namespace std;
char a[300010], b[300010], ans[3000010];
int main()
{
	scanf("%s%s", a, b);
	int n = strlen(a);
	int s = (n + 1) / 2;
	sort(a, a + n);
	sort(b, b + n);
	reverse(b, b + n);
	int c = 0, L1 = 0, R1 = s - 1, L2 = 0, R2 = n - s - 1;
	int r = n - 1, h = 0;
	for(int i = 0; i < n; i ++)
	{
		if(a[L1] < b[L2]) ans[h ++] = a[L1 ++];
		else ans[r --] = a[R1 --];
		if(++ c >= n) break;
		if(b[L2] > a[L1]) ans[h ++] = b[L2 ++];
		else ans[r --] = b[R2 --];
		if(++ c >= n) break;
	}
	for(int i = 0; i < n; i ++) printf("%c", ans[i]);
	return 0;
}