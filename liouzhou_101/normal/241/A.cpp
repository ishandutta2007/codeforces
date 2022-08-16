#include<cstdio>
#include<iostream>

using namespace std;

long long m,k;
long long s[1010],d[1010];
long long way,ans;

int main()
{
	cin>>m>>k;
	for (int i=1;i<=m;++i)
	{
		cin>>s[i];
		ans+=s[i];
	}
	for (int i=1;i<=m;++i)
	{
		cin>>d[i];
	}
	long long get=0;
	long long tmp;
	for (int i=1;i<=m;++i)
	{
		get=max(get,d[i]);
		way+=d[i];
		if (way<s[i])
		{
			ans+=(tmp=(s[i]-way+get-1)/get)*k;
			way+=tmp*get;
		}
		way-=s[i];
	}
	cout<<ans<<endl;
	return 0;
}