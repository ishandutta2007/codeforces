#line 1 "a.cpp"
#include<cstdio>
#include<queue>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/BIT.cpp"
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
#line 5 "a.cpp"
int N,M;
char S[3000][3003];
int L[3000][3000],D[3000][3000];
main()
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)scanf("%s",S[i]);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(S[i][j]=='.')L[i][j]=0;
			else L[i][j]=j==0?1:L[i][j-1]+1;
		}
	}
	for(int i=N;i--;)
	{
		for(int j=0;j<M;j++)
		{
			if(S[i][j]=='.')D[i][j]=0;
			else D[i][j]=i==N-1||j==0?1:D[i+1][j-1]+1;
		}
	}
	long long ans=0;
	for(int j=0;j<M;j++)
	{
		BIT<int>P(N);
		priority_queue<pair<int,int> >Q;
		for(int i=N;i--;)
		{
			P.add(i+1,1);
			Q.push(make_pair(i-L[i][j]+1,i));
			while(!Q.empty()&&Q.top().first>i)
			{
				P.add(Q.top().second+1,-1);
				Q.pop();
			}
			int u=D[i][j];
			if(u>L[i][j])u=L[i][j];
			ans+=P.sum(i+u);
		}
	}
	printf("%lld\n",ans);
}