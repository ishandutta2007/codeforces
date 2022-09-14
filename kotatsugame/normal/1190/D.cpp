#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/BIT.cpp"
//1-indexed
#line 3 "/home/kotatsugame/library/datastructure/BIT.cpp"
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
#line 6 "a.cpp"
int N;
main()
{
	scanf("%d",&N);
	vector<int>xs(N),ys(N);
	vector<pair<int,int> >XY(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&XY[i].first,&XY[i].second);
		xs[i]=XY[i].first;
		ys[i]=XY[i].second;
	}
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	sort(ys.begin(),ys.end());
	ys.erase(unique(ys.begin(),ys.end()),ys.end());
	sort(XY.begin(),XY.end());
	BIT<int>P(ys.size());
	BIT<long long>Y(ys.size());
	long long ans=0;
	for(int i=0;i<N;)
	{
		int j=i;
		while(j<N&&XY[i].first==XY[j].first)j++;
		int my=XY[j-1].second;
		my=lower_bound(ys.begin(),ys.end(),my)-ys.begin();
		P.add(my+1,1);
		for(int k=i;k<j;k++)
		{
			int yi=lower_bound(ys.begin(),ys.end(),XY[k].second)-ys.begin();
			long long now=Y.sum(yi+1)-Y.sum(yi);
			Y.add(yi+1,-now);
			Y.add(yi+1,P.sum(ys.size())-P.sum(yi));
		}
		i=j;
		ans+=Y.sum(my+1);
	}
	printf("%lld\n",ans);
}