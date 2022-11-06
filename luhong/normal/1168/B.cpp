#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 301000

char s[MN];
int L[MN], R[MN], top = 0;

int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int l = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = l + 1; j < i; j++)
		{
			if(s[j] == s[i] && s[i] == s[i + i - j])
			{
				while(top && i + i - j <= R[top]) top--;
				++top; L[top] = j, R[top] = i + i - j;
				l = j;
			}
		}
	}
	int j = 1; long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(j <= top) ans += n - R[j] + 1;
		if(j <= top && L[j] == i) j++;
	}
	printf("%lld\n", ans);
}