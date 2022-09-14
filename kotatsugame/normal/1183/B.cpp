#include<iostream>
#include<algorithm>
using namespace std;
int Q;
main()
{
	cin>>Q;
	for(;Q--;)
	{
		int N,K;cin>>N>>K;
		int L=1,R=1e9;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			L=max(L,a-K);
			R=min(R,a+K);
		}
		cout<<(L<=R?R:-1)<<endl;
	}
}