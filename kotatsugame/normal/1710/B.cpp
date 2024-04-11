#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Disjoint Sparse Table
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
					dat.back()[j-k]=max(dat[0][j-k],dat.back()[j-k+1]);
				}
				dat.back()[j]=dat[0][j];
				for(int k=2;k<=i&&j+k<=n;k++)
				{
					dat.back()[j+k-1]=max(dat.back()[j+k-2],dat[0][j+k-1]);
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
		return max(dat[k][l],dat[k][r]);
	}
};
int T,N,M;
int X[2<<17],P[2<<17],Id[2<<17];
bool ok[2<<17];
long long A[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		vector<pair<int,int> >query;
		query.reserve(5*N);
		for(int i=0;i<N;i++)
		{
			cin>>X[i]>>P[i];
			X[i]--;
			query.push_back(make_pair(X[i],i));
			query.push_back(make_pair(X[i]-P[i],-1));
			query.push_back(make_pair(X[i],-2));
			query.push_back(make_pair(X[i],-2));
			query.push_back(make_pair(X[i]+P[i],-1));
		}
		sort(query.begin(),query.end());
		long long sum=0,diff=0;
		int prev;
		for(int i=0;i<query.size();i++)
		{
			int x=query[i].first;
			if(i>0)sum+=diff*(x-prev);
			prev=x;
			int op=query[i].second;
			if(op>=0)A[op]=sum;
			else if(op==-1)diff++;
			else diff--;
		}
		vector<int>xv(X,X+N);
		sort(xv.begin(),xv.end());
		xv.erase(unique(xv.begin(),xv.end()),xv.end());
		vector<long long>Li(xv.size(),-1e18),Ri(xv.size(),-1e18);
		for(int i=0;i<N;i++)
		{
			int id=lower_bound(xv.begin(),xv.end(),X[i])-xv.begin();
			if(A[i]>M)
			{
				Li[id]=max(Li[id],A[i]-X[i]-M);
				Ri[id]=max(Ri[id],A[i]+X[i]-M);
			}
			Id[i]=id;
		}
		DST<long long>L(Li),R(Ri);
		for(int i=0;i<N;i++)
		{
			int id=Id[i];
			if(L.query(0,id+1)>P[i]-X[i]||R.query(id,xv.size())>P[i]+X[i])cout<<'0';
			else cout<<'1';
		}
		cout<<"\n";
	}
}