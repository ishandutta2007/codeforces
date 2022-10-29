#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = 410000;
 
int n,m;
int a[maxn],b[maxn];
struct node
{
	int ai,i;
}p[maxn];
inline bool cmp(const node &k1,const node &k2){ return k1.ai==k2.ai?k1.i>k2.i:k1.ai<k2.ai; }
 
int seg[maxn<<2];
void build(const int x,const int l,const int r)
{
	seg[x]=-1;
	if(l==r) return;
	int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
	build(lc,l,mid); build(rc,mid+1,r);
}
int loc,c;
void upd(const int x,const int l,const int r)
{
	if(l==r)
	{
		seg[x]=max(seg[x],c);
		return;
	}
	int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
	if(loc<=mid) upd(lc,l,mid);
	else upd(rc,mid+1,r);
	seg[x]=max(seg[lc],seg[rc]);
}
int lx,rx;
int query(const int x,const int l,const int r)
{
	if(rx<l||r<lx) return -1;
	if(lx<=l&&r<=rx) return seg[x];
	int mid=(l+r)>>1,lc=x<<1,rc=lc|1;
	return max(query(lc,l,mid),query(rc,mid+1,r));
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		p[i].i=i,p[i].ai=a[i];
		m=max(m,a[i]);
	}
	sort(p+1,p+n+1,cmp);
	m+=n;
	
	build(1,0,m);
	loc=n,c=0,upd(1,0,m);
	
	for(int i=1;i<=n;i++)
	{
		lx=n+p[i].ai-p[i].i,rx=m;
		
		int k=query(1,0,m);
		if(k!=-1)
		{
			int kc=k+1;
			loc=n+p[i].ai-p[i].i;
			c=kc;
			upd(1,0,m);
		}
	}
	lx=0,rx=m;
	cout<<query(1,0,m)<<endl;
	
	return 0;
}