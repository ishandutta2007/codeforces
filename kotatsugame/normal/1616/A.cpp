#include<iostream>
using namespace std;
int t,n;
int cnt[101];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	for(;t--;)
	{
		cin>>n;
		for(int i=0;i<=100;i++)cnt[i]=0;
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int a;cin>>a;
			if(a<0)a=-a;
			if(cnt[a]==0)
			{
				cnt[a]=1;
				ans++;
			}
			else if(cnt[a]==1&&a>0)
			{
				cnt[a]=2;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
}