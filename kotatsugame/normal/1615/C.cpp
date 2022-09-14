#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		string A,B;
		cin>>A>>B;
		int cnt[4]={};
		for(int i=0;i<N;i++)
		{
			int a=A[i]-'0',b=B[i]-'0';
			cnt[a*2+b]++;
		}
		int ans=1e9;
		if((cnt[0]+cnt[3])%2==1&&cnt[0]+1==cnt[3])
		{
			ans=min(ans,cnt[0]+cnt[3]);
		}
		if((cnt[1]+cnt[2])%2==0&&cnt[1]==cnt[2])
		{
			ans=min(ans,cnt[1]+cnt[2]);
		}
		if(ans==(int)1e9)ans=-1;
		cout<<ans<<"\n";
	}
}