#include<cstdio>
#include<queue>
using namespace std;
//Disjoint Sparse Table
#include<vector>
pair<int,int>calcfn(pair<int,int>a,pair<int,int>b)
{
	return a.first>b.first?a:a.first<b.first?b:a.second<b.second?a:b;
}
struct DST{
	int n;
	vector<vector<pair<int,int> > >dat;
	DST(const vector<pair<int,int> >&v={})
	{
		n=v.size();
		dat.push_back(v);
		for(int i=2;i<n;i<<=1)
		{
			dat.push_back(vector<pair<int,int> >(n));
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
	pair<int,int>query(int l,int r)const//[l,r)
	{
		if(l<0)l=0;
		if(r>n)r=n;
		r--;
		if(l==r)return dat[0][l];
		int k=31-__builtin_clz(l^r);
		return calcfn(dat[k][l],dat[k][r]);
	}
};
int T,N;
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		vector<pair<int,int> >A(N);
		for(int i=0;i<N;i++)
		{
			scanf("%d",&A[i].first);
			A[i].second=i;
		}
		DST P(A);
		queue<pair<pair<int,int>,int> >Q;
		Q.push(make_pair(make_pair(0,N),-1));
		long long ans=0;
		while(!Q.empty())
		{
			int l=Q.front().first.first,r=Q.front().first.second;
			int mx=Q.front().second;
			Q.pop();
			if(r<=l)continue;
			pair<int,int>p=P.query(l,r);
			if(mx!=-1)ans+=mx-p.first;
			Q.push(make_pair(make_pair(p.second+1,r),p.first));
			Q.push(make_pair(make_pair(l,p.second),mx==-1?-1:p.first));
		}
		printf("%lld\n",ans);
	}
}