#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int G[1001][1001];
int mx[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i=1;i<=1000;i++)for(int j=1;j<=1000;j++)G[i][j]=gcd(i,j);
	int T;cin>>T;
	for(;T--;)
	{
		for(int i=1;i<=1000;i++)mx[i]=0;
		int N;cin>>N;
		for(int i=1;i<=N;i++)
		{
			int A;cin>>A;
			mx[A]=i;
		}
		int ans=-1;
		if(mx[1]!=0)ans=mx[1]*2;
		for(int i=1;i<=1000;i++)if(mx[i]!=0)
		{
			for(int j=i+1;j<=1000;j++)if(mx[j]!=0&&G[i][j]==1)ans=max(ans,mx[i]+mx[j]);
		}
		cout<<ans<<"\n";
	}
}