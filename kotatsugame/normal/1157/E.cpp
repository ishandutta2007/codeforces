#include<iostream>
#include<cstdio>
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
	T query(int a,int b,int i=0,int l=0,int r=-1)//[a,b)
	{
		if(r<0)r=n;
		if(r<=a||b<=l)return defvalue;
		else if(a<=l&&r<=b)return dat[i];
		else
		{
			return calcfn(
				query(a,b,i*2+1,l,(l+r)/2),
				query(a,b,i*2+2,(l+r)/2,r)
			);
		}
	}
};
int N,a[2<<17],cb[2<<17];
main()
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",a+i);
	for(int i=0;i<N;i++)
	{
		int b;scanf("%d",&b);
		cb[b]++;
	}
	segtree<long long>P(N*2,0,[](long long a,long long b){return a+b;});
	for(int i=0;i<N;i++)
	{
		P.update(i,cb[i]);
		P.update(i+N,cb[i]);
	}
	for(int i=0;i<N;i++)
	{
		int L=-1,R=N-1;
		int np=(N-a[i])%N;
		while(R-L>1)
		{
			int M=(L+R)/2;
			if(P.query(np,np+M+1)>0)R=M;
			else L=M;
		}
		printf("%d%c",R,i==N-1?'\n':' ');
		R=(R-a[i]+N)%N;
		cb[R]--;
		P.update(R,cb[R]);
		P.update(R+N,cb[R]);
	}
}