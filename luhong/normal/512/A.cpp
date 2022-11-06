#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

char s[1010][1010]; int d[1010000];
int c[1010000], tot = 0;
int h[1010000], nxt[4010000], to[4010000], K = 0;
char ans[1010]; int tt = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 2; i <= n; i++)
	{
		int len = std::min(strlen(s[i - 1] + 1), strlen(s[i] + 1)); 
		bool ok = 0;
		for(int j = 1; j <= len; j++)
		{
			if(s[i][j] != s[i - 1][j])
			{
				ins(s[i - 1][j] - 'a', s[i][j] - 'a');
				d[s[i][j] - 'a']++;
				ok = 1; break;
			}
		}
		if(!ok && strlen(s[i - 1] + 1) > strlen(s[i] + 1)) return 0 * puts("Impossible");
	}
	for(int i = 0; i < 26; i++) if(d[i] == 0) pq.push(i); 
	while(!pq.empty())
	{
		int u = pq.top(); pq.pop();
		ans[++tt] = u + 'a';
		for(int i = h[u]; i; i = nxt[i])
		{
			if(--d[to[i]] == 0) pq.push(to[i]); 
		}
	}
	if(tt != 26) puts("Impossible");
	else printf("%s", ans + 1);
	return 0;
}