#include<iostream>
using namespace std;
int T,a,b,c,d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>a>>b>>c>>d;
		cout<<(a<b)+(a<c)+(a<d)<<"\n";
	}
}