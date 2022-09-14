#include<iostream>
using namespace std;
int N,M;
int A[1<<17];
long long L[1<<17],R[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>M;
	for(int i=0;i<N;i++)cin>>A[i];
	L[0]=0;
	for(int i=1;i<N;i++)L[i]=L[i-1]+max(A[i-1]-A[i],0);
	R[N-1]=0;
	for(int i=N-1;i--;)R[i]=R[i+1]+max(A[i+1]-A[i],0);
	for(;M--;)
	{
		int s,t;cin>>s>>t;
		if(s<t)cout<<L[t-1]-L[s-1]<<"\n";
		else cout<<R[t-1]-R[s-1]<<"\n";
	}
}