#include<iostream>
using namespace std;
int T,a,b,c;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>a>>b>>c;
		if(a>b)
		{
			int x=a;a=b;b=x;
		}
		int w=b-a;
		if(2*w<b||2*w<c)cout<<-1<<endl;
		else cout<<(c<=w?c+w:c-w)<<endl;
	}
}