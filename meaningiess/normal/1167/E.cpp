#include<bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
vector<int> v[N];int a[N],pr[N],sf[N];
int main()
{
	int n,x,i;ll ans=0;cin>>n>>x;sf[x+1]=n+1;
	for (i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
	for (i=1;i<=x+1;i++) if (v[i].size())
	{
		if (v[i][0]<pr[i-1]) {pr[i]=n+2;continue;}
		pr[i]=v[i][v[i].size()-1];
	}
	else pr[i]=pr[i-1];
	for (i=x;i>=0;i--) if (v[i].size())
	{
		if (v[i][v[i].size()-1]>sf[i+1]) {sf[i]=-1;continue;}
		sf[i]=v[i][0];
	}
	else sf[i]=sf[i+1];
	for (i=0;i<x;i++)
	{
		int t=lower_bound(sf,sf+x+2,pr[i])-sf;t=max(t,i+2);ans+=max(0,x-t+2);
	}
	cout<<ans;
}