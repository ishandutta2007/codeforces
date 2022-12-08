#include <bits/stdc++.h>
#define int long long
using namespace std;

int inclusion=0;

int gt[300005];
pair<int, int> a[300005];
signed main()
{
	gt[0]=1;
	int n;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		gt[i]=gt[i-1]*i;
		gt[i]%=998244353;
		cin>>a[i].first>>a[i].second;
	}
	inclusion+=gt[n];
	sort(a+1, a+n+1);
	a[n+1].first=-1;
	int cnt=0;
	int cacc=1;
	for(int i=1; i<=n+1; i++)
	{
		if(a[i].first!=a[i-1].first&&i!=1)
		{
//			cout<<cnt<<endl;
			cacc*=gt[cnt];
			cacc%=998244353;
			cnt=0;
		}
		cnt++;
	}
	for(int i=1; i<=n; i++)
	{
		swap(a[i].first, a[i].second);
	}
//	cout<<cacc<<" SA"<<endl;
	inclusion-=cacc;
	inclusion=(inclusion+998244353)%998244353;
	int exclusion=1;
	bool can=true;
	cacc=1;
	int ccnt=0;
	cnt=0;
	a[n+1].second=100000000;
	sort(a+1, a+n+1);
	for(int i=1; i<=n+1; i++)
	{
		if(a[i].first!=a[i-1].first&&i!=1)
		{
//			cout<<cnt<<endl;
			cacc*=gt[cnt];
			cacc%=998244353;
			cnt=0;
		}
		if(a[i]!=a[i-1]&&i!=1)
		{
			exclusion*=gt[ccnt];
			exclusion%=998244353;
			ccnt=0;
		}
		if(a[i].second<a[i-1].second) can=false;
		cnt++;
		ccnt++;
	}
//	cout<<cacc<<" SA"<<endl;
//	cout<<exclusion<<endl;
	inclusion-=cacc;
	inclusion=(inclusion+998244353)%998244353;
	cout<<(inclusion+exclusion*can+998244353)%998244353;
}