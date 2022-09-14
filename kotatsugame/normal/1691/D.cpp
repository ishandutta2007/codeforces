#include<iostream>
#include<algorithm>
using namespace std;
//Disjoint Sparse Table
#include<vector>
template<typename T,T(*op)(T,T)>
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
					dat.back()[j-k]=op(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=op(dat.back()[j+k-2],dat[0][j+k-1]);
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
		return op(dat[k][l],dat[k][r]);
	}
};
long long mx(long long a,long long b){return a<b?b:a;}
long long mn(long long a,long long b){return a<b?a:b;}
int T,N;
pair<int,int>A[2<<17];
int L[2<<17],R[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		R[0]=1;
		L[N+1]=N;
		vector<long long>S(N+1);
		S[0]=0;
		for(int i=1;i<=N;i++)
		{
			cin>>A[i].first;
			A[i].second=i;
			L[i]=i-1;
			R[i]=i+1;
			S[i]=S[i-1]+A[i].first;
		}
		DST<long long,mx>MX(S);
		DST<long long,mn>MN(S);
		sort(A+1,A+N+1);
		bool ok=true;
		for(int i=1;i<=N;i++)
		{
			int id=A[i].second;
			int l=L[id],r=R[id];
			R[l]=r,L[r]=l;
			if(A[i].first<MX.query(id,r)-MN.query(l,id))
			{
				ok=false;
				break;
			}
		}
		cout<<(ok?"YES\n":"NO\n");
	}
}