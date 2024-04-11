#include<iostream>
using namespace std;
int T,N;
int S[2<<17],F[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>S[i];
		for(int i=0;i<N;i++)cin>>F[i];
		int prv=0;
		for(int i=0;i<N;i++)
		{
			if(prv<S[i])prv=S[i];
			cout<<F[i]-prv<<(i+1==N?"\n":" ");
			prv=F[i];
		}
	}
}