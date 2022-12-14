// Lynkcat.
// Problem: D. Karen and Cards
// Contest: Codeforces - 10.10
// URL: https://codeforces.com/gym/403227/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
int tr[N<<2],mx[N<<2],tag[N<<2],mn[N<<2];
int n,pp,q,r;
int a[N],b[N],c[N],p[N];

int mb[N],mc[N];
inline void ptag(int k,int l,int r,int x)
{
	tr[k]=x*(r-l+1);
	mx[k]=x;mn[k]=x;
	tag[k]=x;
}
inline void pushdown(int k,int l,int r)
{
	int mid=l+(r-l)/2;
	if (!tag[k]) return;
	int x=tag[k];
	ptag(k<<1,l,mid,x);
	ptag(k<<1|1,mid+1,r,x);
	tag[k]=0;
}
inline void pushup(int k)
{
	tr[k]=tr[k<<1]+tr[k<<1|1];
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
}
void build(int k,int l,int r)
{
	if (l==r) 
	{
		tr[k]=1;
		mx[k]=1;
		mn[k]=1;
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
}
void update(int k,int l,int r,int L,int R,int x)
{
	if (l!=r)
		pushdown(k,l,r);
	int mid=l+(r-l)/2;
	if (L<=l&&r<=R)
	{
		if (l==r)
		{
			if (mx[k]<x)
				ptag(k,l,r,x);
		}
		else
		{
			if (mn[k<<1]>=x)
			{
				update(k<<1|1,mid+1,r,L,R,x);
			}
			else
			{
				ptag(k<<1|1,mid+1,r,x);
				update(k<<1,l,mid,L,R,x);
			}
			pushup(k);
		}
		return;
	}
	if (L<=mid) update(k<<1,l,mid,L,R,x);
	if (R>mid) update(k<<1|1,mid+1,r,L,R,x);
	pushup(k);
}
int query(int k,int l,int r,int L,int R,int x)
{
	// cout<<"?"<<k<<" "<<l<<" "<<r<<" "<<tr[k]<<endl;
	if (l!=r)
		pushdown(k,l,r);
	int mid=l+(r-l)/2;
	if (L<=l&&r<=R)
	{
		if (l==r)
		{
			return max(x,tr[k]);
		}
		else
		{
			if (mn[k<<1]>=x)
			{
				return tr[k<<1]+query(k<<1|1,mid+1,r,L,R,x);
			}
			else
			{
				return (r-mid)*x+query(k<<1,l,mid,L,R,x);
			}
		}
	}
	int res=0;
	if (L<=mid) res+=query(k<<1,l,mid,L,R,x);
	if (R>mid) res+=query(k<<1|1,mid+1,r,L,R,x);
	return res;
}
void BellaKira()
{
	cin>>n>>pp>>q>>r;
	for (int i=1;i<=n;i++)	
		cin>>a[i]>>b[i]>>c[i],p[i]=i;
	build(1,1,q);
	sort(p+1,p+n+1,[&](int x,int y)
	{
		return a[x]<a[y];
	});
	mb[n+1]=1,mc[n+1]=1;
	for (int i=n;i>=1;i--)
		mb[i]=max(mb[i+1],b[p[i]]+1),mc[i]=max(mc[i+1],c[p[i]]+1);
	int ans=0;
	int ans1=0;
	p[n+1]=n+1;
	a[n+1]=pp;
	for (int i=1;i<=n+1;i++)
	{
		// cout<<a[p[i]]<<" "<<b[p[i]]<<" "<<c[p[i]]<<endl;
		if (a[p[i]]!=a[p[i-1]])
		{
			if (mb[i]<=q)
			{
				// cout<<"?"<<query(1,1,q,mb[i],q,mc[i])<<" "<<p[i]<<" "<<mb[i]<<" "<<mc[i]<<endl;
				ans+=(a[p[i]]-a[p[i-1]])
				*((q-mb[i]+1)*(r+1)-query(1,1,q,mb[i],q,mc[i]));
				// int sum=0;
				// for (int j=mb[i];j<=q;j++)
				// {
					// int lf=1;
					// for (int k=1;k<i;k++)
						// if (b[p[k]]>=j) lf=max(lf,c[p[k]]+1);
					// cout<<"?"<<j<<" "<<lf<<" "<<query(1,1,q,j,j,1)<<'\n';
					// sum+=r+1-max(mc[i],lf);
				// }
				// ans1+=(a[p[i]]-a[p[i-1]])*sum;
				// cout<<" "<<ans<<" "<<ans1<<'\n';
				// cout<<i<<" "<<ans<<" "<<query(1,1,q,mb[i],q,mc[i])<<" "<<(q-mb[i]+1)*(r+1)<<'\n';
				// cout<<"?"<<(a[p[i]]-a[p[i-1]])
				// *((q-mb[i]+1)*(r+1)-query(1,1,q,mb[i],q,mc[i]))<<endl;
				// cout<<"----"<<query(1,1,q,1,1,1)<<" "<<query(1,1,q,2,2,1)<<" "<<query(1,1,q,3,3,1)<<" "<<query(1,1,q,4,4,1)<<" "<<
				// (r+1)*(q-mb[i]+1)-query(1,1,q,mb[i],q,2)<<" "<<mb[i]<<" "<<ans<<" "<<
				// ((q-mb[i]+1)*(r+1)-query(1,1,q,mb[i],q,mc[i]))<<" "<<mc[i]<<'\n';
			}
		}
		if (i!=n+1)
			update(1,1,q,1,b[p[i]],c[p[i]]+1);
	}
	cout<<ans<<'\n';
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}