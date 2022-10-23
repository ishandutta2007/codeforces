#include<iostream>
#include<algorithm>
using namespace std;
int N,A[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		sort(A,A+N);
		bool ok=true;
		for(int i=1;i<N;i++)if(A[i-1]==A[i])ok=false;
		cout<<(ok?"YES\n":"NO\n");
	}
}