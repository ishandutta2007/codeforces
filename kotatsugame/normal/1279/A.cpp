#include<iostream>
#include<algorithm>
using namespace std;
int t;
main()
{
	cin>>t;
	for(;t--;)
	{
		int r,g,b;cin>>r>>g>>b;
		if(r<g)swap(r,g);
		if(r<b)swap(r,b);
		if(r>g+b+1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
}