#include<cstdio>
const int N=1e5+5;
int mod,P,K;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int extgcd(int x,int y,int &a,int &b)
{
	if(!x)
		return a=0,b=1,y;
	int g=extgcd(y%x,x,b,a);
	a-=b*(y/x);
	return g;
}
inline int inv(int x)
{
	int a,b;
	extgcd(x,mod,a,b);
	return (a%mod+mod)%mod;
}
int l[N<<2],r[N<<2];
int sum[N<<2],lazy[N<<2];
int sum2[N<<2],lazy2[N<<2];
int sum3[N<<2],lazy3[N<<2];
inline void push_up(int x)
{
	sum[x]=add(sum[x<<1],sum[x<<1|1]);
	sum2[x]=sum2[x<<1]+sum2[x<<1|1];
	sum3[x]=add(sum3[x<<1],sum3[x<<1|1]);
	return;
}
inline void push_down(int x)
{
	if(lazy[x]!=1)
	{
		sum[x<<1]=mul(sum[x<<1],lazy[x]);
		lazy[x<<1]=mul(lazy[x<<1],lazy[x]);
		sum[x<<1|1]=mul(sum[x<<1|1],lazy[x]);
		lazy[x<<1|1]=mul(lazy[x<<1|1],lazy[x]);
		lazy[x]=1;
	}
	if(lazy2[x])
	{
		sum2[x<<1]+=(r[x<<1]-l[x<<1]+1)*lazy2[x];
		lazy2[x<<1]+=lazy2[x];
		sum2[x<<1|1]+=(r[x<<1|1]-l[x<<1|1]+1)*lazy2[x];
		lazy2[x<<1|1]+=lazy2[x];
		lazy2[x]=0;
	}
	if(lazy3[x]!=1)
	{
		sum3[x<<1]=mul(sum3[x<<1],lazy3[x]);
		lazy3[x<<1]=mul(lazy3[x<<1],lazy3[x]);
		sum3[x<<1|1]=mul(sum3[x<<1|1],lazy3[x]);
		lazy3[x<<1|1]=mul(lazy3[x<<1|1],lazy3[x]);
		lazy3[x]=1;
	}
	return;
}
void modify(int x,int ll,int rr,int k)
{
	if(l[x]==ll&&r[x]==rr)
	{
		sum[x]=mul(sum[x],k);
		sum3[x]=mul(sum3[x],k);
		lazy[x]=mul(lazy[x],k);
		lazy3[x]=mul(lazy3[x],k);
		return;
	}
	push_down(x);
	if(rr<=r[x<<1])
		modify(x<<1,ll,rr,k);
	else if(ll>=l[x<<1|1])
		modify(x<<1|1,ll,rr,k);
	else
		modify(x<<1,ll,r[x<<1],k),modify(x<<1|1,l[x<<1|1],rr,k);
	push_up(x);
	return;
}
void modify2(int x,int ll,int rr,int k,int pk)
{
	if(l[x]==ll&&r[x]==rr)
	{
		sum[x]=mul(sum[x],pk);
		sum2[x]+=(r[x]-l[x]+1)*k;
		lazy[x]=mul(lazy[x],pk);
		lazy2[x]+=k;
		return;
	}
	push_down(x);
	if(rr<=r[x<<1])
		modify2(x<<1,ll,rr,k,pk);
	else if(ll>=l[x<<1|1])
		modify2(x<<1|1,ll,rr,k,pk);
	else
		modify2(x<<1,ll,r[x<<1],k,pk),modify2(x<<1|1,l[x<<1|1],rr,k,pk);
	push_up(x);
	return;
}
void modify3(int x,int pos,int k)
{
	if(l[x]==r[x])
	{
		sum[x]=add(sum[x],k);
		return;
	}
	push_down(x);
	if(pos<=r[x<<1])
		modify3(x<<1,pos,k);
	else if(pos>=l[x<<1|1])
		modify3(x<<1|1,pos,k);
	push_up(x);
	return;
}
int query(int x,int ll,int rr)
{
	if(l[x]==ll&&r[x]==rr)
		return sum[x];
	push_down(x);
	if(rr<=r[x<<1])
		return query(x<<1,ll,rr);
	else if(ll>=l[x<<1|1])
		return query(x<<1|1,ll,rr);
	else
		return add(query(x<<1,ll,r[x<<1]),query(x<<1|1,l[x<<1|1],rr));
}
int query2(int x,int ll,int rr)
{
	if(l[x]==ll&&r[x]==rr)
		return sum2[x];
	push_down(x);
	if(rr<=r[x<<1])
		return query2(x<<1,ll,rr);
	else if(ll>=l[x<<1|1])
		return query2(x<<1|1,ll,rr);
	else
		return query2(x<<1,ll,r[x<<1])+query2(x<<1|1,l[x<<1|1],rr);
}
int query3(int x,int ll,int rr)
{
	if(l[x]==ll&&r[x]==rr)
		return sum3[x];
	push_down(x);
	if(rr<=r[x<<1])
		return query3(x<<1,ll,rr);
	else if(ll>=l[x<<1|1])
		return query3(x<<1|1,ll,rr);
	else
		return add(query3(x<<1,ll,r[x<<1]),query3(x<<1|1,l[x<<1|1],rr));
}
int n,q,Q,bmod;
int a[N];
int a3[N],a2[N];
struct cell
{
	int opt;
	int l,r,x;
}c[N];
int pp[50],kk[50],ppkk[50];
int ans[50][N];
void build(int x,int ll,int rr)
{
	l[x]=ll;r[x]=rr;
	lazy[x]=1;lazy2[x]=0;lazy3[x]=1;
	if(ll==rr)
	{
		sum[x]=a[ll]%mod;
		sum2[x]=a2[ll];
		sum3[x]=a3[ll];
		return;
	}
	int mid=(ll+rr)>>1;
	build(x<<1,ll,mid);
	build(x<<1|1,mid+1,rr);
	push_up(x);
	return;
}
signed main()
{
	int idx=0,x,y,z;
	int r1,r2,r3;
	register int i,j,o;
	scanf("%d%d",&n,&bmod);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%d",&c[i].opt);
		if(c[i].opt==1)
			scanf("%d%d%d",&c[i].l,&c[i].r,&c[i].x);
		else if(c[i].opt==2)
			scanf("%d%d",&c[i].l,&c[i].x);
		else
			scanf("%d%d",&c[i].l,&c[i].r),c[i].x=++idx;
	}
	Q=idx;
	x=bmod;idx=0;
	for(i=2;i*i<=bmod;i++)
		if(x%i==0)
		{
			pp[++idx]=i;ppkk[idx]=1;y=0;
			while(x%i==0)
				x/=i,ppkk[idx]*=i,y++;
			kk[idx]=y;
		}
	if(x>1)
		pp[++idx]=x,kk[idx]=1,ppkk[idx]=x;
	for(o=1;o<=idx;o++)
	{
		P=pp[o];K=kk[o];mod=ppkk[o];
		for(i=1;i<=n;i++)
		{
			x=a[i];y=0;
			while(x%P==0)
				x/=P,y++;
			a2[i]=y;a3[i]=x;
		}
		build(1,1,n);
		for(i=1;i<=q;i++)
			if(c[i].opt==1)
			{
				x=c[i].x;y=0;z=1;
				while(x%P==0)
					x/=P,y++,z*=P;
				x%=mod;z%=mod;
				modify(1,c[i].l,c[i].r,x);
				modify2(1,c[i].l,c[i].r,y,z);
			}
			else if(c[i].opt==2)
			{
				x=c[i].x;y=0;
				while(x%P==0)
					x/=P,y++;
				x%=mod;x=inv(x);
				modify(1,c[i].l,c[i].l,x);
				r1=query(1,c[i].l,c[i].l);
				r2=query2(1,c[i].l,c[i].l);
				r3=query3(1,c[i].l,c[i].l);
				modify3(1,c[i].l,sub(0,r1));
				if(r2-y>=K)
					z=0;
				else
				{
					z=1;
					for(j=1;j<=r2-y;j++)
						z*=P;
					z%=mod;
				}
				modify3(1,c[i].l,mul(r3,z));
				modify2(1,c[i].l,c[i].l,-y,1);
			}
			else
				ans[o][c[i].x]=query(1,c[i].l,c[i].r);
	}
	int res;
	for(i=1;i<=Q;i++)
	{
		res=0;
		for(o=1;o<=idx;o++)
		{
			mod=ppkk[o];
			(res+=(long long)ans[o][i]*(bmod/mod)%bmod*inv(bmod/mod)%bmod)%=bmod;
		}
		printf("%d\n",res);
	}
	return 0;
}