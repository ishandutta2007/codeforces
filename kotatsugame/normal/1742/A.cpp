#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int a,b,c;cin>>a>>b>>c;
		cout<<(a==b+c||b==a+c||c==a+b?"YES\n":"NO\n");
	}
}