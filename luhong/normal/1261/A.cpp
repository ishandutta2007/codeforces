#include <iostream>
#include <cstdio>
#include <algorithm>
#define MN 2100

char s[MN];
int l[MN], r[MN];

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		int tot = 0;
		int n, k; scanf("%d%d", &n, &k);
		scanf("%s", s); 
		k--;
		for(int i = 0; i < k; i++)
		{
			int id;
			for(int j = 2 * i; j < n; j++)
			{
				if(s[j] == '(') {id = j; break;} 
			}
			++tot; l[tot] = 2 * i; r[tot] = id;
			std::reverse(s + l[tot], s + r[tot] + 1);
			
			for(int j = 2 * i + 1; j < n; j++)
			{
				if(s[j] == ')') {id = j; break;} 
			}
			++tot; l[tot] = 2 * i + 1; r[tot] = id;
			std::reverse(s + l[tot], s + r[tot] + 1);
		}
		int now = 2 * k, w = (n - 2 * k) / 2;
		while(w--)
		{
			int id;
			for(int j = now; j < n; j++)
			{
				if(s[j] == '(') {id = j; break;} 
			}
			++tot; l[tot] = now; r[tot] = id;
			std::reverse(s + l[tot], s + r[tot] + 1);
			now++;
		}
		printf("%d\n", tot);
		for(int i = 1; i <= tot; i++) printf("%d %d\n", l[i] + 1, r[i] + 1);
	}
}