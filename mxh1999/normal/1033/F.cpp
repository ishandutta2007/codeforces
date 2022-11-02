#include<bits/stdc++.h>
using namespace std;

int a[10010];
int f[10010];
int g[20000010];
char str[20],s[20];
int w,n,m;
int all;
void dfs(int t,int x,int y)
{
	if (t>=w)
	{
		g[x]+=y;
		return;
	}
	dfs(t+1,x|(1<<(12+t)),y);
	dfs(t+1,x&(all^(1<<t)),y);
}
void prepare()
{
	for (int i=0;i<(1<<w);i++)
	if (a[i])
		dfs(0,i,a[i]);
}
int main()
{
	scanf("%d%d%d",&w,&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		a[x]++;
	}
	all=(1<<24)-1;
	prepare();
	for (int i=1;i<=m;i++)
	{
		scanf("%s",str+1);
		for (int j=0;j<w;j++)
			s[j]=str[w-j];
		f[0]=0;
		for (int j=0;j<w;j++)
		{
			//int tmp=check(0,0,s[j]),tmp1=check(0,1,s[j]);
			if (s[j]=='O' || s[j]=='X')	f[0]|=1<<(12+j);
			if (s[j]=='o' || s[j]=='x')f[0]|=(1<<(12+j))|(1<<j);
			if (s[j]=='a')	f[0]|=1<<j;
		}
		for (int j=1;j<(1<<w);j++)
		{
			int t=j&(-j);
			int ha=__builtin_ctz(t);
			f[j]=f[j-t]&(all^(1<<ha)^(1<<(ha+12)));
			if (s[ha]=='A' || s[ha]=='x')	f[j]|=1<<(12+ha);
			if (s[ha]=='a' || s[ha]=='X')	f[j]|=(1<<(12+ha))|(1<<ha);
			if (s[ha]=='O')	f[j]|=1<<ha;
		}
		int ans=0;
		for (int j=0;j<(1<<w);j++)
			ans+=a[j]*g[f[j]];
		printf("%d\n",ans);
	}
	return 0;
}