#include<bits/stdc++.h>
#define re register
const long double eps=1e-17;
int a[110],b[110],x[1010],y[1010],k,nw,n,xxx[1010],yyy[1010],bk,q[1010],ta,bg[11][1010],X;
long double dd[11][1010];
bool vis[110],us[1010];
long double dis(re int i,re int j){return sqrtl((long long)(a[i]-x[j])*(a[i]-x[j])+(long long)(b[i]-y[j])*(b[i]-y[j]));}
inline bool cmp(re int i,re int j){return dd[X][i]<dd[X][j];}
int gcd(re int a,re int b)
{
	return b?gcd(b,a%b):a;
}
bool dfs()
{
	re int ta1=ta,x1=q[ta],bbl=0;
	nw--;ta--;
	for(re int i=1;i<=k&&!bbl;i++)
	if(!vis[i]){
		vis[i]=1;
		for(re int j=bg[i][x1];j!=-1;j=bg[i][j])
		if(!us[j]){
			q[++ta]=j;us[j]=1;if(ta>nw)break;
		}//printf("****%d %d %d %d %d %d\n",x1,i,ta,nw,bg[i][x1],us[2]);
		if(ta==0||(ta<=nw&&dfs()))bbl=1;
		while(ta>=ta1)us[q[ta--]]=0;
		vis[i]=0;
	}
	q[++ta]=x1;nw++;
	return bbl;
}
int main()
{
	scanf("%d%d",&k,&n);
	for(re int i=1;i<=k;i++)scanf("%d%d",&a[i],&b[i]);
	for(re int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
	for(re int i=1;i<=k;i++)
	{
		X=i;
		for(re int j=1;j<=n;j++)
		{
			vis[j]=0,dd[i][j]=dis(i,j),xxx[j]=(x[j]-a[i]),yyy[j]=(y[j]-b[i]);
			re int ddd=gcd(xxx[j]>0?xxx[j]:-xxx[j],yyy[j]>0?yyy[j]:-yyy[j]);
			xxx[j]/=ddd;yyy[j]/=ddd;
		}
		for(re int j=1;j<=n;j++)if(!vis[j])
		{
			vis[j]=1;q[ta=1]=j;
			for(re int k=1;k<=n;k++)if(!vis[k])
			{
				if(xxx[j]==xxx[k]&&yyy[j]==yyy[k])
				{
					q[++ta]=k;vis[k]=1;
				}
			}
			std::sort(q+1,q+ta+1,cmp);
			q[0]=-1;
			for(re int k=1;k<=ta;k++)bg[i][q[k]]=q[k-1];//,printf("**%d %d %d\n",i,j,q[k]);
		}
	}
	re int ans=0;
	for(re int i=1;i<=k;i++)vis[i]=0;
	for(re int i=1;i<=n;i++)
	{
		nw=k;
		q[ta=1]=i;us[i]=1;
		ans+=dfs();
		us[i]=0;
	}
	printf("%d\n",ans);
}