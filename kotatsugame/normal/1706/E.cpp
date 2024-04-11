#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//Disjoint Sparse Table
#include<vector>
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
int T,N,M,Q;
vector<int>vs[1<<17];
int pr[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>Q;
		for(int i=0;i<N;i++)
		{
			pr[i]=i;
			vs[i].clear();
			vs[i].push_back(i);
		}
		vector<int>init(N-1);
		for(int i=0;i<M;i++)
		{
			int u,v;cin>>u>>v;
			u--,v--;
			u=pr[u];
			v=pr[v];
			if(u!=v)
			{
				if(vs[u].size()>vs[v].size())swap(u,v);
				for(int w:vs[u])
				{
					if(w>=1&&pr[w-1]==v&&init[w-1]==0)init[w-1]=i+1;
					if(w+1<N&&pr[w+1]==v&&init[w]==0)init[w]=i+1;
					pr[w]=v;
					vs[v].push_back(w);
				}
			}
		}
		DST<int>dst(init);
		for(int i=0;i<Q;i++)
		{
			int l,r;cin>>l>>r;l--,r--;
			cout<<(l==r?0:dst.query(l,r))<<(i+1==Q?"\n":" ");
		}
	}
}