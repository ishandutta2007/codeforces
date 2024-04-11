#include<iostream>
#include<algorithm>
using namespace std;
int T,N,H[3<<17];
long long cnt(long long c1,long long c2)
{
	if(c1>c2)return c1*2-1;
	else return c2*2;
}
long long solve(int TH)
{
	long long c1=0,c2=0;
	for(int i=0;i<N;i++)
	{
		int need=TH-H[i];
		c2+=need/2;
		c1+=need%2;
	}
	long long d=c2-c1;
	if(d<=0)return cnt(c1,c2);
	c2-=d/3;
	c1+=d/3*2;
	long long ret=cnt(c1,c2);
	if(c2>0)
	{
		c2--;
		c1+=2;
		ret=min(ret,cnt(c1,c2));
	}
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int mh=0;
		for(int i=0;i<N;i++)
		{
			cin>>H[i];
			mh=max(mh,H[i]);
		}
		cout<<min(solve(mh),solve(mh+1))<<"\n";
	}
}