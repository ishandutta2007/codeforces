#include<iostream>
#include<vector>
using namespace std;
int gcd(int a,int b){
	while(b)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}
template<typename T>
struct DST{
	int n;
	vector<vector<T> >dat;
	DST(const vector<T>&v={})
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
					dat.back()[j-k]=gcd(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=gcd(dat.back()[j+k-2],dat[0][j+k-1]);
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
		return gcd(dat[k][l],dat[k][r]);
	}
};
int N;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	vector<int>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	DST<int>P(A);
	int pre=-1;
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		int l=pre,r=i;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(P.query(mid,i+1)>=i+1-mid)r=mid;
			else l=mid;
		}
		if(P.query(r,i+1)==i+1-r)pre=i,cnt++;
		cout<<cnt<<(i+1==N?"\n":" ");
	}
}