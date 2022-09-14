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
int N;
char s[1<<20],now[1<<20];
main()
{
	scanf("%d\n%s\n",&N,s);
	auto cfn=[](pair<int,int>a,pair<int,int>b){
		return make_pair(min(a.first,b.first),max(a.second,b.second));
	};
	auto lcfn=[](pair<int,int>a,pair<int,int>b){
		return make_pair(a.first+b.first,0);
	};
	auto ufn=[](pair<int,int>a,pair<int,int>b,int l,int r){
		return make_pair(a.first+b.first,a.second+b.first);
	};
	lazysegtree<pair<int,int> >P(N,make_pair(0,0),cfn,lcfn,ufn,make_pair(0,0));
	int point=0,ans=0,cnt=0;
	for(int i=0;i<N;i++)
	{
		if(s[i]=='R')point++;
		else if(s[i]=='L')
		{
			if(point)point--;
		}
		else if(s[i]=='(')
		{
			if(now[point]!='(')
			{
				P.update(point,N,make_pair(now[point]==')'?2:1,0));
				cnt+=now[point]==')'?2:1;
				now[point]='(';
				pair<int,int>p=P.query(0,N);
				if(cnt!=0||p.first<0)ans=-1;
				else ans=p.second;
			}
		}
		else if(s[i]==')')
		{
			if(now[point]!=')')
			{
				P.update(point,N,make_pair(now[point]=='('?-2:-1,0));
				cnt+=now[point]=='('?-2:-1;
				now[point]=')';
				pair<int,int>p=P.query(0,N);
				if(cnt!=0||p.first<0)ans=-1;
				else ans=p.second;
			}
		}
		else
		{
			if(now[point]=='('||now[point]==')')
			{
				P.update(point,N,make_pair(now[point]=='('?-1:1,0));
				cnt+=now[point]=='('?-1:1;
				now[point]=0;
				pair<int,int>p=P.query(0,N);
				if(cnt!=0||p.first<0)ans=-1;
				else ans=p.second;
			}
		}
		printf("%d%c",ans,i+1==N?'\n':' ');
	}
}