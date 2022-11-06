#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int p[101000],a[101000],k;long long dp[101000][22],w;
void del(int x){p[a[x]]--;w-=p[a[x]];}
void ins(int x){w+=p[a[x]];p[a[x]]++;}
void move(int &a,int &b,int c,int d)
{
	while(a<c)del(a++);
	while(a>c)ins(--a);
	while(b<d)ins(++b);
	while(b>d)del(b--);
}
void solve(int l,int r,int l1,int r1)//w=w(l1,l)=w[p,q]
{
	if(l>r)return;
	int mid=l+r>>1;
	int g=-1,p=l1+1,q=l-1;
	move(p,q,l1+1,mid);
	for(int i=l1;i<=min(mid,r1);i++)
	{
		if(dp[i][k-1]+w<dp[mid][k])
			dp[mid][k]=dp[i][k-1]+w,g=i; 
		del(p++);
	}
	move(p,q,l1+1,l-1);
	solve(l,mid-1,l1,g);
	move(p,q,g+1,mid);
	solve(mid+1,r,g,r1);
	move(p,q,l1+1,l-1);
}
int main()
{
	int n,K;scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=K;j++)dp[i][j]=1ll<<60;
	for(int i=1;i<=K;i++)
	{
		k=i;w=0;memset(p,0,sizeof(p));solve(1,n,0,n);
	}
	printf("%lld\n",dp[n][K]);return 0;
 } 
/*
dp[i][k]=min(dp[j][k-1]+w(j,i]) 
ming[i](i)
[l,r]DP[l1,r1]
mid(w) 

*/