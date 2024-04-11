#include<iostream>
using namespace std;
int cnt[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		cnt[0]=0;
		for(int i=0;i<N;i++)
		{
			int A;
			cin>>A;
			cnt[i+1]=cnt[i]+A;
		}
		int ans=N-1;
		for(int i=0;i<=N;i++)
		{
			int x=cnt[i]-cnt[0];
			int y=(N-i)-(cnt[N]-cnt[i]);
			if(x>=y)ans=min(ans,x);
			else ans=min(ans,y);
		}
		cout<<ans<<"\n";
	}
}