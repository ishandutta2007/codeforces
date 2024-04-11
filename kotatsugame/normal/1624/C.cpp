#include<iostream>
using namespace std;
int T,N,A[50];
int cnt[51];
bool usd[51];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)cnt[i]=0,usd[i]=false;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			int a=A[i];
			while(a>=1)
			{
				if(a<=N)cnt[a]++;
				a/=2;
			}
		}
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			int a=A[i];
			int mn=N+1;
			while(a>=1)
			{
				if(a<=N&&!usd[a])
				{
					if(mn==N+1||cnt[mn]>cnt[a])mn=a;
				}
				a/=2;
			}
			if(mn==N+1)
			{
				ok=false;
				break;
			}
			usd[mn]=true;
			a=A[i];
			while(a>=1)
			{
				if(a<=N)cnt[a]--;
				a/=2;
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}