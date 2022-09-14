#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
main()
{
	cin>>N;
	vector<int>A,B;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		if(a%2)B.push_back(a);
		else A.push_back(a);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	if(A.size()==B.size())cout<<0<<endl;
	else if(A.size()>B.size())
	{
		int ans=0;
		for(int i=0;i<A.size()-B.size()-1;i++)ans+=A[i];
		cout<<ans<<endl;
	}
	else
	{
		int ans=0;
		for(int i=0;i<B.size()-A.size()-1;i++)ans+=B[i];
		cout<<ans<<endl;
	}
}