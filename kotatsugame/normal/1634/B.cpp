#include<iostream>
using namespace std;
int T,N,X;
long long Y;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>X>>Y;
		int oc=X%2;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;
			oc+=a%2;
		}
		oc+=Y%2;
		cout<<(oc%2==0?"Alice\n":"Bob\n");
	}
}