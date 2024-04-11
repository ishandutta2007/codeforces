#include<iostream>
using namespace std;
int N,A[2<<17],B[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		bool ok=true;
		for(int i=0;i<N;i++)if(B[i]<A[i])ok=false;
		for(int i=0;i<N;i++)if(A[i]<B[i]&&B[i]>B[(i+1)%N]+1)ok=false;
		cout<<(ok?"YES\n":"NO\n");
	}
}