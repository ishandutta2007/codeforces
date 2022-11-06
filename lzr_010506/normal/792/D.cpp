#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, u, sz[70];
int q, rt[100010];
char ch[100010];
int main()
{
	scanf("%I64d %d", &n, &q);
	ll top = n / 2LL + 1LL;
	int top_c;
	sz[1] = 1;
	if(top == 1) top_c = 1;
	for(int i = 2; i < 70; i ++)
	{
		sz[i] = sz[i - 1] * 2;
		if(sz[i] == top) top_c = i;

	}
	while(q --)
	{
		scanf("%I64d", &u);
		int c = top_c, p = 0;
		ll now = top;
		while(now != u)
		{
			if(now < u) rt[++ p] = 2, now = now + sz[-- c];
			else rt[++ p] = 1, now = now - sz[-- c];
		}
		scanf("%s", ch);
		int l = strlen(ch);
		for(int i = 0; i < l; i ++)
		{
			char op = ch[i];
			if(op == 'U')
			{
				if(c == top_c) continue;
				if(rt[p] == 1) now = now + sz[c ++], p --;
				else now = now - sz[c ++], p --;
				continue;
			}
			if(op == 'L')
			{
				if(c == 1) continue;
				rt[++ p] = 1;
				now = now - sz[-- c];
				continue;
			}
			if(op == 'R')
			{
				if(c == 1) continue;
				rt[++ p] = 2;
				now = now + sz[-- c];
			}
		}
		printf("%I64d\n", now);
	}


	return 0;
}