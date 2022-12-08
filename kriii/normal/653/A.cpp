#include <stdio.h>

bool chk[1001];

int main()
{
	int n; scanf ("%d",&n); while (n--){
		int x; scanf ("%d",&x);
		chk[x] = 1;
	}
	for (int i=2;i<=1000;i++) if (chk[i-2] && chk[i-1] && chk[i]){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}