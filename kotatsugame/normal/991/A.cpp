#include<iostream>
using namespace std;
int a,b,c,n;
main()
{
	cin>>a>>b>>c>>n;
	if(a<c||b<c||n<a||n<b)cout<<-1<<endl;
	else
	{
		n-=a-c+b-c+c;
		if(n<1)cout<<-1<<endl;
		else cout<<n<<endl;
	}
}