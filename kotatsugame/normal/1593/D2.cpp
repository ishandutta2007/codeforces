#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A[40];
int cnt[2<<20],vis[2<<20];
main()
{
	cin>>T;
	int tm=0;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			A[i]+=1000000;
		}
		int g;
		for(g=2<<20;g>0;g--)
		{
			int mx=0;
			tm++;
			for(int i=0;i<N;i++)
			{
				int x=A[i]%g;
				if(vis[x]<tm)vis[x]=tm,cnt[x]=0;
				if(mx<++cnt[x])mx=cnt[x];
			}
			if(mx*2>=N)
			{
				break;
			}
		}
		if(g==(2<<20))g=-1;
		cout<<g<<"\n";
	}
}