#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		long long a,b,c,d;
		cin>>a>>b>>c>>d;
		a*=d;
		b*=c;
		if(a==b)cout<<"0\n";
		else
		{
			if(a==0||b==0)cout<<"1\n";
			else if(b%a==0||a%b==0)cout<<"1\n";
			else cout<<"2\n";
		}
	}
}