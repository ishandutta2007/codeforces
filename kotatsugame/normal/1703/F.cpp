#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		vector<int>ids;
		for(int i=0;i<N;i++)if(A[i]<i+1)ids.push_back(i+1);
		long long ans=0;
		for(int id:ids)
		{
			int a=A[id-1];
			ans+=lower_bound(ids.begin(),ids.end(),a)-ids.begin();
		}
		cout<<ans<<"\n";
	}
}