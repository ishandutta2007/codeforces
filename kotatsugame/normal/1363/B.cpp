#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
string S;
int L[1010],R[1010];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		N=S.size();
		L[0]=0;
		for(int i=0;i<N;i++)
		{
			L[i+1]=L[i];
			if(S[i]=='1')L[i+1]++;
		}
		R[N]=0;
		for(int i=N;i--;)
		{
			R[i]=R[i+1];
			if(S[i]=='1')R[i]++;
		}
		int ans=N;
		for(int i=0;i<=N;i++)
		{
			ans=min(ans,min(L[i]+(N-i-R[i]),(i-L[i])+R[i]));
		}
		cout<<ans<<"\n";
	}
}