#include <stdio.h>
#include <string.h>
#define MAXN 5005

int lcp[MAXN][MAXN], mua[MAXN], mub[MAXN];
char a[MAXN], b[MAXN];

inline int max(int a, int b){return a > b ? a : b;}
inline int min(int a, int b){return a > b ? b : a;}
void calc(char a[], char b[], int lcp[][MAXN])
{
	int la = strlen(a), lb = strlen(b), i, j;
	for(i = la - 1; i >= 0; i --)
		for(j = lb - 1; j >= 0; j --)
			if(a[i] == b[j])
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			else
				lcp[i][j] = 0;
}
int main()
{
	scanf("%s%s", a, b);
	int la = strlen(a), lb = strlen(b), i, j, ans = 1 << 30;
	calc(a, a, lcp);
	for(i = 0; i < la; i ++)
	{
		mua[i] = 0;
		for(j = 0; j < la; j ++)
			if(i != j)
				mua[i] = max(mua[i], lcp[i][j]);
		mua[i] ++;
	}
	memset(lcp, 0, sizeof(lcp));
	calc(b, b, lcp);
	for(i = 0; i < lb; i ++)
	{
		mub[i] = 0;
		for(j = 0; j < lb; j ++)
			if(i != j)
				mub[i] = max(mub[i], lcp[i][j]);
		mub[i] ++;
	}
	memset(lcp, 0, sizeof(lcp));
	calc(a, b, lcp);
	for(i = 0; i < la; i ++)
		for(j = 0; j < lb; j ++)
			if(lcp[i][j] >= max(mua[i], mub[j]))
				ans = min(ans, max(mua[i], mub[j]));
	printf("%d\n", ans >= 1 << 30 ? -1 : ans);
	return 0;
}