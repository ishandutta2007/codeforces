#include<iostream>
#include<algorithm>
using namespace std;
int T,N,H[200];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		int x;
		cin>>N>>x;
		for(int i=0;i<2*N;i++)cin>>H[i];
		sort(H,H+2*N);
		bool ok=true;
		for(int i=0;i<N;i++)if(H[i]+x>H[i+N])ok=false;
		cout<<(ok?"YES\n":"NO\n");
	}
}