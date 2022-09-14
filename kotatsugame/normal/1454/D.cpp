#include<cstdio>
#include<vector>
using namespace std;
int T;
long long N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%lld",&N);
		long long N_=N;
		vector<pair<long long,int> >X;
		int len=0;
		for(long long i=2;i*i<=N;i++)if(N%i==0)
		{
			X.push_back(make_pair(i,0));
			while(N%i==0)
			{
				X.back().second++;
				N/=i;
			}
			if(len<X.back().second)
			{
				len=X.back().second;
			}
		}
		if(N>1)
		{
			X.push_back(make_pair(N,1));
			if(len<1)len=1;
		}
		vector<long long>ans(len,1);
		for(pair<long long,int>p:X)
		{
			int c=p.second;
			long long q=p.first;
			for(int i=0;i<c;i++)ans[len-i-1]*=q;
		}
		printf("%d\n",(int)ans.size());
		for(int i=0;i<len;i++)printf("%lld%c",ans[i],i+1==len?10:32);
	}
}