#line 1 "a.cpp"
#include<cstdio>
#include<algorithm>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/segtree.cpp"
#include<vector>
#include<functional>
#include<limits>
template<typename T>
struct segtree{
	using F=function<T(T,T)>;
	const F calcfn,updatefn;
	int n;
	T defvalue;
	vector<T>dat;
	segtree(int n_=0,T defvalue_=numeric_limits<T>::max(),
		const F calcfn_=[](T a,T b){return a<b?a:b;},
		const F updatefn_=[](T a,T b){return b;}
	):defvalue(defvalue_),calcfn(calcfn_),updatefn(updatefn_)
	{
		n=1;
		while(n<n_)n<<=1;
		dat.assign(2*n-1,defvalue);
	}
	void copy(const vector<T>&v)
	{
		for(int i=0;i<v.size();i++)dat[i+n-1]=v[i];
		for(int i=n-2;i>=0;i--)dat[i]=calcfn(dat[i*2+1],dat[i*2+2]);
	}
	void update(int i,T a)
	{
		i+=n-1;
		dat[i]=updatefn(dat[i],a);
		while(i>0)
		{
			i=(i-1)/2;
			dat[i]=calcfn(dat[2*i+1],dat[2*i+2]);
		}
	}
	T query(int a,int b)//[a,b)
	{
		int L=(a<0?0:a>n?n:a)+n-1;
		int R=(b<0?0:b>n?n:b)+n-1;
		T lret=defvalue,rret=defvalue;
		for(;L<R;L>>=1,R>>=1)
		{
			if(!(L&1))lret=calcfn(lret,dat[L]);
			if(!(R&1))rret=calcfn(dat[--R],rret);
		}
		return calcfn(lret,rret);
	}
};
#line 5 "a.cpp"
int T,N,Q;
char S[2<<17];
struct dat{
	int mx,mn,ri;
	dat(int a=0,int b=0,int c=0):mx(a),mn(b),ri(c){}
};
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d%s",&N,&Q,S);
		vector<dat>init(N);
		for(int i=0;i<N;i++)
		{
			if(S[i]=='+')init[i]=dat(1,1,1);
			else init[i]=dat(-1,-1,-1);
		}
		segtree<dat>P(N,dat(),[](const dat&a,const dat&b){
			return dat(max(a.mx,a.ri+b.mx),
				min(a.mn,a.ri+b.mn),
				a.ri+b.ri);
		},[](const dat&a,const dat&b){return b;});
		P.copy(init);
		for(;Q--;)
		{
			int L,R;scanf("%d%d",&L,&R);
			dat X=P.query(0,L-1);
			dat Y=P.query(R,N);
			int mx=max(X.mx,X.ri+Y.mx);
			if(mx<0)mx=0;
			int mn=min(X.mn,X.ri+Y.mn);
			if(mn>0)mn=0;
			printf("%d\n",mx-mn+1);
		}
	}
}