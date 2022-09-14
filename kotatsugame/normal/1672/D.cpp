#include<iostream>
using namespace std;
int T,N;
int A[2<<17],B[2<<17];
int usd[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		for(int i=1;i<=N;i++)usd[i]=0;
		int bi=N-1,i=N-1;
		for(;i>=0;)
		{
			if(A[i]==B[bi])
			{
				bi--;
				i--;
			}
			else if(bi+1<N&&B[bi+1]==B[bi])
			{
				usd[B[bi]]++;
				bi--;
			}
			else if(usd[A[i]]>0)
			{
				usd[A[i]]--;
				i--;
			}
			else break;
		}
		cout<<(i>=0||bi>=0?"NO\n":"YES\n");
	}
}