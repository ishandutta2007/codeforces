#include<iostream>
using namespace std;
int T,N,M;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int Am=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			Am=max(Am,a);
		}
		cin>>M;
		int Bm=0;
		for(int i=0;i<M;i++)
		{
			int b;cin>>b;
			Bm=max(Bm,b);
		}
		cout<<(Am>=Bm?"Alice\n":"Bob\n");
		cout<<(Bm>=Am?"Bob\n":"Alice\n");
	}
}