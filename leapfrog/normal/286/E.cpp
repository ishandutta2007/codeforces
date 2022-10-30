// 
//  
// 
//  
//   
#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
struct comp
{
	double x,y;
	inline comp operator+(comp b) const {return(comp){x+b.x,y+b.y};}
	inline comp operator-(comp b) const {return(comp){x-b.x,y-b.y};}
	inline comp operator*(double b) const {return(comp){x*b,y*b};}
	inline comp operator/(double b) const {return(comp){x/b,y/b};}
	inline comp operator*(comp b) const {return(comp){x*b.x-y*b.y,x*b.y+y*b.x};}
}A[4000005],B[4000005];int n,m,r[4000005],a[4000005],b[4000005];
inline void FFT(int n,comp *a,int fla)
{
	for(int i=0;i<n;i++) if(r[i]<i) swap(a[i],a[r[i]]);
	for(int d=1;d<n;d<<=1)
	{
		comp wn=(comp){cos(pi/d),sin(pi/d)*fla},w;
		for(int i=0,k;i<n;i+=(d<<1))
			for(k=0,w=(comp){1,0};k<d;k++,w=w*wn)
				{comp x=a[i+k],y=w*a[i+k+d];a[i+k]=x+y,a[i+k+d]=x-y;}
	}
	if(fla==-1) for(int i=0;i<n;i++) a[i]=a[i]/n;
}
inline void times(int n,int *a,int m,int *b,int &l,int *c)
{
	int T=1;r[0]=0;while(T<=n+m) T<<=1;
	for(int i=0;i<T;i++) r[i]=((r[i>>1]>>1)|((i&1)?(T>>1):0));
	for(int i=0;i<T;i++) A[i]=B[i]=(comp){0,0};
	for(int i=0;i<=n;i++) A[i].x=a[i];
	for(int i=0;i<=m;i++) B[i].x=b[i];
	FFT(T,A,1),FFT(T,B,1);
	for(int i=0;i<T;i++) A[i]=A[i]*B[i];
	FFT(T,A,-1),l=n+m;
	for(int i=0;i<=l;i++) c[i]=(int)(A[i].x+0.5);
}
int main()
{
	scanf("%d%d",&n,&m),memset(a,0,sizeof(a));int l,res=0;
	for(int i=1,x;i<=n;i++) scanf("%d",&x),a[x]=1;
	a[0]=1,times(m,a,m,a,l,b);
	// for(int i=0;i<=l;i++) printf("%d%c",b[i],i==l?'\n':' ');
	for(int i=1;i<=m;i++) if(b[i]&&!a[i]) return puts("NO"),0;else if(b[i]==2&&a[i]) res++;
	puts("YES"),printf("%d\n",res);
	for(int i=1;i<=m;i++) if(b[i]==2&&a[i]) printf("%d ",i);
	return puts(""),0;
}