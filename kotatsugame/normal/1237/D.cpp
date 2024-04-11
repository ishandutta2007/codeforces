#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#include<vector>
#include<functional>
#include<limits>
template<typename T>
struct segtree{
	function<T(T,T)>calcfn,updatefn;
	int n;
	T defvalue;
	vector<T>dat;
	segtree(int n_=0,T defvalue_=numeric_limits<T>::max(),
		function<T(T,T)>calcfn_=[](T a,T b){return a<b?a:b;},
		function<T(T,T)>updatefn_=[](T a,T b){return b;}
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
int N;
int A[1<<17],T[3<<17],id[1<<17];
vector<int>X;
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",A+i);
		X.push_back(A[i]);
	}
	sort(X.begin(),X.end());
	X.erase(unique(X.begin(),X.end()),X.end());
	for(int i=0;i<N;i++)
	{
		id[i]=lower_bound(X.begin(),X.end(),A[i])-X.begin();
	}
	segtree<int>P(X.size()+1,(int)1e9);
	for(int i=3*N;i--;)
	{
		int t=P.query(0,lower_bound(X.begin(),X.end(),(A[i%N]+1)/2)-X.begin());
		T[i]=t;
		P.update(id[i%N],i);
	}
	segtree<int>Q(3*N);
	vector<int>vT(T,T+3*N);
	Q.copy(vT);
	for(int i=0;i<N;i++)
	{
		int L=i,R=T[i];
		if(R>3*N)R=3*N;
		int ans=Q.query(L,R)-L;
		if(ans>3*N)ans=-1;
		printf("%d%c",ans,i+1<N?' ':'\n');
	}
}