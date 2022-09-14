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
int N,M;
int A[2<<17];
int B[2<<17];
long long f(int M)
{
	vector<int>vs;
	vs.push_back(0);
	for(int i=0;i<N;i++)
	{
		int a=B[i];
		a=a<=M?1:-1;
		A[i+1]=a+A[i];
		vs.push_back(A[i+1]);
	}
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(),vs.end()),vs.end());
	BIT<int>P(vs.size());
	long long ans=0;
	for(int i=0;i<=N;i++)
	{
		int a=lower_bound(vs.begin(),vs.end(),A[i])-vs.begin();
		ans+=P.sum(a+1);
		P.add(a+1,1);
	}
	return ans;
}
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%d",&B[i]);
	printf("%lld\n",f(M)-f(M-1));
}