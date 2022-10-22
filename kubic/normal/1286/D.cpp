#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define LIM 1000005
#define MOD 998244353
#define mid ((l+r)/2)
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const int INF=1e9;char *P1,*P2,buf[LIM];
int n,tp,ans,a[N],b[N],p[N];struct Node {int x,w,w1,w2,fl1,fl2;}z[N*4];
bool cmp(Node x,Node y) {return 1ll*x.w1*y.w2>1ll*x.w2*y.w1;}
struct Matrix
{
	int a[2][2];
	Matrix operator * (Matrix t) const
	{
		Matrix res;
		res.a[0][0]=(1ll*a[0][0]*t.a[0][0]+1ll*a[0][1]*t.a[1][0])%MOD;
		res.a[0][1]=(1ll*a[0][0]*t.a[0][1]+1ll*a[0][1]*t.a[1][1])%MOD;
		res.a[1][0]=(1ll*a[1][0]*t.a[0][0]+1ll*a[1][1]*t.a[1][0])%MOD;
		res.a[1][1]=(1ll*a[1][0]*t.a[0][1]+1ll*a[1][1]*t.a[1][1])%MOD;
		return res;
	}
}nw[N],sg[N*4];
int rd()
{
	int res=0;char c=0;bool fl=0;while(!isdigit(c)) fl|=c=='-',c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return fl?-res:res;
}
int qPow(int x,int y)
{int res=1;for(;y;y/=2,x=1ll*x*x%MOD) if(y&1) res=1ll*res*x%MOD;return res;}
void pu(int p) {sg[p]=sg[p*2]*sg[p*2+1];}
void upd(int p,int l,int r,int x)
{
	if(l==r) {sg[p]=nw[l];return;}
	if(x<=mid) upd(p*2,l,mid,x);else upd(p*2+1,mid+1,r,x);pu(p);
}
int main()
{
	n=rd();for(int i=1;i<=n;++i) a[i]=rd(),b[i]=rd(),p[i]=rd();
	for(int i=1;i<n;++i)
	{
		z[++tp]=(Node) {i,0,a[i+1]-a[i],max(b[i+1]-b[i],0),0,0};
		z[++tp]=(Node) {i,0,a[i+1]-a[i],0,0,1};
		z[++tp]=(Node) {i,0,a[i+1]-a[i],b[i]+b[i+1],1,0};
		z[++tp]=(Node) {i,0,a[i+1]-a[i],max(b[i]-b[i+1],0),1,1};
	}sort(z+1,z+tp+1,cmp);
	for(int i=1;i<=tp;++i) z[i].w=1ll*z[i].w1*qPow(z[i].w2,MOD-2)%MOD;
	nw[n].a[0][0]=100-p[n];nw[n].a[1][0]=p[n];upd(1,1,n,n);
	for(int i=1,x,fl1,fl2;i<=tp;++i)
	{
		x=z[i].x;fl1=z[i].fl1;fl2=z[i].fl2;
		nw[x].a[fl1][fl2]+=fl1?p[x]:100-p[x];upd(1,1,n,x);
		ans=(ans+(0ll+sg[1].a[0][0]+sg[1].a[1][0])*(z[i].w-z[i+1].w+MOD))%MOD;
	}printf("%lld\n",1ll*ans*qPow(100,MOD-n-1)%MOD);return 0;
}