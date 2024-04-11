#include<bits/stdc++.h>
#define re register
int b[1010][4],as[3010],ans[3010];
std::bitset<3010>bs[2010];
bool bb[2010];
char ss[1010];
int main()
{
	re int n,m,k,tot=0,x;
	scanf("%d%d",&n,&k);
	for(re int i=1;i<=n;i++)b[i][1]=1,b[i][2]=2,b[i][3]=3;
	for(;k--;)
	{
		scanf("%s%d",ss+1,&m);
		if(ss[1]=='m')
		{
			for(re int i=1;i<=m;i++)
			{
				scanf("%d",&x);
				bs[tot+1][x*3-3+b[x][1]]=1;
				bs[tot+1][x*3-3+b[x][3]]=1;
				bs[tot+2][x*3-3+b[x][2]]=1;
				bs[tot+2][x*3-3+b[x][3]]=1;
			}
			scanf("%s",ss+1);
			bb[tot+1]=(ss[1]=='R'||ss[1]=='Y');
			bb[tot+2]=(ss[1]=='B'||ss[1]=='Y');
			tot+=2;
		}else
		{
			re int x1=(ss[1]=='R'?1:3),y1=(ss[2]=='B'?2:3);
			for(re int i=1;i<=m;i++)
			{
				scanf("%d",&x);
				std::swap(b[x][x1],b[x][y1]);
			}
		}
	}
	re int tt=0;
	for(re int i=1;i<=3*n;i++)
	{
		re int j=tt+1;
		for(;j<=tot;j++)if(bs[j][i])break;
		if(j>tot)continue;
		std::swap(bs[j],bs[++tt]);
		std::swap(bb[j],bb[tt]);
		for(j++;j<=tot;j++)if(bs[j][i])
		{
			bs[j]^=bs[tt];bb[j]^=bb[tt];
		}
	}
	for(re int i=1;i<=3*n;i++)as[i]=-1;
	for(re int i=tot;i;i--)
	{
		re bool bl=bb[i];
		for(re int j=3*n;j;j--)
		if(bs[i][j]){
			if(as[j]==-1)as[j]=bl;
			bl^=as[j];
		}
		if(bl)
		{
			puts("NO");return 0;
		}
	}
	for(re int i=1;i<=3*n;i++)
	{
		if(as[i]==1)ans[(i+2)/3]^=(i-1)%3+1;
	}
	puts("YES");
	for(re int i=1;i<=n;i++)
	{
		if(ans[i]==0)putchar('.');
		else if(ans[i]==1)putchar('R');
		else if(ans[i]==2)putchar('B');
		else putchar('Y');
	}
}