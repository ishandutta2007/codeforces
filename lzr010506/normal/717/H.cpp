#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n,m,T,u[N],v[N],l[N][22],r[N],c[N*10];
void init()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i ++)
		scanf("%d%d", u + i, v + i);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d",l[i]);
		for(int j = 1; j <= *l[i]; j ++)
			scanf("%d",l[i] + j), T = max(T,l[i][j]);
	}
}

bool work()
{
	for(int i = 1; i <= n; i ++)
		r[i] = l[i][rand() % *l[i] + 1];
	for(int i = 1; i <= T; i ++)
		c[i] = (rand() & 1) + 1;
	int cnt = 0; 
	for(int i = 1; i <= m; i ++)
		cnt += c[r[u[i]]] != c[r[v[i]]];
	if(cnt * 2 >= m)return 1;
	return 0;
}

int main()
{
	init();
	while(!work());
	for(int i = 1; i <= n; i ++)
		printf("%d%c",r[i]," \n"[i == n]);
	for(int i = 1; i <= T; i ++)
		printf("%d%c",c[i]," \n"[i == T]);
	return 0;
}