#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#include<vector>
#include<functional>
template<typename T>
struct lazysegtree{
	using F=function<T(T,T)>;
	using G=function<T(T,T,int,int)>;
	const F calcfn,lazycalcfn;
	const G updatefn;
	int n;
	T defvalue,lazydefvalue;
	vector<T>dat,lazy;
	vector<bool>lazyflag;
	lazysegtree(int n_=0,T defvalue_=0,
		const F calcfn_=[](T a,T b){return a+b;},
		const F lazycalcfn_=[](T a,T b){return a+b;},
		const G updatefn_=[](T a,T b,int l,int r){return a+b*(r-l);},
		T lazydefvalue_=0
	):defvalue(defvalue_),lazydefvalue(lazydefvalue_),
		calcfn(calcfn_),lazycalcfn(lazycalcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,defvalue);
		lazy.assign(2*n-1,lazydefvalue);
		lazyflag.assign(2*n-1,false);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)dat[i]=calcfn(dat[2*i+1],dat[2*i+2]);
	}
	void eval(int i,int l,int r)
	{
		if(lazyflag[i])
		{
			dat[i]=updatefn(dat[i],lazy[i],l,r);
			if(r-l>1)
			{
				lazy[2*i+1]=lazycalcfn(lazy[2*i+1],lazy[i]);
				lazy[2*i+2]=lazycalcfn(lazy[2*i+2],lazy[i]);
				lazyflag[2*i+1]=lazyflag[2*i+2]=true;
			}
			lazy[i]=lazydefvalue;
			lazyflag[i]=false;
		}
	}
	void update(int a,int b,T x,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]=lazycalcfn(lazy[k],x);
			lazyflag[k]=true;
			eval(k,l,r);
		}
		else
		{
			update(a,b,x,2*k+1,l,(l+r)/2);
			update(a,b,x,2*k+2,(l+r)/2,r);
			dat[k]=calcfn(dat[2*k+1],dat[2*k+2]);
		}
	}
	T query(int a,int b,int k=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		eval(k,l,r);
		if(b<=l||r<=a)return defvalue;
		else if(a<=l&&r<=b)return dat[k];
		else return calcfn(
			query(a,b,2*k+1,l,(l+r)/2),
			query(a,b,2*k+2,(l+r)/2,r)
		);
	}
};
int N,M,P;
main()
{
	scanf("%d%d%d",&N,&M,&P);
	vector<int>A(N),ca(N);
	{
		vector<pair<int,int> >Ain(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d%d",&Ain[i].first,&Ain[i].second);
		}
		sort(Ain.begin(),Ain.end());
		int pre=1e9;
		for(int i=N;i--;)
		{
			A[i]=Ain[i].first;
			ca[i]=pre=min(pre,Ain[i].second);
		}
	}
	vector<int>B(M),cb(M);
	{
		vector<pair<int,int> >Bin(M);
		for(int i=0;i<M;i++)
		{
			scanf("%d%d",&Bin[i].first,&Bin[i].second);
		}
		sort(Bin.begin(),Bin.end());
		int pre=1e9;
		for(int i=M;i--;)
		{
			B[i]=Bin[i].first;
			cb[i]=pre=min(pre,Bin[i].second);
		}
	}
	vector<pair<pair<int,int>,int> >xyz(P);
	vector<int>Y(P);
	for(int i=0;i<P;i++)
	{
		scanf("%d%d%d",&xyz[i].first.first,&xyz[i].first.second,&xyz[i].second);
		Y[i]=xyz[i].first.second;
	}
	sort(xyz.begin(),xyz.end());
	sort(Y.begin(),Y.end());
	Y.erase(unique(Y.begin(),Y.end()),Y.end());
	vector<int>bitc;
	int bi=0;
	for(int i=0;i<Y.size();i++)
	{
		int y=Y[i];
		while(bi<B.size()&&B[bi]<=y)bi++;
		if(bi==M)break;
		bitc.push_back(-cb[bi]);
	}
	auto calc=[](int a,int b){return a<b?b:a;};
	auto lcalc=[](int a,int b){return a+b;};
	auto upd=[](int a,int b,int l,int r){return a+b;};
	lazysegtree<int>bit(bitc.size(),-1e9,calc,lcalc,upd);
	bit.copy(bitc);
	int ans=-cb[0]-ca[0];
	int ai=0;
	for(pair<pair<int,int>,int>xy:xyz)
	{
		int x=xy.first.first,y=xy.first.second,z=xy.second;
		int yi=lower_bound(Y.begin(),Y.end(),y)-Y.begin();
		bit.update(yi,bitc.size(),z);
		while(ai<A.size()&&A[ai]<=x)ai++;
		if(ai==N)break;
		ans=max(ans,bit.query(0,bitc.size())-ca[ai]);
	}
	printf("%d\n",ans);
}