#include<iostream>
#include<algorithm>
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
long long A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	vector<long long>V;
	for(int i=0;i<N;i++)
	{
		int a;cin>>a;
		if(i==0)A[i]=a;
		else A[i]=a+A[i-1];
		V.push_back(A[i]);
	}
	sort(V.begin(),V.end());
	if(V[0]<0||V.back()!=A[N-1])
	{
		cout<<"-1\n";
		return 0;
	}
	V.erase(unique(V.begin(),V.end()),V.end());
	BIT<int>bit(V.size());
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		int id=lower_bound(V.begin(),V.end(),A[i])-V.begin();
		ans+=bit.sum(V.size())-bit.sum(id+1);
		bit.add(id+1,1);
	}
	cout<<ans<<endl;
}