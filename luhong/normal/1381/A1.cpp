#include <cstdio>
#include <iostream> 
#define MN 201000

char a[MN], b[MN];
int ans[MN];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int n, tot = 0; scanf("%d", &n);
		scanf("%s%s", a + 1, b + 1);
		int l = 1, r = n, t = 0;
		for(int i = n; i >= 1; i--)
		{
			if(t == 0) 
			{
				if(a[l] == b[i]) ans[++tot] = 1;
				ans[++tot] = r - l + 1;
				l++; t = 1;
			}
			else
			{
				if((a[r] ^ 1) == b[i]) ans[++tot] = 1;
				ans[++tot] = r - l + 1;
				r--; t = 0;
			} 
		}
		printf("%d ", tot);
		for(int i = 1; i <= tot; i++) printf("%d ", ans[i]); puts("");
	}
}