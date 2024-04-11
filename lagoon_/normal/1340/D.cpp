#include<bits/stdc++.h>
#define re register
int p1[1001000],t1[1001000],d[100100],tot;
struct eg{int to;eg*nx;}e[200100],*la[100100],*cnt=e;
inline void addE(re int a,re int b)
{
	*++cnt=(eg){b,la[a]};la[a]=cnt;
	*++cnt=(eg){a,la[b]};la[b]=cnt;
}
inline void adc(re int a,re int t){p1[++tot]=a;t1[tot]=t;}
void dfs(re int a,re int fa,re int ti)
{
	re int tn=ti;d[a]--;
	adc(a,ti);
	for(re eg*i=la[a];i;i=i->nx)if(i->to!=fa)
	{
		if(tn>=ti&&d[a]<=ti-1)
		{
			tn=ti-1-d[a];adc(a,tn);
		}
		dfs(i->to,a,tn+1);
		tn++;d[a]--;adc(a,tn);
	}
	if(tn>=ti&&d[a]<=ti-1)
	{
		tn=ti-1-d[a];adc(a,tn);
	}
}
int main()
{
	re int n,x,y;
	scanf("%d",&n);
	for(re int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		addE(x,y);d[x]++;d[y]++;
	}
	re int x0=0;adc(1,0);
	for(re eg*i=la[1];i;i=i->nx)
	{
		x0++;
		dfs(i->to,1,x0);adc(1,x0);
	}
	printf("%d\n",tot);
	for(re int i=1;i<=tot;i++)printf("%d %d\n",p1[i],t1[i]);
}