#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int n,a[222],son[555][26],sz,fail[555],pos,num[555],sum[555];
string s[222];
queue<int> q;
long long l,ans;
struct mat
{
	long long a[555][555];
	mat()
	{
		for (int i=1;i<=sz;i++)
		{
			for (int j=1;j<=sz;j++)
			{
				if (i==j) a[i][j]=0;
				else a[i][j]=-inf;
			}
		}
	}
	mat operator * (const mat &u) const
	{
		mat res;
		for (int i=1;i<=sz;i++)
		{
			for (int j=1;j<=sz;j++)
			{
				res.a[i][j]=-inf;
				for (int k=1;k<=sz;k++)
				{
					res.a[i][j]=max(res.a[i][j],a[i][k]+u.a[k][j]);
				}
			}
		}
		return res;
	}
}ma;
mat binpow(mat a,long long t)
{
	mat res,p=a;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
int main()
{
	scanf("%d%lld",&n,&l);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) cin>>s[i];
    sz=1;
	for (int i=1;i<=n;i++)
	{
		pos=1;
		for (int j=0;j<s[i].size();j++)
		{
			if (!son[pos][s[i][j]-'a']) 
			{
				pos=son[pos][s[i][j]-'a']=++sz;
			}
			else pos=son[pos][s[i][j]-'a'];
		}
		num[pos]+=a[i];
	}
	for (int i=0;i<26;i++)
	{
		if (son[1][i]) 
		{
			q.push(son[1][i]);
			fail[son[1][i]]=1; 
		}
		else son[1][i]=1;
	}
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<26;i++)
		{
			if (son[x][i])
			{
				q.push(son[x][i]);
				fail[son[x][i]]=son[fail[x]][i]; 
			}
			else son[x][i]=son[fail[x]][i];
		}
	}
	for (int i=2;i<=sz;i++)
	{
		for (int j=i;j>1;j=fail[j]) sum[i]+=num[j]; 
	}
	for (int i=1;i<=sz;i++)
	{
		for (int j=1;j<=sz;j++) 
		ma.a[i][j]=-inf;
	}
	for (int i=1;i<=sz;i++)
	{
		for (int j=0;j<26;j++)
		{
			ma.a[i][son[i][j]]=sum[son[i][j]];
		}
	}
	ma=binpow(ma,l);
	for (int i=1;i<=sz;i++) ans=max(ans,ma.a[1][i]);
	printf("%lld\n",ans);
	return 0;
}