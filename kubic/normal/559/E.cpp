#include <bits/stdc++.h>
using namespace std;
#define N 105
int n,ds[N*3],tmp[N*3],dp[N][N*3];
struct Node {int x,l,id,idL,idR;}a[N];
bool cmp(Node x,Node y) {return x.x<y.x;}
int find(int x) {return lower_bound(ds+1,ds+ds[0]+1,x)-ds;} 
int main()
{
	scanf("%d",&n);ds[++ds[0]]=-1e9;
	for(int i=1,x,l;i<=n;++i)
	{
		scanf("%d %d",&x,&l);a[i]=(Node) {x,l};
		ds[++ds[0]]=x;ds[++ds[0]]=x-l;ds[++ds[0]]=x+l;
	}sort(a+1,a+n+1,cmp);sort(ds+1,ds+ds[0]+1);
	ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1,id,idL,idR,mx;i<=n;++i)
	{
		mx=id=a[i].id=find(a[i].x);
		idL=a[i].idL=find(a[i].x-a[i].l);
		idR=a[i].idR=find(a[i].x+a[i].l);
		for(int j=1;j<=ds[0];++j) tmp[j]=0,dp[i][j]=dp[i-1][j];
		tmp[mx]=dp[i-1][idL]+ds[mx]-ds[idL];
		for(int j=i-1;j;--j)
		{
			mx=max(mx,a[j].idR);
			tmp[mx]=max(tmp[mx],dp[j-1][idL]+ds[mx]-ds[idL]);
		}
		for(int j=ds[0];j>=idL;--j)
		{
			if(j<ds[0]) tmp[j]=max(tmp[j],tmp[j+1]+ds[j]-ds[j+1]);
			dp[i][j]=max(dp[i][j],tmp[j]);
		}
		for(int j=id;j<=idR;++j)
			dp[i][j]=max(dp[i][j],dp[i-1][id]+ds[j]-ds[id]);
		for(int j=1;j<=ds[0];++j) dp[i][j]=max(dp[i][j],dp[i][j-1]);
	}printf("%d\n",dp[n][ds[0]]);return 0;
}