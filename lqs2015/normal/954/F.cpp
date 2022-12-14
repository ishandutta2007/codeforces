#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const long long mod=1e9+7;
long long n,m,l,r,d,num[4],f,k;
vector<pair<long long,pair<long long,long long> > > v; 
multiset<pair<long long,long long> > s[4];
struct mat
{
	long long ma[4][4];
	mat()
	{
		ma[1][1]=ma[2][2]=ma[3][3]=1;
		ma[1][2]=ma[1][3]=ma[2][1]=ma[2][3]=ma[3][1]=ma[3][2]=0;
	}
	mat operator * (const mat &a) const
	{
		mat res;
		for (long long i=1;i<=3;i++)
		{
			for (long long j=1;j<=3;j++)
			{
				res.ma[i][j]=0;
				for (long long k=1;k<=3;k++)
				{
					res.ma[i][j]=(res.ma[i][j]+ma[i][k]*a.ma[k][j])%mod;
				}
			}
		}
		return res;
	}
}matr,matrix,can;
mat mul(mat a,long long t)
{
	mat res,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
void doit()
{
	long long ans[4];
	for (long long i=1;i<=3;i++)
	{
		ans[i]=0;
		for (long long j=1;j<=3;j++)
		{
			ans[i]=(ans[i]+num[j]*can.ma[i][j])%mod;
		}
	}
	for (long long i=1;i<=3;i++) num[i]=ans[i];
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%I64d%I64d%I64d",&d,&l,&r);
		s[d].insert(make_pair(l,0));
		s[d].insert(make_pair(r,1));  
	}
	for (long long i=1;i<=3;i++)
	{
		k=0;
		for (multiset<pair<long long,long long> >::iterator it=s[i].begin();it!=s[i].end();it++)
		{
			if (it->second==0)
			{
				if (!k) v.push_back(make_pair(it->first,make_pair(0,i)));
				k++; 
			}
			else 
			{
				k--;
				if (!k) v.push_back(make_pair(it->first+1,make_pair(1,i))); 
			}
		}
	}
	sort(v.begin(),v.end());
	matr.ma[1][1]=matr.ma[1][2]=matr.ma[2][1]=matr.ma[2][2]=matr.ma[2][3]=matr.ma[3][2]=matr.ma[3][3]=1;
	matr.ma[1][3]=matr.ma[3][1]=0;
	matrix=matr;
	num[1]=num[3]=0;num[2]=1;
	can=mul(matr,v[0].first-2);
	doit();
	for (long long i=0;i<v.size();i++)
	{
		d=v[i].second.second;f=v[i].second.first;
		if (!f)
		{
			for (long long j=1;j<=3;j++) matr.ma[d][j]=0;
		}
		else
		{
			for (long long j=1;j<=3;j++) matr.ma[d][j]=matrix.ma[d][j];
		}
		if (i==v.size()-1) can=mul(matr,m-v[i].first+1);
		else can=mul(matr,v[i+1].first-v[i].first);
		doit();
	}
	printf("%I64d\n",num[2]);
	return 0;
}