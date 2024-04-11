#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200001];
int f(int m)
{
	map<int,int>mp;
	int now=0,num=0,ans=0;
	for(int x=1;x<=n;x++)
	{
		mp[num]++;
		if(a[x]>=m)now+=mp[num],num++;
		else num--,now-=mp[num];
		ans+=now;
	}
	return ans;
}
main()
{
	int m;
	cin>>n>>m;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	cout<<f(m)-f(m+1);
}