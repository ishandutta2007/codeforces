#include <bits/stdc++.h>
#define Mn 410
using namespace std;
int n, m, r, c;
char ch[Mn][Mn], pat[Mn][Mn];
bitset<640010> bs[26], ans;
int N, M;
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%s", ch[i]);
	scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i ++)
		scanf("%s", pat[i]);
	ans.set();
	N = n + r;
	M = m + c;
	for(int i = 0; i < n; i ++)
		for(int j = 0; j < m; j ++)
		{
			int now = ch[i][j] - 'a';
			for(int x = i; x < N; x += n)
				for(int y = j; y < M; y += m)
					bs[now].set(x * M + y);
		}
	
	for(int i = 0; i < r; i ++)
		for(int j = 0; j < c; j ++)
		{
			if(pat[i][j] == '?') continue;
			int now = pat[i][j] - 'a';
			ans &= bs[now] >> (i * M + j);
		}
	
	for(int i = 0; i < n; i ++, puts("")) 
		for(int j = 0; j < m; j ++) 
			putchar(ans[i * M + j] + '0');

	return 0;
}