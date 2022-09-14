#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
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
int N;
long long T,A[2<<17];
main()
{
	scanf("%d%lld",&N,&T);
	for(int i=0;i<N;i++)scanf("%lld",A+i);
	vector<long long>sum;
	sum.push_back(0);
	long long now=0;
	for(int i=0;i<N;i++)
	{
		now+=A[i];
		sum.push_back(now);
	}
	sort(sum.begin(),sum.end());
	sum.erase(unique(sum.begin(),sum.end()),sum.end());
	BIT<int>P(sum.size());
	now=0;
	long long ans=0;
	P.add(lower_bound(sum.begin(),sum.end(),0)-sum.begin()+1,1);
	for(int i=0;i<N;i++)
	{
		now+=A[i];
		int id=upper_bound(sum.begin(),sum.end(),now-T)-sum.begin();
		ans+=i+1-P.sum(id);
		P.add(lower_bound(sum.begin(),sum.end(),now)-sum.begin()+1,1);
	}
	printf("%lld\n",ans);
}