#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
#include<vector>
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
	vector<int>X(N);
	vector<pair<int,int> >vs(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&X[i]);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",&vs[i].first);
		vs[i].second=X[i];
	}
	sort(X.begin(),X.end());
	sort(vs.begin(),vs.end());reverse(vs.begin(),vs.end());
	BIT<long long>P(N);
	BIT<int>cnt(N);
	long long ans=0;
	for(pair<int,int>p:vs)
	{
		int v=p.first,x=p.second;
		int id=lower_bound(X.begin(),X.end(),x)-X.begin()+1;
		ans+=P.sum(N)-P.sum(id)-(long long)x*(cnt.sum(N)-cnt.sum(id));
		cnt.add(id,1);
		P.add(id,x);
	}
	printf("%lld\n",ans);
}