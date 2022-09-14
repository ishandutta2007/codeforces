#include<iostream>
using namespace std;
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
int N,K;
string A;
main()
{
	cin>>N>>K>>A;
	string B(N,'9');
	segtree<int>P(N,0,[](int a,int b){return a?a:b;},[](int a,int b){return b;});
	vector<int>X(N);
	for(int i=0;i<N;i++)X[i]=A[i]<'9'?1:0;
	P.copy(X);
	for(int i=0;i<K;i++)
	{
		int now=8;
		while(now>=0)
		{
			int flag=0;
			int j;
			for(j=i;j<N;j+=K)
			{
				int x=P.query(j-K+1,j);
				if(x==1)
				{
					flag=1;
					break;
				}
				else if(x==-1)
				{
					flag=-1;
					break;
				}
				else if(A[j]-'0'<now)
				{
					flag=1;
					break;
				}
				else if(A[j]-'0'>now)
				{
					flag=-1;
					break;
				}
			}
			if(flag==0)
			{
				flag=P.query(j-K+1,j);
			}
			if(flag<0)break;
			now--;
		}
		now++;
		for(int j=i;j<N;j+=K)
		{
			B[j]=now+'0';
			P.update(j,B[j]<A[j]?-1:B[j]>A[j]?1:0);
		}
	}
	cout<<N<<endl<<B<<endl;
}