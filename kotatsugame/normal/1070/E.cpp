#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
//1-indexed
#include<vector>
template<typename T>
struct BIT{
	int n;
	vector<T>bit;
	BIT(int n_=0):n(n_),bit(n_+1){}
	T sum(int i)
	{
		T ans=0;
		for(;i>0;i-=i&-i)ans+=bit[i];
		return ans;
	}
	void add(int i,T a)
	{
		if(i==0)return;
		for(;i<=n;i+=i&-i)bit[i]+=a;
	}
	int lower_bound(T k)//k<=sum(ret)
	{
		if(k<=0)return 0;
		int ret=0,i=1;
		while((i<<1)<=n)i<<=1;
		for(;i;i>>=1)
			if(ret+i<=n&&bit[ret+i]<k)k-=bit[ret+=i];
		return ret+1;
	}
};
int testcases,N,M;
long long T;
main()
{
	scanf("%d",&testcases);
	for(;testcases--;)
	{
		scanf("%d%d%lld",&N,&M,&T);
		vector<pair<int,int> >P(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&P[i].first);
			P[i].second=i+1;
		}
		sort(P.begin(),P.end());
		int ans=-1,ansd;
		BIT<long long>TM(N);
		BIT<int>cnt(N);
		for(int i=0;i<N;)
		{
			int j=i;
			while(j<N&&P[i].first==P[j].first)
			{
				TM.add(P[j].second,P[j].first);
				cnt.add(P[j].second,1);
				j++;
			}
			int r=TM.lower_bound(T/2+1)-1;
			int ok=cnt.sum(r)/M*M;
			int beg=cnt.lower_bound(ok);
			long long nT=T-TM.sum(beg);
			r=TM.lower_bound(nT+1)-1;
			int nowans=cnt.sum(r);
			if(ok+M<nowans)nowans=ok+M;
			if(ans<nowans)
			{
				ans=nowans;
				ansd=P[i].first;
			}
			i=j;
		}
		printf("%d %d\n",ans,(int)min((long long)ansd,T));
	}
}