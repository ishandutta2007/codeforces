#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e6+10;
inline bool ckmax(int &x,const int &y){return x<y?x=y,1:0;}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int n;
double s[maxn];
const double eps=1e-8;
inline bool eq_cmp(double x,double y){
	return fabs(x-y)<eps;
}
template<class T>
struct vec{
	T x,y;
	inline vec<T>(T x_=0,T y_=0):x(x_),y(y_){}
	inline vec<T> operator-(const vec<T> &k){return vec(x-k.x,y-k.y);}
	inline T operator*(const vec<T> &k){return x*k.y-y*k.x;}
	inline T norm(){return x*x+y*y;}
	inline bool operator<(const vec<T> &k)const{return x!=k.x?x<k.x:y<k.y;}
};
template<class T>inline T dot(const vec<T> &x,const vec<T> &y){return x.x*y.x+x.y*y.y;}
using V=vec<ll>;
V o;
inline bool cmp(V x,V y){
	ll det=(x-o)*(y-o);
	return det?det>0:(x-o).norm()<(y-o).norm();
}
inline double angle(V x,V y){
	double COS=1.0*dot(x,y)/sqrt(x.norm())/sqrt(y.norm());
	if(COS<-1)COS=-1;
	if(COS>1)COS=1;
	return acos(COS);
}
inline double angle(V x,V y,V z){
	return angle(y-x,z-y);
}
struct graph{
	int n,tp;
	V a[maxn],st[maxn];
	inline void build_convex(){
		for(ri i=1;i<=n;++i)a[i].x=qr(),a[i].y=qr();
		for(ri i=2;i<=n;++i)
			if(a[i]<a[1])
				swap(a[i],a[1]);
		o=a[1];
		sort(a+2,a+n+1,cmp);
		st[tp=1]=a[1];
		for(ri i=2;i<=n;++i){
			while(tp>1&&(a[i]-st[tp])*(st[tp]-st[tp-1])>=0)--tp;
			st[++tp]=a[i];
		}
	}
	inline void build_string(int times){
		while(times--){
			st[tp+1]=st[1],st[tp+2]=st[2];
			for(ri i=1;i<=tp;++i){
				s[++::n]=(st[i+1]-st[i]).norm();
				s[++::n]=angle(st[i],st[i+1],st[i+2]);
			}
		}
	}
}g1,g2;
int kmp[maxn];
int main(){
	g1.n=qr(),g2.n=qr();
	g1.build_convex();
	g2.build_convex();
	if(g1.tp!=g2.tp)return puts("NO"),0;
	g1.build_string(1);
	g2.build_string(2);
	kmp[1]=0;
	for(ri i=2,j=0;i<=n;++i){
		while(j>0&&!eq_cmp(s[i],s[j+1]))j=kmp[j];
		if(s[i]==s[j+1])++j;
		kmp[i]=j;
		if(kmp[i]>=g1.tp*2)return puts("YES"),0;
	}
	puts("NO");
	return 0;
}