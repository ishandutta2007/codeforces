#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int cnt[2<<17];
int rest[2<<17];
main()
{
	cin>>T;
	{
		int z=1;
		for(int i=0;i<2<<17;i++)
		{
			if(i>z)z*=2;
			rest[i]=z-i;
		}
	}
	for(;T--;)
	{
		cin>>N;
		for(int i=1;i<=N;i++)cnt[i]=0;
		for(int i=0;i<N;i++)
		{
			int A;cin>>A;
			cnt[A]++;
		}
		vector<int>now;
		for(int i=1;i<=N;i++)if(cnt[i]>0)now.push_back(cnt[i]);
		int ans=1e9;
		int li=0,Ls=0;
		for(int i=0;;i++)
		{
			while(li<now.size()&&Ls+now[li]<=1<<i)Ls+=now[li++];
			int ri=now.size()-1,Rs=0;
			for(int j=0;;j++)
			{
				while(ri>=li&&Rs+now[ri]<=1<<j)Rs+=now[ri--];
				ans=min(ans,(1<<i)-Ls+(1<<j)-Rs+rest[N-Ls-Rs]);
				if(ri<li)break;
			}
			if(li==now.size())break;
		}
		cout<<ans<<"\n";
	}
}