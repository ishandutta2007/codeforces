#include<iostream>
#include<queue>
using namespace std;
int N,K;
long long B[3<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>B[i];
	queue<pair<int,long long> >P;long long Psum=0,sum=0;
	long long ans=0;
	for(int i=N;i--;)
	{
		sum-=Psum;
		if(!P.empty()&&P.front().first-K>=i)
		{
			pair<int,long long>p=P.front();
			P.pop();
			Psum-=p.second;
		}
		B[i]-=sum;
		if(i>=K&&B[i]>0)
		{
			long long t=(B[i]+K-1)/K;
			P.push(make_pair(i,t));
			Psum+=t;
			sum+=t*K;
			B[i]-=t*K;
			ans+=t;
		}
	}
	long long mx=0;
	for(int i=0;i<K;i++)if(B[i]>0)mx=max(mx,(B[i]+i)/(i+1));
	cout<<ans+mx<<endl;
}