#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N,L,R,K;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>L>>R>>K;
		vector<int>A;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			if(L<=a&&a<=R)A.push_back(a);
		}
		sort(A.begin(),A.end());
		int cnt=0;
		for(int a:A)
		{
			if(K>=a)K-=a,cnt++;
		}
		cout<<cnt<<"\n";
	}
}