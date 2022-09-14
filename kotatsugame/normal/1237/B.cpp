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
int invA[1<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int A;scanf("%d",&A);A--;
		invA[A]=i;
	}
	int ans=0;
	BIT<int>P(N);
	for(int i=0;i<N;i++)
	{
		int B;scanf("%d",&B);B--;
		ans+=P.sum(invA[B])<invA[B];
		P.add(invA[B]+1,1);
	}
	printf("%d\n",ans);
}