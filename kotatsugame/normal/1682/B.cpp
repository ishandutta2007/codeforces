#include<iostream>
using namespace std;
int T,N;
int P[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int A=-1;
		for(int i=0;i<N;i++)
		{
			cin>>P[i];
			if(i!=P[i])A&=P[i];
		}
		cout<<A<<"\n";
	}
}