#include<bits/stdc++.h>
using namespace std;
#define re register
#define ui unsigned int
#define ull unsigned long long
int cnt1,cnt2;
bool in[300100];
int mt[500100];
int main()
{
	re int n,m,x,y,t;
	scanf("%d",&t);
	for(;t--;)
	{	
		scanf("%d%d",&n,&m);n*=3;
		cnt1=n;cnt2=0;
		for(re int i=1;i<=n;i++)in[i]=0;
		for(re int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			if(in[x]==0&&in[y]==0)in[x]=in[y]=1,mt[++cnt2]=i,cnt1-=2;
		}
		if(cnt1>=n/3)
		{
			cnt1=n/3;
			puts("IndSet");for(re int i=1;i<=n&&cnt1;i++)if(!in[i])printf("%d ",i),cnt1--;puts("");
		}else
		{
			puts("Matching");for(re int i=1;i<=n/3;i++)printf("%d ",mt[i]);puts("");
		}
	}
}