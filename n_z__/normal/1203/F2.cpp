#include<bits/stdc++.h>
using namespace std;
struct nodee{
	int a,b;
};
struct node{
	int num;
	nodee s[101];
}a,b;
int dp[101][60001];
bool cmp(nodee a,nodee b)
{
	return a.a<b.a;
}
bool cmp2(nodee a,nodee b)
{
	return a.a+a.b>b.a+b.b;
}
int main()
{
	int n,r;
	cin>>n>>r;
	for(int x=1;x<=n;x++)
	{
		int y,z;
		cin>>y>>z;
		if(z>=0){a.s[++a.num].a=y;a.s[a.num].b=z;}
		else {b.s[++b.num].a=y;b.s[b.num].b=z;}
	}
	sort(a.s+1,a.s+1+a.num,cmp);
	int ans=0;
	for(int x=1;x<=a.num;x++)
	if(r>=a.s[x].a)r+=a.s[x].b,ans++;
	else break;
	sort(b.s+1,b.s+1+b.num,cmp2);
	int ans2=0;
	for(int x=1;x<=b.num;x++)
	if(r>=b.s[x].a&&r>=abs(b.s[x].b))
	{
		dp[x][r-abs(b.s[x].b)]=1;
		ans2=max(ans2,1);
		for(int y=x-1;y>=1;y--)
		for(int z=max(abs(b.s[x].b),b.s[x].a);z<=60000;z++)
		if(dp[y][z])dp[x][z-abs(b.s[x].b)]=max(dp[x][z-abs(b.s[x].b)],dp[y][z]+1),ans2=max(ans2,dp[x][z-abs(b.s[x].b)]);
	}
	cout<<ans+ans2<<endl;
}