#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,b;
main()
{
	cin>>n>>b;
	vector<pair<long long,long long> >ba;
	for(long long i=2;i*i<=b;i++)
	{
		if(b%i==0)
		{
			ba.push_back(make_pair(i,0));
			while(b%i==0)
			{
				ba.back().second++;
				b/=i;
			}
		}
	}
	if(b>1)ba.push_back(make_pair(b,1));
	long long ans=9e18;
	for(int i=0;i<ba.size();i++)
	{
		long long now=n;
		long long cnt=0;
		long long base=ba[i].first;
		while(now/base>0)
		{
			cnt+=now/=base;
		}
		ans=min(ans,cnt/ba[i].second);
	}
	cout<<ans<<endl;
}