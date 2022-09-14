#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,d;
main()
{
	cin>>a>>b>>c>>d;
	cout<<max(abs(a-c),abs(b-d))<<endl;
}