#include<iostream>
#include<vector>
#include<cstdio>
#include<time.h>
#include<algorithm>
#include<set>
#include<random>
using namespace std;
int n;
long long L=-1,R=1000000000;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
set<int>used;
main()
{
	mt19937 e((int)time(NULL));
	cin>>n;
	if(n<=60)
	{
		vector<int>a;
		for(int i=1;i<=n;i++)
		{
			cout<<"? "<<i<<endl;
			int r;cin>>r;a.push_back(r);
		}
		sort(a.begin(),a.end());
		cout<<"! "<<a[0]<<" "<<a[1]-a[0]<<endl;
		return 0;
	}
	int cnt=0;
	while(R-L>1)
	{
		long long mid=(L+R+1)/2;
		cout<<"> "<<mid<<endl;
		int r;
		cin>>r;
		cnt++;
		if(r)L=mid;
		else R=mid;
	}
	vector<long long>a;
	cnt=60-cnt;
	for(int i=0;i<cnt;i++)
	{
		int I=e()%n+1;
		while(used.find(I)!=used.end())
		{
			I=e()%n+1;
		}
		cout<<"? "<<I<<endl;
		int r;cin>>r;
		a.push_back(R-r);
		used.insert(I);
	}
	long long g=0;
	for(int i=0;i<a.size();i++)
	{
		g=gcd(a[i],g);
	}
	if(R-g*(n-1)>=0)cout<<"! "<<R-g*(n-1)<<" "<<g<<endl;
	else
	{
		for(long long i=2;i*i<=g;i++)
		{
			if(g%i==0)
			{
				g/=i;
				cout<<"! "<<R-g*(n-1)<<" "<<g<<endl;
				return 0;
			}
		}
		g=1;
		cout<<"! "<<R-g*(n-1)<<" "<<g<<endl;
	}
	return 0;
}