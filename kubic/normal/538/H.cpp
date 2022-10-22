#include <bits/stdc++.h>
using namespace std;
#define N 100005
int vL,vR,n,m,tL,tR,S,L[N],R[N],col[N];vector<int> e[N];
bool dfs(int u)
{
	for(int i=0,v;i<e[u].size();++i)
	{
		v=e[u][i];
		if(!col[v]) {col[v]=3-col[u];if(!dfs(v)) return 0;}
		else if(col[u]==col[v]) return 0;
	}return 1;
}
int main()
{
	scanf("%d %d %d %d",&vL,&vR,&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d %d",&L[i],&R[i]);col[i]=0;
		tL=i==1?L[i]:max(tL,L[i]);tR=i==1?R[i]:min(tR,R[i]);
	}if(tL+tR<vL) tL=vL-tR;else if(tL+tR>vR) tR=vR-tL;
	if(tL<0 || tR<0) {puts("IMPOSSIBLE");return 0;}
	for(int i=1,u,v;i<=m;++i)
		scanf("%d %d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for(int i=1;i<=n;++i)
	{
		bool flL=L[i]<=tL && R[i]>=tL,flR=L[i]<=tR && R[i]>=tR; 
		if(!flL && !flR) {puts("IMPOSSIBLE");return 0;}
		else if(flL && !flR) col[i]=1;else if(!flL && flR) col[i]=2;
	}if(!dfs(S)) {puts("IMPOSSIBLE");return 0;}
	for(int i=1;i<=n;++i)
		if(col[i] && !dfs(i)) {puts("IMPOSSIBLE");return 0;}
	for(int i=1;i<=n;++i) if(!col[i])
	{col[i]=1;if(!dfs(i)) {puts("IMPOSSIBLE");return 0;}}
	printf("POSSIBLE\n%d %d\n",tL,tR);
	for(int i=1;i<=n;++i) putchar(col[i]+48);return 0;
}