#include<iostream>
using namespace std;
int T,N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int b=1;
		while(b*2<N)b*=2;
		for(int i=b-1;i>=0;i--)cout<<i<<" ";
		for(int i=b;i<N;i++)cout<<i<<(i+1==N?"\n":" ");
	}
}