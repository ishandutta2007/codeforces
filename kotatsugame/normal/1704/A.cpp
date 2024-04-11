#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N,M;
		cin>>N>>M;
		string A,B;
		cin>>A>>B;
		bool ok=true;
		for(int i=0;i<M-1;i++)if(B[M-i-1]!=A[N-i-1])ok=false;
		char to=B[0];
		bool fn=false;
		for(int i=0;i<=N-M;i++)if(A[i]==to)fn=true;
		cout<<(fn&&ok?"YES\n":"NO\n");
	}
}