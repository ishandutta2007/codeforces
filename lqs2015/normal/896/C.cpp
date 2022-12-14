#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int seed,n,m,vmax,x,op,l,r,y;
int rnd()
{
	int ret=seed;
	seed=(7ll*seed+13)%mod;
	return ret;
}
int binpow(int a,int t)
{
	int res=1,p=a;
	for (int i=t;i;i>>=1)
	{
		if (i&1) res=1ll*res*p%y;
		p=1ll*p*p%y;
	}
	return res;
}
struct node
{
	int l,r;
	long long val;
	bool operator < (const node &u) const
	{
		if (l!=u.l) return l<u.l;
		return r<u.r;
	}
}fuck;
set<node> s;
set<node>::iterator it,itt;
pair<long long,int> a[111111];
int crt;
void split(set<node>::iterator &it,int x)
{
	int l=it->l,r=it->r;
	long long v=it->val;
	s.erase(it);
	if (x>=l) s.insert((node){l,x,v});
	if (x<r) s.insert((node){x+1,r,v});
}
void prex(int l,int r)
{
	it=s.lower_bound((node){l+1,0,0});it--;
	split(it,l-1);
	it=s.lower_bound((node){r+1,0,0});it--;
	split(it,r);
	it=s.lower_bound((node){l,0,0});
}
void add(int l,int r,int x)
{
	prex(l,r);
	for (;it!=s.end() && (it->r)<=r;it=itt)
	{
		itt=it;itt++;
		fuck=*it;s.erase(it);
		fuck.val+=x;
		s.insert(fuck);
	}
}
void fill(int l,int r,int x)
{
	prex(l,r);
	for (;it!=s.end() && (it->r)<=r;it=itt)
	{
		itt=it;itt++;
		s.erase(it);
	}
	s.insert((node){l,r,(long long)x});
}
long long query(int l,int r,int x)
{
	prex(l,r);
	crt=0;
	for (;it!=s.end() && (it->r)<=r;it++)
	{
		a[++crt]=make_pair(it->val,(it->r)-(it->l)+1);
	}
	sort(a+1,a+crt+1);
	int lst=x;
	for (int i=1;i<=crt;i++)
	{
		if (a[i].second>=lst) return a[i].first;
		lst-=a[i].second;
	}
	return 0;
}
int ksm(int l,int r,int x,int y)
{
	prex(l,r);
	int res=0;
	for (;it!=s.end() && (it->r)<=r;it++)
	{
		res=(1ll*binpow((it->val)%y,x)*((it->r)-(it->l)+1)+res)%y;
	}
	return res;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for (int i=1;i<=n;i++)
	{
		x=rnd()%vmax+1;
		s.insert((node){i,i,x});
	}
	for (int i=1;i<=m;i++)
	{
		op=rnd()%4+1;
		l=rnd()%n+1;
		r=rnd()%n+1;
		if (l>r) swap(l,r);
		if (op==3)
		{
			x=rnd()%(r-l+1)+1;
		}
		else
		{
			x=rnd()%vmax+1;
		}
		if (op==4)
		{
			y=rnd()%vmax+1;
		}
		if (op==1) add(l,r,x);
		else if (op==2) fill(l,r,x);
		else if (op==3) printf("%lld\n",query(l,r,x));
		else printf("%d\n",ksm(l,r,x,y));
	}
	return 0;
}