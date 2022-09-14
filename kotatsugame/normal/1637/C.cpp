#include<iostream>
#include<vector>
using namespace std;
int T,N,A[1<<17];
vector<int>one,two;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		long long ans=0;
		one.clear();
		two.clear();
		for(int i=1;i<N-1;i++)
		{
			ans+=(A[i]+1)/2;
			if(A[i]%2==1)one.push_back(i);
			if(A[i]>=2)two.push_back(i);
		}
		if(one.empty())cout<<ans<<"\n";
		else if(two.empty())cout<<"-1\n";
		else if(one.size()>=2||two.size()>=2)cout<<ans<<"\n";
		else if(one[0]!=two[0])cout<<ans<<"\n";
		else cout<<"-1\n";
	}
}