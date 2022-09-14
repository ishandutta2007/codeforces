#include<iostream>
#include<algorithm>
using namespace std;
int a,b,c,n;
main()
{
	cin>>n>>a>>b>>c;n--;
	if(n==0)cout<<0<<endl;
	else if(c<a&&c<b)
	{
		cout<<(n>0?min(a,b):0)+(--n*c)<<endl;
	}
	else cout<<(n*min(a,b))<<endl;
}