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
		int M;cin>>M;
		int p=1;
		while(p<=M/10)p*=10;
		cout<<M-p<<"\n";
	}
}