#include<bits/stdc++.h>
using namespace std;
#define re register
double lb[400100],rb[400100],us[400100],v[400100];
inline bool cmp(re int a,re int b){return v[a]>v[b];}
int x[400100],pq[400100];
int main()
{
	re int n,l,ta=0,n1=0,xx,y;
	re double s;
	scanf("%d%d",&n,&l);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d%lf",&xx,&y,&s);
		s++;
		if(xx>x[n1])x[++n1]=xx,v[n1]=1;
		x[++n1]=y;v[n1]=s;
	}
	if(x[n1]!=l)x[++n1]=l,v[n1]=1;
	for(re int i=1;i<=n1;i++)
	{
		s=x[i]-x[i-1];
		if(v[i]!=1)lb[i]=-s/(v[i]-1);
		rb[i]=s/(v[i]+1);
	}
	for(re int i=n1;i;i--)
	{
		while(ta)
		{
			if(v[pq[1]]>=v[i])break;
			//printf("**%d %d\n",i,pq[1]);
			re double x1=us[i]-lb[i],x2=rb[pq[1]]-us[pq[1]];
			if(x1>x2)
			{
				us[pq[1]]=rb[pq[1]];
				us[i]-=x2;
				pop_heap(pq+1,pq+ta+1,cmp);
				ta--;
			}else
			{
				us[pq[1]]+=x1;
				us[i]=lb[i];
				break;
			}
		}
		pq[++ta]=i;
		push_heap(pq+1,pq+ta+1,cmp);
	}
	re double ans=0;
	for(re int i=1;i<=n1;i++)
	{
		//printf("**%d %d %lf %lf %lf %lf\n",i,x[i],v[i],us[i],lb[i],rb[i]);
		ans+=(x[i]-x[i-1]-us[i])/v[i];
	}
	printf("%.13lf\n",ans);
}