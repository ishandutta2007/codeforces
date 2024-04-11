#include<iostream>
using namespace std;
int T,N;
int W[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>W[i];
		int ans=0;
		int r=N;
		int ls=0,rs=0;
		for(int l=0;l<N;l++)
		{
			ls+=W[l];
			while(rs<ls)rs+=W[--r];
			if(ls==rs&&l<r)ans=l+1+N-r;
		}
		cout<<ans<<"\n";
	}
}