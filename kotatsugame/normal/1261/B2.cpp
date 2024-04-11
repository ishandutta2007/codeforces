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
int N,M;
int A[2<<17];
vector<pair<int,int> >Q[2<<17];
int ans[2<<17];
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >B(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&A[i]);
		B[i]=make_pair(-A[i],i);
	}
	sort(B.begin(),B.end());
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int k,p;scanf("%d%d",&k,&p);
		Q[k-1].push_back(make_pair(p,i));
	}
	BIT<int>P(N);
	for(int i=0;i<N;i++)
	{
		P.add(B[i].second+1,1);
		for(pair<int,int>q:Q[i])
		{
			int id=P.lower_bound(q.first);
			ans[q.second]=A[id-1];
		}
	}
	for(int i=0;i<M;i++)
	{
		printf("%d\n",ans[i]);
	}
}