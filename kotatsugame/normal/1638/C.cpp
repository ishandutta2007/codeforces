#include<iostream>
using namespace std;
int T,N;
int P[1<<17];
int Lmax[1<<17],Rmin[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>P[i];
		Lmax[0]=0;
		for(int i=0;i<N;i++)Lmax[i+1]=max(Lmax[i],P[i]);
		Rmin[N]=N+1;
		for(int i=N;i--;)Rmin[i]=min(Rmin[i+1],P[i]);
		int ans=1;
		for(int i=0;i<N-1;i++)
		{
			if(Lmax[i+1]<Rmin[i+1])ans++;
		}
		cout<<ans<<"\n";
	}
}