#line 1 "a.cpp"
#include<iostream>
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
#line 4 "a.cpp"
int N,T,K;
bool asked[2<<17];
int ans[2<<17];
BIT<int>P(2<<17);
int ask(int r)
{
	if(asked[r])
	{
		return ans[r]+P.sum(r);
	}
	asked[r]=true;
	cout<<"? 1 "<<r<<endl;
	int x;cin>>x;
	ans[r]=x-P.sum(r);
	return x;
}
main()
{
	cin>>N>>T;
	for(;T--;)
	{
		cin>>K;
		int L=0,R=N;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			int x=ask(mid);
			if(mid-x>=K)R=mid;
			else L=mid;
		}
		cout<<"! "<<R<<endl;
		P.add(R,1);
	}
}