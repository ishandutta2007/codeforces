#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>

using namespace std;

const int MaxN=710;

int n;
vector<int> v[MaxN],son[MaxN];

void init()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
}

const int MOD=100000000;

struct number
{
	int len;
	unsigned long long v[20];
	void init()
	{
		memset(v,0,sizeof(v));
		len=0;
	}
	void operator = (int p)
	{
		init();
		len=1;
		v[0]=p;
	}
	bool operator < (number A) const
	{
		if (len<A.len) return true;
		if (len>A.len) return false;
		for (int i=len-1;i>=0;--i)
		{
			if (v[i]<A.v[i]) return true;
			if (v[i]>A.v[i]) return false;
		}
		return false;
	}
	number operator * (number A)
	{
		number p;
		p.init();
		for (int i=0;i<len;++i)
			for (int j=0;j<A.len;++j)
				p.v[i+j]+=v[i]*A.v[j];
		p.len=len+A.len;
		for (int i=0,x=0;i<p.len;++i)
		{
			p.v[i]+=x;
			x=p.v[i]/MOD;
			p.v[i]%=MOD;
		}
		for (;p.len>1;--p.len)
			if (p.v[p.len-1]) break;
		return p;
	}
	number operator * (int k)
	{
		number p=*this;
		p.len=len+1;
		for (int i=0,x=0;i<p.len;++i)
		{
			p.v[i]=p.v[i]*k+x;
			x=p.v[i]/MOD;
			p.v[i]%=MOD;
		}
		for (;p.len>1;--p.len)
			if (p.v[p.len-1]) break;
		return p;
	}
	void operator *= (number A)
	{
		*this=*this*A;
	}
	void print()
	{
		cout<<v[len-1];
		for (int i=len-2;i>=0;--i)
			printf("%08d",(int)v[i]);
	}
};

number F[MaxN],G[MaxN],P[MaxN][MaxN],Ls[MaxN],Rs[MaxN];

void solve(int x,int pre)
{
	F[x]=1;
	G[x]=1;
	for (int i=0;i<v[x].size();++i)
		if (v[x][i]!=pre)
		{
			son[x].push_back(v[x][i]);
			solve(v[x][i],x);
			G[x]*=F[v[x][i]];
		}
	F[x]=G[x];
	P[x][0]=1;
	for (int i=0;i<=son[x].size();++i)
		P[x][i+1]=0;
	for (int i=0;i<son[x].size();++i)
		for (int j=son[x].size()-1;j>=0;--j)
		{
			P[x][j+1]=max(P[x][j+1],P[x][j]*G[son[x][i]]);
			P[x][j]*=F[son[x][i]];
		}
	for (int i=0;i<=son[x].size();++i)
		F[x]=max(F[x],P[x][i]*(i+1));
	Ls[0]=1;
	Rs[son[x].size()+1]=1;
	for (int i=0;i<son[x].size();++i)
		Ls[i+1]=Ls[i]*F[son[x][i]];
	for (int i=(int)son[x].size()-1;i>=0;--i)
		Rs[i+1]=Rs[i+2]*F[son[x][i]];
	for (int i=0;i<son[x].size();++i)
		for (int j=0;j<=son[son[x][i]].size();++j)
			F[x]=max(F[x],Ls[i]*Rs[i+2]*P[son[x][i]][j]*(j+2));
}

void work()
{
	solve(1,0);
	F[1].print();
}

int main()
{
	init();
	work();
	return 0;
}