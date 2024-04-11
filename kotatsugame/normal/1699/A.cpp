#include<iostream>
using namespace std;
int T,N;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		if(N%2==0)cout<<N/2<<" "<<N/2<<" 0\n";
		else cout<<"-1\n";
	}
}