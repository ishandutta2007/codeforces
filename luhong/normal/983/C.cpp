#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define gx dp[k][used[v[0]][v[1]][v[2]][v[3]]][f]
using namespace std;
int dp[2010][1000][10];
int a[2010],b[2010],p[4],n;
int Abs(int x){return x>0?x:-x;}
int used[10][10][10][10],cnt=0;
int DP(int k,int v1,int v2,int v3,int v4,int f)
{
	int v[4];v[0]=v1;v[1]=v2;v[2]=v3;v[3]=v4;
	if(k==n&&v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0)return 0;
	sort(v,v+4);
	if(!used[v[0]][v[1]][v[2]][v[3]])used[v[0]][v[1]][v[2]][v[3]]=++cnt;
	if(gx!=-1)return gx;gx=1e9;
	int id=-1;
	for(int i=3;i>=0;i--)if(v[i]==0){id=i;break;}
	for(int i=id+1;i<=3;i++)
	{
		int o=v[i];v[i]=0;
		int y=DP(k,v[0],v[1],v[2],v[3],o);
		v[i]=o;
		gx=min(gx,y+Abs(f-v[i])+1);
	}
	if(id!=-1&&k!=n)
	{
		v[id]=b[k+1];int y=DP(k+1,v[0],v[1],v[2],v[3],a[k+1]);
		v[id]=0;
		gx=min(gx,y+Abs(f-a[k+1])+1);
	}
	return gx;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	memset(dp,-1,sizeof(dp));printf("%d",DP(0,0,0,0,0,1));int tot=0;
	return 0;
}