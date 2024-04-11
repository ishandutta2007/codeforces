#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1<<19|1;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
const double PI=acos(-1);
struct comp{
	double x,y;
	inline comp(double x_=0,double y_=0):x(x_),y(y_){}
	inline comp operator+(const comp &k){return {x+k.x,y+k.y};}
	inline comp operator-(const comp &k){return {x-k.x,y-k.y};}
	inline comp operator*(const comp &k){return {x*k.x-y*k.y,x*k.y+k.x*y};}
}f[2][maxn];
int a[maxn],all,bf[maxn],cnt[maxn],k,n,pre[maxn];
inline void dft(comp *f,int v){
	for(ri i=0;i<all;++i)swap(f[i],f[bf[i]]);
	for(ri k=1,kk=2;kk<=all;k<<=1,kk<<=1){
		comp wn(cos(PI/k),v*sin(PI/k));
		for(ri i=0;i<all;i+=kk){
			comp w(1,0);
			for(ri j=0;j<k;++j,w=w*wn){
				comp x=f[i|j],y=w*f[i|j|k];
				f[i|j]=x+y,f[i|j|k]=x-y;
			}
		}
	}
	if(v==-1)
		for(ri i=0;i<all;++i)
			f[i].x/=all;
}
inline ll solve_0(){
	ri lst=0;
	ll ret=0;
	for(ri i=1;i<=n;++i){
		if(a[i]<k)lst=i;
		else ret+=i-lst;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	++cnt[0];
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		++cnt[pre[i]=pre[i-1]+(a[i]<k)];
	}
	for(all=1;all<=n+n;all<<=1);
	for(ri i=0;i<all;++i)bf[i]=(bf[i>>1]>>1)|((i&1)?(all>>1):0);
	for(ri i=0;i<all;++i)ckmax(bf[i],i);
	for(ri i=0;i<=n;++i)f[0][i].x=f[1][n-i].x=cnt[i];
	dft(f[0],1),dft(f[1],1);
	for(ri i=0;i<all;++i)f[0][i]=f[0][i]*f[1][i];
	dft(f[0],-1);
	printf("%lld",solve_0());
	for(ri i=1;i<=n;++i)printf(" %lld",(ll)(f[0][i+n].x+0.5));
	return 0;
}