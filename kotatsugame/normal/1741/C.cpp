#include<iostream>
using namespace std;
int N,A[2000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int ans=N;
		for(int i=1;i<=N;i++)
		{
			int t=0;
			for(int j=0;j<i;j++)t+=A[j];
			int k=i;
			int ret=i;
			while(k<N)
			{
				int now=0,cnt=0;
				while(k<N&&now<t)now+=A[k++],cnt++;
				if(now!=t)
				{
					ret=N;
					break;
				}
				ret=max(ret,cnt);
			}
			ans=min(ans,ret);
		}
		cout<<ans<<"\n";
	}
}