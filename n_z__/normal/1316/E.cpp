#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[100001][201];
struct node
{
	int v,s[11];
}a[100001];
bool cmp(node a,node b){return a.v>b.v;}
#define mymax(a,b) a=max(a,b)
signed main()
{
	memset(f,128,sizeof(f));
	int n,p,k;
	cin>>n>>p>>k;
	int pp=(1<<p)-1;
	for(int x=1;x<=n;x++)cin>>a[x].v;
	for(int x=1;x<=n;x++)for(int y=1;y<=p;y++)cin>>a[x].s[y];
	sort(a+1,a+n+1,cmp);
	f[0][0]=0;
	for(int x=1;x<=n;x++)
	for(int y=0;y<=pp;y++)
	{
		int cnt=0;
		int zz=1;
		for(int z=1;z<=p;z++,zz*=2)
		if(zz&y)cnt++,mymax(f[x][y],f[x-1][zz^y]+a[x].s[z]);
		mymax(f[x][y],f[x-1][y]+(x<=cnt+k?a[x].v:0));
	}
	cout<<f[n][pp];
}