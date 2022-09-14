#include<iostream>
#include<algorithm>
using namespace std;
int t;
main()
{
	cin>>t;
	for(;t--;)
	{
		int n,x,y;cin>>n>>x>>y;
		cout<<min(max(x+y+1-n,1),n)<<" "<<min(x+y-1,n)<<endl;
	}
}