#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define db double
#define mid ((l+r)/2)
const db INF=1e18;
int n,m,a[N];db c1,c2;
struct Matrix
{
	db a[3][3];
	Matrix operator * (Matrix t) const
	{
		Matrix res;
		for(int i=0;i<3;++i) for(int j=0;j<3;++j)
			res.a[i][j]=max({a[i][0]+t.a[0][j],a[i][1]+t.a[1][j],a[i][2]+t.a[2][j]});
		return res;
	}
}sg[N*4];
Matrix f(int vl)
{
	return (Matrix)
	{
		{
			{0,0,0},
			{vl/(c1+c2),vl/(c1+c2),-INF},
			{vl/c2,-INF,-INF}
		}
	};
}
void pu(int p) {sg[p]=sg[p*2]*sg[p*2+1];}
void build(int p,int l,int r)
{
	if(l==r) {sg[p]=f(a[l]);return;}
	build(p*2,l,mid);build(p*2+1,mid+1,r);pu(p);
}
void upd(int p,int l,int r,int x,int vl)
{
	if(l==r) {sg[p]=f(vl);return;}
	if(x<=mid) upd(p*2,l,mid,x,vl);
	else upd(p*2+1,mid+1,r,x,vl);pu(p);
}
Matrix qry(int p,int l,int r,int qL,int qR)
{
	if(l>=qL && r<=qR) return sg[p];Matrix tL,tR;
	if(qL<=mid) tL=qry(p*2,l,mid,qL,qR);
	if(qR>mid) tR=qry(p*2+1,mid+1,r,qL,qR);
	if(qL<=mid && qR>mid) return tL*tR;
	if(qL<=mid) return tL;return tR;
}
int main()
{
	scanf("%d %d %lf %lf",&n,&m,&c1,&c2);if(c1>c2) swap(c1,c2);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);build(1,1,n);
	for(int i=1,F[3];i<=m;++i)
	{
		scanf("%d %d %d",&F[0],&F[1],&F[2]);
		if(F[0]==1) upd(1,1,n,F[1],F[2]);
		if(F[0]==2)
		{
			Matrix t=qry(1,1,n,F[1],F[2]);
			printf("%.10lf\n",max({t.a[0][0],t.a[1][0],t.a[2][0]}));
		}
	}return 0;
}