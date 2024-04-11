#include<iostream>
#include<map>
#include<array>
using namespace std;
const long long m1=1e9+7,m2=1e9+6;
using dat=array<int,6>;
dat tmp;
main()
{
	int K;cin>>K;
	int p=((1LL<<K)-1)%m2;
	int N;
	cin>>N;
	map<long long,dat>mp;
	for(;N--;)
	{
		long long v;string s;
		cin>>v>>s;
		int now;
		if(s=="white")now=0;
		else if(s=="yellow")now=1;
		else if(s=="green")now=2;
		else if(s=="blue")now=3;
		else if(s=="red")now=4;
		else now=5;
		mp[v][now]=1;
	}
	long long a;
	while(!mp.empty())
	{
		p=(p+m2-1)%m2;
		auto it=mp.end();it--;
		pair<long long,dat>q=*it;
		mp.erase(it);
		long long nu=q.first/2;
		if(nu==0)
		{
			long long t=0;
			for(int i=0;i<6;i++)t+=q.second[i];
			a=t%m1;
		}
		else
		{
			for(int i=0;i<6;i++)tmp[i]=0;
			for(int i=0;i<6;i++)
			{
				for(int j=0;j<6;j++)if(i/2!=j/2)
				{
					tmp[j]+=q.second[i];
					tmp[j]%=m1;
				}
			}
			if(mp.find(nu)==mp.end())
			{
				mp[nu]=tmp;
			}
			else
			{
				for(int i=0;i<6;i++)mp[nu][i]=(long long)tmp[i]*mp[nu][i]%m1;
			}
		}
	}
	long long b=4;
	while(p)
	{
		if(p&1)a=a*b%m1;
		if(p>>=1)b=b*b%m1;
	}
	cout<<a<<endl;
}