#include<iostream>
using namespace std;
int T,N,M;
int cnt[50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<M;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int a;cin>>a;cnt[a-1]++;
		}
		string ans(M,'B');
		for(int i=0;i<M;i++)
		{
			if(cnt[i]>0)
			{
				ans[i]='A';
				cnt[i]--;
			}
			else if(cnt[M-i-1]>0)
			{
				ans[i]='A';
				cnt[M-i-1]--;
			}
		}
		cout<<ans<<"\n";
	}
}