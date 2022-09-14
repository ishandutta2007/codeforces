#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f;
main()
{
	cin>>a>>b>>c>>d>>e>>f;
	a=abs(a-c);
	b=abs(b-d);
	if(a%e||b%f)cout<<"NO"<<endl;
	else
	{
		a/=e;
		b/=f;
		if((a+b)%2)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}