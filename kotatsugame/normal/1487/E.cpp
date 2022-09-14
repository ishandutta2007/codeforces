#line 1 "a.cpp"
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#line 2 "/home/kotatsugame/library/datastructure/dualsegtree.cpp"
#include<functional>
template<typename T>
struct dualsegtree{
	using F=function<T(T,T)>;
	const F lazycalcfn,updatefn;
	int n;
	T lazydefvalue;
	vector<T>dat,lazy;
	vector<bool>lazyflag;
	dualsegtree(int n_=0,T defvalue=0,
		const F lazycalcfn_=[](T a,T b){return a+b;},
		const F updatefn_=[](T a,T b){return a+b;},
		T lazydefvalue_=0
	):lazydefvalue(lazydefvalue_),
		lazycalcfn(lazycalcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(n,defvalue);
		lazy.assign(n-1,lazydefvalue);
		lazyflag.assign(n-1,false);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i]=v[i];
		lazy.assign(n-1,lazydefvalue);
		lazyflag.assign(n-1,false);
	}
	void update(int a,int b,T x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			if(k<n-1)
			{
				lazy[k]=lazycalcfn(lazy[k],x);
				lazyflag[k]=true;
			}
			else dat[k-n+1]=updatefn(dat[k-n+1],x);
		}
		else
		{
			if(lazyflag[k])
			{
				update(0,n,lazy[k],k*2+1,l,(l+r)/2);
				update(0,n,lazy[k],k*2+2,(l+r)/2,r);
				lazy[k]=lazydefvalue;
				lazyflag[k]=false;
			}
			update(a,b,x,k*2+1,l,(l+r)/2);
			update(a,b,x,k*2+2,(l+r)/2,r);
		}
	}
	T query(int i)
	{
		T ret=dat[i];
		i+=n-1;
		while(i>0)
		{
			i=(i-1)/2;
			if(lazyflag[i])ret=updatefn(ret,lazy[i]);
		}
		return ret;
	}
};
#line 6 "a.cpp"
vector<int>calc(int N,int M,vector<int>st,vector<pair<int,int> >E)
{
	vector<vector<int> >G(N);
	for(pair<int,int>e:E)G[e.first].push_back(e.second);
	dualsegtree<int>P(M,(int)1e9,[](int a,int b){return a<b?a:b;},[](int a,int b){return a<b?a:b;},(int)1e9);
	for(int i=0;i<N;i++)
	{
		sort(G[i].begin(),G[i].end());
		int prv=0;
		for(int v:G[i])
		{
			if(prv<v)
			{
				P.update(prv,v,st[i]);
			}
			prv=v+1;
		}
		if(prv<M)P.update(prv,M,st[i]);
	}
	vector<int>ret(M);
	for(int i=0;i<M;i++)ret[i]=P.query(i);
	return ret;
}
main()
{
	int N[4];
	for(int i=0;i<4;i++)scanf("%d",&N[i]);
	vector<int>A[4];
	for(int i=0;i<4;i++)
	{
		A[i].assign(N[i],0);
		for(int j=0;j<N[i];j++)scanf("%d",&A[i][j]);
	}
	int M[3];
	vector<pair<int,int> >B[3];
	for(int i=0;i<3;i++)
	{
		scanf("%d",&M[i]);
		B[i].assign(M[i],make_pair(0,0));
		for(int j=0;j<M[i];j++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			B[i][j]=make_pair(u,v);
		}
	}
	vector<int>X=calc(N[0],N[1],A[0],B[0]);
	for(int i=0;i<N[1];i++)X[i]+=A[1][i];
	vector<int>Y=calc(N[1],N[2],X,B[1]);
	for(int i=0;i<N[2];i++)Y[i]+=A[2][i];
	vector<int>Z=calc(N[2],N[3],Y,B[2]);
	int ans=1e9;
	for(int i=0;i<N[3];i++)
	{
		Z[i]+=A[3][i];
		ans=min(ans,Z[i]);
	}
	if(ans==(int)1e9)ans=-1;
	printf("%d\n",ans);
}