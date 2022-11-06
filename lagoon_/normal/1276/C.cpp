#include<bits/stdc++.h>
using namespace std; 
#define re register
int a[400100],b,a1[400100],b1[400100],pk[4010000],tot,pp[400100];
inline bool cmp(re int a,re int b){return b1[a]>b1[b];}
int main()
{
	re int n,nm=1,mm,mx=-1<<30;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(re int i=1;i<=n;i++)if(a[i]!=a1[tot])a1[++tot]=a[i],b1[tot]=1,pk[tot]=tot;else b1[tot]++;
	sort(pk+1,pk+n+1,cmp);
	for(re int i=1;;i++)
	{
		re int nn=0,xx;
		for(re int j=1;j<=tot;j++)if(b1[j]>i)nn+=i;else nn+=b1[j];
		xx=nn/i*i;if(nn/i<i)break;if(xx>mx)mx=xx,mm=i;
	}
	printf("%d\n%d %d\n",mx,mm,mx/mm);
	re int mk=mx/mm,mc=mk*mm;
	re int ii=1,jj=0;
	for(re int i=1;i<=tot;i++)
	{
		re int xx=min(mm,b1[pk[i]]);
		for(;xx&&mc;xx--)
		{
			pp[(ii-1)*mk+(ii+jj-1)%mk+1]=a1[pk[i]];
			ii++;if(ii>mm)ii-=mm,jj++;
			mc--;
		}
	}
	for(re int i=1;i<=mm;i++){for(re int j=1;j<=mk;j++)printf("%d ",pp[(i-1)*mk+j]);puts("");}
}