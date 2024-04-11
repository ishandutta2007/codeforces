#include<iostream>
#include<vector>
using namespace std;
int T;
vector<int>ans;
main()
{
	for(int i=1;ans.size()<1000;i++)
	{
		if(i%3!=0&&i%10!=3)ans.push_back(i);
	}
	cin>>T;
	for(;T--;)
	{
		int k;cin>>k;cout<<ans[k-1]<<endl;
	}
}