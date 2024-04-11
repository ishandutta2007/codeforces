#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
#define int long long
bool vis[5001];
int n;
char a[5001][5001];
void dfs(int y,int z)
{
	vis[y]=1;
	for(int x=1;x<=n;x++)
	if(a[y][x]!='0'&&a[x][z]-'0'){cout<<x<<' '<<z<<' '<<y<<endl;exit(0);}
	else if(a[y][x]!='0'&&!vis[x])dfs(x,y);
}
signed main()
{
	cin>>n;
	for(int x=1;x<=n;x++)scanf("%s",a[x]+1);
	for(int x=1;x<=n;x++)if(!vis[x])dfs(x,x);
	puts("-1");
}