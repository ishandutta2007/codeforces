#include<iostream>
using namespace std;
int T,N,S;
int A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		for(int i=0;i<N;i++)cin>>A[i];
		int l=0,ans=-1;
		for(int r=0;r<N;r++)
		{
			S-=A[r];
			while(S<0)
			{
				S+=A[l++];
			}
			if(S==0)ans=max(ans,r-l+1);
		}
		cout<<(ans==-1?-1:N-ans)<<"\n";
	}
}