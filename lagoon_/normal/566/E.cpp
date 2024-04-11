#include<bits/stdc++.h>
#define re register
int s[1010][1010],k[1010],d[1010];
std::bitset<1010>ba[1010],bb[1010],bc,bk,bc1,bk1,bd;
int main()
{
	re int n,nm=0;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(re int j=1;j<=k[i];j++)scanf("%d",&s[i][j]),bb[i].set(s[i][j]);
		ba[i][i]=1;
	}
	for(re int i=1;i<=n;i++)
		for(re int j=i+1;j<=n;j++)
		{
			if((bb[i]&bb[j]).count()==2)
			{
				re int xx=0,xy=0;
				for(re int i1=1;i1<=n;i1++)
				if(bb[i][i1]&&bb[j][i1]){
					if(!xx)xx=i1;else xy=i1;
				}
				ba[xx][xy]=ba[xy][xx]=1;d[xx]++;d[xy]++;nm++;
			}
		}
	k[0]=1<<30;
	for(re int i=1;i<=n;i++)if(d[i])bd[i]=1;
	if(!nm){for(re int i=1;i<n;i++)printf("%d %d\n",i,n);return 0;}
	for(re int i=1;i<=n;i++)if(!d[i])
	{
		re int x=0,x1,xx=0;
		for(re int j=1;j<=n;j++)if(bb[j][i]&&k[j]<k[x])x=j;
		for(re int j=1;j<=k[x];j++)if(d[s[x][j]]!=0)
		{
			x1=s[x][j];
			//std::cout<<bd<<std::endl<<ba[x1]<<std::endl<<bb[x]<<std::endl;
			if((ba[x1]&bd)==(bb[x]&bd))xx=x1;
		}//printf("**%d %d %d\n",i,xx,x);
		ba[i][xx]=ba[xx][i]=1;
		bd[i]=1;
	}
	for(re int i=1;i<=n;i++)for(re int j=i+1;j<=n;j++)if(ba[i][j])printf("%d %d\n",i,j);
	return 0;
}