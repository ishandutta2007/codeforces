#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,sz,ans;
bool used[11];
void dfs(int i,int a,int b)
{
	if (i==x+y+1)
	{
		if (a<n && b<m) ans++;
		return;
	}
	for (int j=0;j<=6;j++)
	{
		if (!used[j])
		{
			used[j]=1;
			if (i>x) dfs(i+1,a,b*7+j);
			else dfs(i+1,a*7+j,b);
			used[j]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	sz=1;
	while(sz<n)
	{
		sz*=7;
		x++;
	}
	sz=1;
	while(sz<m)
	{
		sz*=7;
		y++;
	}
	if (n==1) x=1;
	if (m==1) y=1;
	if (x+y>7) printf("0\n");
	else
	{
		dfs(1,0,0);
		printf("%lld\n",ans);
	}
	return 0;
}