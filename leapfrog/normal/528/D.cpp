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
	inline comp operator*(comp b) const {return(comp){x*b.x-y*b.y,x*b.y+y*b.x};}
	inline comp operator*(double c) const {return(comp){x*c,y*c};}
	inline comp operator/(double c) const {return(comp){x/c,y/c};}
}a[800005],b[800005];
int n,m,k,T,res,r[800005],cnt[800005];char s[200005],t[200005];
inline void FFT(int n,comp *a,int fla)
{
	for(int i=0;i<n;i++) if(r[i]<i) swap(a[i],a[r[i]]);
	for(int d=1;d<n;d<<=1)
	{
		comp wn=(comp){cos(pi/d),sin(pi/d)*fla},w;
		for(int i=0,k;i<n;i+=(d<<1))
			for(k=0,w=(comp){1.0,0.0};k<d;k++,w=w*wn)
				{comp x=a[i+k],y=a[i+k+d]*w;a[i+k]=x+y,a[i+k+d]=x-y;}
	}
	if(fla==-1) for(int i=0;i<T;i++) a[i]=a[i]/n;
}
inline void solve(char c)
{
	for(int i=0;i<T;i++) a[i]=(comp){0.0,0.0},b[i]=(comp){0.0,0.0};
	for(int i=0,lst=-1e9;i<n;i++) {if(s[i]==c) lst=i;if((i-lst)<=k) a[i]=(comp){1.0,0};}
	for(int i=n-1,lst=1e9;i>=0;i--) {if(s[i]==c) lst=i;if((lst-i)<=k) a[i]=(comp){1.0,0};}
	for(int i=0;i<m;i++) if(t[i]==c) b[m-i-1]=(comp){1.0,0};
	FFT(T,a,1),FFT(T,b,1);
	for(int i=0;i<T;i++) a[i]=a[i]*b[i];
	FFT(T,a,-1);
	for(int i=0;i<n;i++) cnt[i]+=(int)(a[i].x+0.5);
}
signed main()
{
	scanf("%d%d%d%s%s",&n,&m,&k,s,t),T=1,r[0]=0,res=0;
	while(T<=n+m) T<<=1;
	for(int i=0;i<T;i++) r[i]=((r[i>>1]>>1)|((i&1)?(T>>1):0));
	solve('A'),solve('C'),solve('G'),solve('T');
	for(int i=0;i<n;i++) if(cnt[i]==m) res++;
	return printf("%d\n",res),0;
}