#include<iostream>
using namespace std;
int T,N,C;
bool vis[1<<20];
int cnt[1<<20];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>C;
		for(int i=1;i<=C;i++)
		{
			vis[i]=false;
			cnt[i]=0;
		}
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			vis[A]=true;
			cnt[A]=1;
		}
		for(int i=1;i<=C;i++)cnt[i]+=cnt[i-1];
		bool ok=true;
		for(int i=1;ok&&i<=C;i++)if(vis[i])
		{
			for(int k=1;i*k<=C;k++)
			{
				int l=i*k,r=i*k+i;
				if(r>C)r=C+1;
				if(cnt[r-1]>cnt[l-1]&&!vis[k])
				{
					ok=false;
					break;
				}
			}
		}
		cout<<(ok?"Yes\n":"No\n");
	}
}