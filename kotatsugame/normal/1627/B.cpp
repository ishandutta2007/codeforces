#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,M;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		vector<int>ans;
		ans.reserve(N*M);
		for(int i=0;i<N;i++)for(int j=0;j<M;j++)
		{
			int d=max(i,N-i-1)+max(j,M-j-1);
			ans.push_back(d);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<N*M;i++)cout<<ans[i]<<(i+1==N*M?"\n":" ");
	}
}