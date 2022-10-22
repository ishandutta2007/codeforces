#include <bits/stdc++.h>
using namespace std;
#define N 55
#define M 105
#define C 20005
#define LIM 1000000
#define db double
#define mid ((l+r)>>1)
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
const db PI=acos(-1);
char buf[LIM],*P1,*P2; 
int n,m,c,h,dst[N];bool vs[N];db P[M][C],A[N][C],B[M][C];
int l,lim=1,r[C*4];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
} 
struct Complex
{
	double x,y;
	Complex(db _x=0,db _y=0) {x=_x;y=_y;}
	Complex operator + (Complex t) {return Complex(x+t.x,y+t.y);}
	Complex operator - (Complex t) {return Complex(x-t.x,y-t.y);}
	Complex operator * (Complex t) {return Complex(x*t.x-y*t.y,x*t.y+y*t.x);}
}tmp1[C*4],tmp2[C*4];
struct Edge {int u,v,w;}e1[M];vector<Edge> e[N];
void getLim(int n)
{
	l=0;lim=1;while(lim<n) ++l,lim<<=1;
	for(int i=0;i<lim;++i) r[i]=(r[i>>1]>>1)|((i&1)<<l-1);
}
void FFT(int fl,Complex a[])
{
	Complex t1,t2,t3,t4;for(int i=0;i<lim;++i) if(i<r[i]) swap(a[i],a[r[i]]);
	for(int i=1;i<lim;i<<=1)
	{
		t1=Complex(cos(PI/i),fl*sin(PI/i));
		for(int j=0;j<lim;j+=i<<1)
		{
			t2=Complex(1,0);
			for(int k=0;k<i;++k,t2=t1*t2)
				t3=a[j+k],t4=t2*a[i+j+k],a[j+k]=t3+t4,a[i+j+k]=t3-t4;
		}
	}if(fl==-1) for(int i=0;i<lim;++i) a[i].x/=lim,a[i].y/=lim;
}
void Dijkstra(int S)
{
	for(int i=1;i<=n;++i) vs[i]=0,dst[i]=1e9;dst[S]=0;
	for(int i=1,t=0;i<=n;++i,t=0)
	{
		for(int j=1;j<=n;++j)
			if(!vs[j] && (!t || dst[j]<dst[t])) t=j;vs[t]=1;
		for(int j=0,v;j<e[t].size();++j)
			v=e[t][j].v,dst[v]=min(dst[v],dst[t]+e[t][j].w);
	}
}
void slv(int l,int r)
{
	if(l==r)
	{
		for(int i=1;i<=m;++i)
			A[e1[i].u][l]=min(A[e1[i].u][l],B[i][l]);return;
	}slv(mid+1,r);getLim(r*2-l-mid); 
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<lim;++j) tmp1[j]=tmp2[j]=(Complex) {0,0};
		for(int j=mid+1;j<=r;++j) tmp1[j-mid-1]=(Complex) {A[e1[i].v][j],0};
		for(int j=1;j<=r-l;++j) tmp2[r-l-j]=(Complex) {P[i][c-j+1],0};
		FFT(1,tmp1);FFT(1,tmp2);
		for(int j=0;j<lim;++j) tmp1[j]=tmp1[j]*tmp2[j];FFT(-1,tmp1);
		for(int j=l;j<=mid;++j) B[i][j]+=tmp1[j+r-l-mid-1].x;
	}slv(l,mid);
}
int main()
{
	n=rd();m=rd();c=rd();h=rd();
	for(int i=1;i<n;++i) for(int j=0;j<=c;++j) A[i][j]=1e9;
	for(int i=1,u,v,w;i<=m;++i)
	{
		u=rd();v=rd();w=rd();
		e1[i]=(Edge) {u,v,w};e[v].push_back((Edge) {v,u,w});
		for(int j=c;j>=1;--j) P[i][j]=1.0*rd()/1e5;
		for(int j=1;j<=c;++j) B[i][j]=B[i][j-1]+P[i][j];
	}Dijkstra(n);
	for(int i=1;i<=m;++i) for(int j=0;j<=c;++j)
		B[i][j]=B[i][j]*(dst[e1[i].v]+h)+e1[i].w;
	slv(0,c);printf("%.7lf\n",A[1][0]);return 0;
}