#include<bits/stdc++.h>
#define re register
char s1[110],s2[110];
const int B=1<<10;
int k,x1[1001000],x2[1001000],f1[1001000],f2[1001000],pp[1001000],mi[1101000],as[1100][1100],as1[1100][1100],vl[1100];
bool bl[1101000];
int ff(re char*ss,re int*p)
{
	re int f1=0;
	for(re int i=1;i<=k;i++)f1|=(ss[i]-'0')<<(p[i]-1);
	return f1;
}
int main()
{
	re int n,m;
	scanf("%d%d%d%s%s",&n,&m,&k,s1+1,s2+1);
	for(re int i=1;i<B;i++)vl[i]=vl[i/2]+(i&1);
	for(re int i=1;i<=k;i++)pp[i]=i;
	f1[0]=ff(s1,pp);
	mi[f1[0]]=1;
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&x1[i],&x2[i]);
		std::swap(pp[x1[i]],pp[x2[i]]);
		f1[i]=ff(s1,pp);f2[i]=ff(s2,pp);
		if(!mi[f1[i]])mi[f1[i]]=i+1;
	}
	re int ans=1<<30,lans=0,rans=0;
	for(re int i1=0;i1<B;i1++)for(re int j1=0;j1<B;j1++)as[i1][j1]=1<<30;
	for(re int i=n-m;i>=0;i--)
	{
		if(!bl[f2[i+m]])
		{
			bl[f2[i+m]]=1;
			re int xx=f2[i+m]/B,yy=f2[i+m]%B;
			for(re int i1=0;i1<B;i1++)
			{
				if(as[xx][i1]>vl[yy^i1])
				{
					as[xx][i1]=vl[yy^i1];
					as1[xx][i1]=i+m;
				}
			}
		}
		if(i+1==mi[f1[i]])
		{
			re int xx=f1[i]/B,yy=f1[i]%B;
			for(re int i1=0;i1<B;i1++)
			{
				if(vl[xx^i1]+as[i1][yy]<ans)ans=vl[xx^i1]+as[i1][yy],lans=i+1,rans=as1[i1][yy];
			}
		}
	}
	printf("%d\n%d %d\n",k-ans,lans,rans);
}