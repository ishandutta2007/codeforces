#include<iostream>
using namespace std;
int T,N;
int H[1<<17];
long long L[1<<17],R[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>H[i];
		if(N%2==1)
		{
			long long ans=0;
			for(int i=1;i<N;i+=2)
			{
				ans+=max(0,(max(H[i-1],H[i+1])+1)-H[i]);
			}
			cout<<ans<<"\n";
		}
		else
		{
			L[0]=0;
			for(int i=1;i+1<N;i++)
			{
				L[i]=L[i-1];
				if(i%2==1)L[i]+=max(0,(max(H[i-1],H[i+1])+1)-H[i]);
			}
			R[N-1]=0;
			for(int i=N-2;i>=1;i--)
			{
				R[i]=R[i+1];
				if(i%2==0)R[i]+=max(0,(max(H[i-1],H[i+1])+1)-H[i]);
			}
			long long ans=9e18;
			for(int i=0;i<N;i+=2)ans=min(ans,L[i]+R[i+1]);
			cout<<ans<<"\n";
		}
	}
}