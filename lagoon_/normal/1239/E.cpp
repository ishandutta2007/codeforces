#include<bits/stdc++.h>
using namespace std;
#define re register
bitset<2*50000*25+11>bt[50][30];
int a[100100],ann[2][50];
int main()
{
	re int n,bg1,bg2=0;
	scanf("%d",&n);
	bg1=n+1;
	for(re int i=1;i<=2*n;i++)scanf("%d",&a[i]);
	sort(a+1,a+2*n+1);
	ann[0][1]=a[1];ann[1][n]=a[2];
	bt[0][0][50000*25+5]=1;
	for(re int i=1;i<=2*n-2;i++)
	{
		a[i]=a[i+2];
		for(re int j=0;j<=n-1;j++)
		{
			bt[i][j]=(bt[i-1][j]<<a[i]);
			if(j)bt[i][j]|=(bt[i-1][j-1]>>a[i]);
		}
	}
	re int ans=50000*25+5,nw=n-1;
	while(!bt[2*n-2][n-1][ans])ans++;
	//printf("**%d %d\n",ans-50000*25-5,(int)bt[1][1][25*50000+5-3]);
	for(re int i=2*n-2;i;i--)
	{
		if(bt[i-1][nw][ans-a[i]])ans-=a[i],ann[0][--bg1]=a[i];//,printf("****%d\n",i);
		else ans+=a[i],nw--,ann[1][++bg2]=a[i];
	}
	for(re int i=0;i<=1;i++){for(re int j=1;j<=n;j++)printf("%d ",ann[i][j]);puts("");}
}