#include<bits/stdc++.h>
using namespace std;
#define re register
#define cmin(a,b) (a>(b)?a=(b):0)
#define D isdigit(c=getchar())
inline int r()
{
	re int x;re char c;
	while(!D);for(x=c-'0';D;x=x*10+c-'0');
	return x;
}
int ta[2010][2010],dfn[2010],low[2010],tot;
bool ok;
void dfs(re int a)
{
	if(!ok)return;
	dfn[a]=low[a]=++tot;
	for(re int i=1;i<=ta[a][0];i++)
	if(!dfn[ta[a][i]]){
		dfs(ta[a][i]);
		cmin(low[a],low[ta[a][i]]);
	}else cmin(low[a],dfn[ta[a][i]]);
	if(a!=1&&low[a]==dfn[a]){ok=0;return;}
}
int main()
{
	re int n,t=1;
	for(;t--;)
	{
		n=r();
		for(re int i=1;i<=n;i++)
		{
			ta[i][0]=dfn[i]=low[i]=0;
			for(re int j=1;j<=n;j++)
			if(r()>0)ta[i][++ta[i][0]]=j;
		}tot=0;ok=1;
		dfs(1);
		if(tot!=n)ok=0;
		if(ok)puts("YES");
		else puts("NO"); 
	}
}