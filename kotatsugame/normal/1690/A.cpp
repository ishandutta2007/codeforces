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
		if(N%3==0)
		{
			cout<<N/3<<" "<<N/3+1<<" "<<N/3-1<<"\n";
		}
		else if(N%3==1)
		{
			cout<<N/3<<" "<<N/3+2<<" "<<N/3-1<<"\n";
		}
		else
		{
			cout<<N/3+1<<" "<<N/3+2<<" "<<N/3-1<<"\n";
		}
	}
}