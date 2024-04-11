#include<iostream>
using namespace std;
int T;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a+b+c+d==0)cout<<"0\n";
		else if(a+b+c+d==4)cout<<"2\n";
		else cout<<"1\n";
	}
}