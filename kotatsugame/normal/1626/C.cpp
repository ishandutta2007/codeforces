#include<iostream>
#include<stack>
using namespace std;
int T,N;
int K[100],H[100];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>K[i];
		for(int i=0;i<N;i++)cin>>H[i];
		stack<pair<int,int> >S;
		for(int i=0;i<N;i++)
		{
			pair<int,int>now=make_pair(K[i],H[i]);
			while(!S.empty())
			{
				pair<int,int>bk=S.top();
				if(now.first-bk.first>=now.second)break;
				else
				{
					now.second=max(now.second,now.first-bk.first+bk.second);
					S.pop();
				}
			}
			S.push(now);
		}
		long long ans=0;
		while(!S.empty())
		{
			long long h=S.top().second;
			S.pop();
			ans+=h*(h+1)/2;
		}
		cout<<ans<<"\n";
	}
}