#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long n,a[111111];
pair<long long,long long> b[111111];
long long l,r,ans,cnt,po[32];
int main()
{
	//freopen("cin.in","r",stdin);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for (int i=0;i<n;i++)
	{
		if (!i) 
		{
			b[0].first=a[i];
			b[0].second=1;
		}
		else if (a[i]==a[i-1])
		{
			b[cnt].second++;
		}
		else
		{
			cnt++;
			b[cnt].first=a[i];
			b[cnt].second=1;
		}
	}
	po[0]=1;
	for (int i=1;i<=31;i++) po[i]=po[i-1]*2;
	for (int i=1;i<=31;i++)
	{
		l=0;
		r=cnt;
		while(l<=r)
		{
			if (b[l].first+b[r].first==po[i]) 
			{
				if (b[l].first!=b[r].first) ans=ans+b[l].second*b[r].second;
				else ans=ans+b[l].second*(b[l].second-1)/2;
			}
			if (b[l].first+b[r].first>po[i]) r--;
			else l++;
		}
	}
	cout<<ans<<endl;
	return 0;
}