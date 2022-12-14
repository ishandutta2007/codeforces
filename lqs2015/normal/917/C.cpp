#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
long long x,k,n,q,cnt,c[333],s[333][333],ks[333],id[333],cur,pos,f,di,nw[333],t[333],pre;
pair<long long,long long> p[333];
map<long long,long long> mp;
struct mat
{
	long long a[88][88];
	mat()
	{
		for (long long i=1;i<=cnt;i++)
		{
			for (long long j=1;j<=cnt;j++)
			{
				if (i==j) a[i][j]=0ll;
				else a[i][j]=1e18;
			}
		}
	}
	mat operator * (const mat &b) const
	{
		mat res;
		for (long long i=1;i<=cnt;i++)
		{
			for (long long j=1;j<=cnt;j++)
			{
				res.a[i][j]=1e18;
				for (long long k=1;k<=cnt;k++)
				{
					res.a[i][j]=min(res.a[i][j],a[i][k]+b.a[k][j]);
				}
			}
		}
		return res;
	}
}ma,cs;
void Init()
{
	for (long long i=0;i<(1<<k);i++)
	{
		cur=0;
		for (long long j=0;j<k;j++)
		{
			if (i&(1<<j)) cur++;
		}
		if (cur==x)
		{
			ks[++cnt]=i;
			id[i]=cnt;
		}
	}
	for (long long i=1;i<=cnt;i++)
	{
		for (long long j=1;j<=cnt;j++)
		ma.a[i][j]=1e18;
	}
	for (long long i=1;i<=cnt;i++)
	{
		cur=ks[i];f=0;
		for (long long j=0;j<k;j++)
		{
			if (cur&(1<<j))
			{
				if (!f)
				{
					f=1;
					pos=j;
					if (pos)
					{
						cur-=(1<<j);
						cur+=(1<<(j-1));
					}
				}
				else
				{
					cur-=(1<<j);
					cur+=(1<<(j-1));
				}
			}
		}
		if (pos)
		{
			ma.a[id[cur]][i]=0;
		}
		else
		{
			cur=ks[i];
			cur--;
			for (int j=1;j<k;j++)
			{
				if (cur&(1<<j))
				{
					cur-=(1<<j);
					cur+=(1<<(j-1));
				}
			}
			for (long long j=1;j<=k;j++)
			{
				if (cur&(1<<(j-1))) continue;
				di=id[cur+(1<<(j-1))];
				ma.a[di][i]=c[j];
				s[di][i]=j-1;
			}
		}
	}
}
mat binpow(mat a,long long t)
{
	mat res,p=a;
	if (t<=0) return res;
	for (long long i=t;i;i>>=1)
	{
		if (i&1) res=res*p;
		p=p*p;
	}
	return res;
}
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&x,&k,&n,&q);
	for (long long i=1;i<=k;i++) scanf("%I64d",&c[i]);
	for (long long i=1;i<=80;i++)
	{
		for (long long j=1;j<=80;j++)
		{
			s[i][j]=-1e9;
		}
	}
	Init();
	for (long long i=1;i<=q;i++)
	{
		scanf("%I64d%I64d",&p[i].first,&p[i].second);
		mp[p[i].first]=p[i].second;
	}
	sort(p+1,p+q+1);
	for (long long i=1;i<=cnt;i++) nw[i]=1e18;
	nw[1]=0;
	if (!q) 
	{
		cs=binpow(ma,n-x);
		for (long long i=1;i<=cnt;i++)
		{
			t[i]=1e18;
			for (long long j=1;j<=cnt;j++) t[i]=min(t[i],cs.a[i][j]+nw[j]);
		}
		for (long long i=1;i<=cnt;i++) nw[i]=t[i];
		printf("%I64d\n",nw[1]);
		return 0;
	}
	cs=binpow(ma,p[1].first-k-1);
	for (long long i=1;i<=cnt;i++)
	{
		t[i]=1e18;
		for (long long j=1;j<=cnt;j++) t[i]=min(t[i],cs.a[i][j]+nw[j]);
	}
	for (long long i=1;i<=cnt;i++) nw[i]=t[i];
	pre=1;
	for (long long i=1;i<=q;i++)
	{
		if (pre<p[i].first-k) pre=p[i].first-k;
		for (long long j=pre+1;j<=min(n-x+1,p[i].first);j++)
		{
			for (long long h=1;h<=cnt;h++)
			{
				t[h]=1e18;
				for (long long r=1;r<=cnt;r++)
				{
					cur=nw[r]+ma.a[h][r];
					if (mp.find(j+s[h][r])!=mp.end()) cur+=mp[j+s[h][r]];
					t[h]=min(t[h],cur);
				}
			}
			for (long long h=1;h<=cnt;h++) nw[h]=t[h];
		}
		pre=p[i].first;
		if (i<q) 
		{
			cs=binpow(ma,p[i+1].first-k-p[i].first);
			for (long long j=1;j<=cnt;j++)
			{
				t[j]=1e18;
				for (long long h=1;h<=cnt;h++) t[j]=min(t[j],cs.a[j][h]+nw[h]);
			}
			for (long long j=1;j<=cnt;j++) nw[j]=t[j];
		}
		else
		{
			cs=binpow(ma,n-x+1-p[i].first);
			for (long long j=1;j<=cnt;j++)
			{
				t[j]=1e18;
				for (long long h=1;h<=cnt;h++) t[j]=min(t[j],cs.a[j][h]+nw[h]);
			}
			for (long long j=1;j<=cnt;j++) nw[j]=t[j];
		}
	}
	printf("%I64d\n",nw[1]);
	return 0;
}