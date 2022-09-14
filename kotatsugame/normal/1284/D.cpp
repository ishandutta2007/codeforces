#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
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
bool check(vector<pair<pair<int,int>,pair<int,int> > >X)
{
	sort(X.begin(),X.end());
	vector<int>x;
	for(int i=0;i<N;i++)
	{
		x.push_back(X[i].second.first);
		x.push_back(X[i].second.second);
	}
	sort(x.begin(),x.end());
	x.erase(unique(x.begin(),x.end()),x.end());
	BIT<int>B(x.size()+5),E(x.size()+5);
	priority_queue<pair<int,pair<int,int> > >P;
	for(int i=0;i<N;i++)
	{
		while(!P.empty()&&-P.top().first<X[i].first.first)
		{
			pair<int,int>p=P.top().second;
			B.add(p.first,-1);
			E.add(p.second,-1);
			P.pop();
		}
		pair<int,int>now;
		now.first=lower_bound(x.begin(),x.end(),X[i].second.first)-x.begin()+1;
		now.second=lower_bound(x.begin(),x.end(),X[i].second.second)-x.begin()+1;
		if(B.sum(x.size()+5)-B.sum(now.second)>0)return true;
		if(E.sum(now.first-1)>0)return true;
		B.add(now.first,1);
		E.add(now.second,1);
		P.push(make_pair(-X[i].first.second,now));
	}
	return false;
}
main()
{
	scanf("%d",&N);
	vector<pair<int,int> >A(N),B(N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d%d%d",&A[i].first,&A[i].second,&B[i].first,&B[i].second);
	}
	vector<pair<pair<int,int>,pair<int,int> > >X(N),Y(N);
	for(int i=0;i<N;i++)
	{
		X[i]=make_pair(A[i],B[i]);
		Y[i]=make_pair(B[i],A[i]);
	}
	puts(check(X)||check(Y)?"NO":"YES");
}