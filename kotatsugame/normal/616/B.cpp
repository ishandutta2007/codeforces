#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
main()
{
	int ans=0;
	cin>>N>>M;
	for(int i=0;i<N;i++)
	{
		int mn=1e9;
		for(int j=0;j<M;j++)
		{
			int t;cin>>t;
			if(mn>t)mn=t;
		}
		if(ans<mn)ans=mn;
	}
	cout<<ans<<endl;
}