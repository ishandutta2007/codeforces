#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,x[100005],v[100005];
long long p[2][100005];
typedef vector<vector<long long> > matrix;
matrix mat[100005],tree[400005];
void mul(matrix &a,matrix &b,matrix &c)
{
    if (c.empty())
	c=matrix(a.size(),vector<long long>(b[0].size(),0));
	for (int i=0;i<a.size();i++)
	{
		for (int x=0;x<b[0].size();x++)
		{
		    c[i][x]=0;
			for (int j=0;j<b.size();j++)
			c[i][x]=(c[i][x]+a[i][j]*b[j][x])%mod;
		}
	}
}
long long pow_log(long long x,int y)
{
	if (!y)
	return 1;
	long long ret=pow_log(x,y/2);
	ret=(ret*ret)%mod;
	if (y%2)
	ret=(ret*x)%mod;
	return ret;
}
struct fraction
{
	long long a,b;
	fraction(long long aa,long long bb)
	{
		a=aa;
		b=bb;
	}
	bool operator<(const fraction &c) const
	{
		return a*c.b<b*c.a;
	}
};
void build(int node,int st,int en)
{
    if (st==en)
    tree[node]=mat[st];
    else
    {
        int mid=(st+en)/2;
        build(2*node,st,mid);
        build(2*node+1,mid+1,en);
        mul(tree[2*node],tree[2*node+1],tree[node]);
    }
}
void update(int node,int st,int en,int idx)
{
	if (st==en)
	tree[node]=mat[idx];
	else
	{
		int mid=(st+en)/2;
		if (st<=idx && idx<=mid)
		update(2*node,st,mid,idx);
		else
		update(2*node+1,mid+1,en,idx);
		mul(tree[2*node],tree[2*node+1],tree[node]);
	}
}
vector<pair<pair<fraction,int>,pair<int,int> > > e;
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d%I64d",&x[i],&v[i],&p[0][i]);
		p[0][i]=(p[0][i]*pow_log(100,mod-2))%mod;
		p[1][i]=(1-p[0][i]+mod)%mod;
	}
	for (int i=0;i<n;i++)
	{
		mat[i]=matrix({{p[0][i],p[0][i]},{p[1][i],p[1][i]}});
		if (i==n-1)
		break;
		for (int j=0;j<2;j++)
		{
			for (int k=0;k<2;k++)
			{
				if (v[i]>v[i+1])
				e.push_back({{fraction(x[i+1]-x[i],v[i]-v[i+1]),i},{j,k}});
				v[i+1]*=-1;
			}
			v[i]*=-1;
		}
	}
	build(1,0,n-1);
	sort(e.begin(),e.end());
	long long ans=0;
	for (auto j:e)
	{
		int idx=j.first.second;
		long long t1=0,t2=0,t3=0,t4=0;
		swap(mat[idx][!j.second.first][0],t1);
		swap(mat[idx][!j.second.first][1],t2);
		swap(mat[idx+1][!j.second.second][0],t3);
		swap(mat[idx+1][!j.second.second][1],t4);
		update(1,0,n-1,idx);
		if (idx!=n-1)
		update(1,0,n-1,idx+1);
		long long prob=(tree[1][0][0]+tree[1][0][1]+tree[1][1][0]+tree[1][1][1])*(mod+1)/2%mod;
		ans=(ans+prob*j.first.first.a%mod*pow_log(j.first.first.b,mod-2))%mod;
		swap(mat[idx][!j.second.first][0],t1);
		swap(mat[idx][!j.second.first][1],t2);
		swap(mat[idx+1][!j.second.second][0],t3);
		swap(mat[idx+1][!j.second.second][1],t4);
		mat[idx][j.second.first][j.second.second]=0;
		update(1,0,n-1,idx);
		if (idx!=n-1)
		update(1,0,n-1,idx+1);
	}
	printf("%I64d",ans);
}