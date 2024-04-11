#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%mod;
		p=1ll*p*p%mod; 
	}
	return res;
}
struct mat
{
	int a[2][2];
	mat()
	{
		a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;
	}
	mat operator * (const mat &u) const
	{
		mat res;
		for (int i=0;i<2;i++)
		{
			for (int j=0;j<2;j++)
			{
				res.a[i][j]=0;
				for (int k=0;k<2;k++)
				{
					res.a[i][j]=(1ll*a[i][k]*u.a[k][j]+res.a[i][j])%mod;
				}
			}
		}
		return res;
	}
}tree[888888],ma;
void pushup(int node)
{
	tree[node]=tree[node<<1]*tree[(node<<1)|1];
}
void upd(int x,int l,int r,int node,int aa,int b,int c)
{
	if (l==r)
	{
		tree[node].a[aa][b]=c;
		return;
	}
	int mid=(l+r)>>1;
	if (x>mid) upd(x,mid+1,r,(node<<1)|1,aa,b,c);
	else upd(x,l,mid,node<<1,aa,b,c);
	pushup(node);
}
int n,a[111111],v[111111],p[111111],cnt,pr,ct,ans;
struct frac
{
	int x,y,p;
	bool operator < (const frac &u) const
	{
		return 1ll*x*u.y<1ll*y*u.x;
	}
};
pair<pair<frac,int>,pair<int,int> > b[444444];
int query()
{
	return (1ll*p[1]*tree[1].a[1][0]+1ll*p[1]*tree[1].a[1][1]+1ll*(1-p[1])*tree[1].a[0][0]+1ll*(1-p[1])*tree[1].a[0][1])%mod;
}
int main()
{
	scanf("%d",&n);
	int iv=binpow(100,mod-2)%mod;
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a[i],&v[i],&p[i]);
		p[i]=1ll*p[i]*iv%mod;
	}
	for (int i=1;i<n;i++)
	{
		b[++cnt]=make_pair(make_pair((frac){a[i+1]-a[i],v[i]+v[i+1],(1-p[i+1])%mod},i),make_pair(1,0));
		upd(i,1,n-1,1,0,1,p[i+1]);
		if (v[i]==v[i+1])
		{
			upd(i,1,n-1,1,0,0,(1-p[i+1])%mod);
			upd(i,1,n-1,1,1,1,p[i+1]);
		}
		else if (v[i]<v[i+1])
		{
			upd(i,1,n-1,1,1,1,p[i+1]);
			b[++cnt]=make_pair(make_pair((frac){a[i+1]-a[i],v[i+1]-v[i],(1-p[i+1])%mod},i),make_pair(0,0));
		}
		else 
		{
			upd(i,1,n-1,1,0,0,(1-p[i+1])%mod);
			b[++cnt]=make_pair(make_pair((frac){a[i+1]-a[i],v[i]-v[i+1],p[i+1]},i),make_pair(1,1));
		}
	}
	sort(b+1,b+cnt+1);
	pr=query()%mod;
	for (int i=cnt;i>=1;i--)
	{
		ct=1ll*b[i].first.first.x*binpow(b[i].first.first.y,mod-2)%mod;
		upd(b[i].first.second,1,n-1,1,b[i].second.first,b[i].second.second,b[i].first.first.p);
		ans=(1ll*(query()-pr)*ct+ans)%mod;
		pr=query();
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}