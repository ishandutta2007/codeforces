#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
int N,A[1<<17],B[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		B[0]=A[0];
		for(int i=1;i<N;i++)B[i]=A[i-1]/gcd(A[i-1],A[i])*A[i];
		B[N]=A[N-1];
		bool ok=true;
		for(int i=0;i<N;i++)if(A[i]!=gcd(B[i],B[i+1]))ok=false;
		cout<<(ok?"YES\n":"NO\n");
	}
}