#include<cstdio>
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
int N,Q;
int A[3<<17];
int ans[3<<17];
vector<pair<int,int> >q[3<<17];
vector<int>ad[3<<17];
main()
{
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=0;i<Q;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		q[x].push_back(make_pair(i,N-y));
	}
	BIT<int>fst(N);
	for(int i=1;i<=N;i++)
	{
		int t=i-A[i-1];
		if(t<0)continue;
		int K=fst.sum(i-1)-t;
		if(K<0)continue;
		int L=1,R=i+1;
		while(R-L>1)
		{
			int mid=L+R>>1;
			if(fst.sum(mid-1)<=K)L=mid;
			else R=mid;
		}
		ad[L-1].push_back(i);
		fst.add(L,1);
	}
	BIT<int>snd(N);
	for(int i=N;i--;)
	{
		for(int j:ad[i])snd.add(j,1);
		for(pair<int,int>p:q[i])
		{
			ans[p.first]=snd.sum(p.second);
		}
	}
	for(int i=0;i<Q;i++)printf("%d\n",ans[i]);
}