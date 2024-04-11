#line 1 "a.cpp"
#include<cstdio>
#include<vector>
using namespace std;
#line 1 "/home/kotatsugame/library/datastructure/DST.cpp"
//Disjoint Sparse Table
#line 3 "/home/kotatsugame/library/datastructure/DST.cpp"
#include<functional>
template<typename T>
struct DST{
	function<T(T,T)>calcfn;
	int n;
	vector<vector<T> >dat;
	DST(const vector<T>&v={},
		function<T(T,T)>calcfn_=[](T a,T b){return a<b?a:b;}
	):calcfn(calcfn_)
	{
		n=v.size();
		dat.push_back(v);
		for(int i=2;i<n;i<<=1)
		{
			dat.push_back(vector<T>(n));
			for(int j=i;j<n;j+=i<<1)
			{
				dat.back()[j-1]=dat[0][j-1];
				for(int k=2;k<=i;k++)
				{
					dat.back()[j-k]=calcfn(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=calcfn(dat.back()[j+k-2],dat[0][j+k-1]);
				}
			}
		}
	}
	T query(int l,int r)const//[l,r)
	{
		if(l<0)l=0;
		if(r>n)r=n;
		r--;
		if(l==r)return dat[0][l];
		int k=31-__builtin_clz(l^r);
		return calcfn(dat[k][l],dat[k][r]);
	}
};
#line 3 "/home/kotatsugame/library/datastructure/segtree.cpp"
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
#line 6 "a.cpp"
int T,N;
int A[5<<17];
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i]);
			A[i]--;
		}
		DST<int>P(vector<int>(A,A+N),[](int a,int b){return a>b?a:b;});
		segtree<pair<int,int> >Q(N,make_pair(0,1),[](pair<int,int>a,pair<int,int>b){return a>b?a:b;},[](pair<int,int>a,pair<int,int>b){return b;});
		for(int i=0;i<N;i++)
		{
			pair<int,int>p=Q.query(0,A[i]+1);
			int nxt=p.first+1;
			if(-p.second+1<i&&P.query(-p.second+1,i)>A[i])nxt++;
			Q.update(A[i],make_pair(nxt,-i));
		}
		printf("%d\n",Q.query(0,N).first);
	}
}