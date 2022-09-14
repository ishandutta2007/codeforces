#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
pair<int,int>cnt[500];
main()
{
	cin>>N>>K;
	for(int i=0;i<N;i++)cnt[i]=make_pair(-1,i+1);
	int st=0,mx=1;
	for(int l=0;l<1<<17;l++)
	{
		if((N+2*l)%K==0&&(N+2*l)/K>=mx)
		{
			int ans=0;
			int t=(N+2*l)/K;
			for(int i=0;i<t;i++)
			{
				cout<<"?";
				sort(cnt,cnt+N);
				for(int j=0;j<K;j++)
				{
					cnt[j].first++;
					cout<<" "<<cnt[j].second;
				}
				cout<<endl;
				int x;cin>>x;ans^=x;
			}
			cout<<"! "<<ans<<endl;
			return 0;
		}
		cnt[st].first-=2;
		if(mx<-cnt[st].first)mx=-cnt[st].first;
		st=(st+1)%N;
	}
	cout<<-1<<endl;
}