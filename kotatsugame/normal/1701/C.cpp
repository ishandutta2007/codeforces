#include<iostream>
using namespace std;
int T,N,M;
int cnt[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		for(int i=0;i<N;i++)cnt[i]=0;
		for(int i=0;i<M;i++)
		{
			int a;cin>>a;
			cnt[a-1]++;
		}
		int l=0,r=M;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			int rest=0;
			for(int i=0;i<N;i++)if(cnt[i]>mid)rest+=cnt[i]-mid;
			for(int i=0;rest>0&&i<N;i++)if(cnt[i]<=mid)rest-=(mid-cnt[i])/2;
			if(rest<=0)r=mid;
			else l=mid;
		}
		cout<<r<<"\n";
	}
}