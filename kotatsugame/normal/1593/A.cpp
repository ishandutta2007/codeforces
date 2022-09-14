#include<iostream>
#include<algorithm>
using namespace std;
int T;
int a,b,c;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>a>>b>>c;
		cout<<max({0,b-a+1,c-a+1})<<" "<<max({a-b+1,0,c-b+1})<<" "<<max({a-c+1,b-c+1,0})<<"\n";
	}
}