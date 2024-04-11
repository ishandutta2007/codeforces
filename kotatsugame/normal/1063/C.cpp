#include<iostream>
using namespace std;
int N;
bool ask(int x,int y)
{
	cout<<x<<" "<<y<<endl;
	string s;cin>>s;
	return s=="black";
}
main()
{
	cin>>N;
	bool O=ask(0,1);
	int L=0,R=1e9;
	for(int i=1;i<N;i++)
	{
		int mid=(L+R)/2;
		bool now=ask(mid,1);
		if(O==now)L=mid;
		else R=mid;
	}
	cout<<L<<" "<<0<<" "<<R<<" "<<2<<endl;
}