#include<iostream>
#include<cstdio>
using namespace std;
bool is[101000];int pri[101000],tot=0,Min[101000],n,m;
bool type;int a[101000],len;
bool used[101000];
int ans[1010000][2],s=0;
void init()
{
	for(int i=2;i<=n;i++)
	{
		if(!is[i])pri[++tot]=i,Min[i]=i;
		for(int j=1;j<=tot&&i*pri[j]<=n;j++)
		{
			is[i*pri[j]]=1;Min[i*pri[j]]=pri[j];
			if(i%pri[j]==0)break;
		}
	}
}
void dfs(int i,long long S,int T)
{
	if(S>n||s>=m)return;
	if(T>len)return; 
	dfs(i,S,T+1);
	while(1)
	{
		if(s>=m)return;
		S*=a[T];
		if(S<=n)
		{
			if(S>=i)ans[++s][0]=i,ans[s][1]=S;
			if(s>=m)return;
			dfs(i,S,T+1);
		}
		else return;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	init();
	for(int i=2;i<=n;i++)
		if(s<=m)ans[++s][0]=1,ans[s][1]=i;
	if(m<n-1)return 0*puts("Impossible");
	for(int i=2;i<=n;i++)
	{
		if(s>=m)break;
		int x=i;len=0;
		while(x!=1){used[Min[x]]=1;x/=Min[x];}
		for(int j=1;j<=tot;j++)
		{
			if(!used[pri[j]])a[++len]=pri[j];
		}
		dfs(i,1,1);
		x=i;
		while(x!=1){used[Min[x]]=0;x/=Min[x];}
	}
	if(s<m)return 0*puts("Impossible");
	puts("Possible");
	for(int i=1;i<=m;i++)printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}