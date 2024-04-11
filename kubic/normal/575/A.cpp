#include <bits/stdc++.h>
using namespace std;
#define N 50005
#define ll long long
#define mid ((l+r)>>1)
int n,m,p,tp,lst,a[N];ll c; 
struct Matrix
{
	int a[2][2];
	Matrix(bool fl=0)
	{a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;if(fl) a[0][0]=a[1][1]=1;}
	Matrix operator * (Matrix t)
	{
		Matrix res;
		res.a[0][0]=(1ll*a[0][0]*t.a[0][0]+1ll*a[0][1]*t.a[1][0])%p;
		res.a[0][1]=(1ll*a[0][0]*t.a[0][1]+1ll*a[0][1]*t.a[1][1])%p;
		res.a[1][0]=(1ll*a[1][0]*t.a[0][0]+1ll*a[1][1]*t.a[1][0])%p;
		res.a[1][1]=(1ll*a[1][0]*t.a[0][1]+1ll*a[1][1]*t.a[1][1])%p;
		return res;
	}
	Matrix operator *= (Matrix t) {return (*this)=(*this)*t;}
}ans(1),tmp,mat[N],sg[N*4];
struct Node {int vl,fl;ll x,bl;}st[N*2];
bool cmp(Node x,Node y) {return x.x<y.x;}
void pu(int p) {sg[p]=sg[p<<1]*sg[p<<1|1];}
void build(int p,int l,int r)
{
	if(l==r) {sg[p]=mat[l];return;}
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int x,Matrix vl)
{
	if(l==r) {sg[p]=vl;return;}
	if(x<=mid) upd(p<<1,l,mid,x,vl);
	else upd(p<<1|1,mid+1,r,x,vl);pu(p);
}
Matrix qPow(Matrix x,ll y)
{Matrix res(1);for(;y;y/=2,x*=x) if(y&1) res*=x;return res;}
int main()
{
	scanf("%lld %d %d",&c,&p,&n);if(!c) {puts("0");return 0;}
	for(int i=0;i<n;++i) scanf("%d",&a[i]);
	for(int i=0;i<n;++i)
		mat[i].a[0][0]=a[(i+1)%n],mat[i].a[0][1]=1,mat[i].a[1][0]=a[i];
	build(1,0,n-1);scanf("%d",&m);
	for(int i=1,vl;i<=m;++i)
	{
		ll x;scanf("%lld %d",&x,&vl); 
		if(x && x<c) st[++tp]=(Node) {vl,0,x+1,(x-1)/n+1};
		if(x+1<c) st[++tp]=(Node) {vl,1,x+2,x/n+1};
	}sort(st+1,st+tp+1,cmp);
	for(int i=1,j=1,t;i<=tp && st[i].bl<(c-2)/n+1;i=j)
	{
		ans*=qPow(sg[1],st[i].bl-st[i-1].bl-1);
		while(j<=tp && st[i].bl==st[j].bl) ++j;lst=j-1;
		for(int k=i;k<j;++k)
		{
			t=(st[k].x-2)%n;if(k==i || st[k].x>st[k-1].x) tmp=mat[t];
			tmp.a[st[k].fl][0]=st[k].vl;
			if(k==j-1 || st[k].x<st[k+1].x) upd(1,0,n-1,t,tmp); 
		}ans*=sg[1];
		for(int k=i;k<j;++k) if(st[k].x>st[k-1].x)
			t=(st[k].x-2)%n,upd(1,0,n-1,t,mat[t]);
	}ans*=qPow(sg[1],(c-2)/n-st[lst].bl);
	for(int i=lst+1;i<=tp;++i)
		mat[(st[i].x-2)%n].a[st[i].fl][0]=st[i].vl;
	for(int i=0;i<=(c-2)%n;++i) ans*=mat[i];
	printf("%d\n",ans.a[0][0]);return 0;
}