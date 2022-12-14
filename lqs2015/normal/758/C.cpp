#include<iostream>
using namespace std;
long long p,tim,re;
long long n,m,k,x,y,mx,mn,ans;
long long askfor(int ii,int jj)
{
	if (ii==1)
	{
		if (re>=jj) return 1;
		return 0;
	}
	if (ii==n)
	{
		if (re>=m*(n-1)+jj) return 1;
		return 0;
	}
	int res=0;
	if (re>=m*(ii-1)+jj) res++;
	if (re>=m*(n*2-ii-1)+jj) res++;
	return res;
}
int main()
{
	cin>>n>>m>>k>>x>>y;
	if (n==1)
	{
		tim=m;
		if (k%m==0)
		{
			cout<<k/m<<" "<<k/m<<" "<<k/m<<endl;
		}
		else
		{
			cout<<k/m+1<<" "<<k/m<<" ";
			if (k%m<y) cout<<k/m<<endl;
			else cout<<k/m+1<<endl;
		}
		return 0;
	}
	tim=m*(2*n-2);
	re=k%tim;
	mx=0;mn=1e18;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (i==1 || i==n) p=1;
			else p=2;
			long long val=p*(k/tim)+askfor(i,j);
			if (x==i && y==j) ans=val;
			mx=max(mx,val);
			mn=min(mn,val);
		}
	}
	cout<<mx<<" "<<mn<<" "<<ans<<endl;
	return 0;
}