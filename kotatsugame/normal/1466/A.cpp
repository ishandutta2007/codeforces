#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,X[50];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>X[i];
		vector<int>ans;
		for(int i=0;i<N;i++)for(int j=i+1;j<N;j++)
		{
			ans.push_back(X[j]-X[i]);
		}
		sort(ans.begin(),ans.end());
		ans.erase(unique(ans.begin(),ans.end()),ans.end());
		cout<<ans.size()<<endl;
	}
}