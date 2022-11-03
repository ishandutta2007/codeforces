#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 1000005
#define LD double
#define LL long long
const LD pi=acos(-1.0);

struct complex{
	LD re,im;
	complex(LD re=0,LD im=0):re(re),im(im){}
}b[N<<2];

complex operator +(const complex &a,const complex &b){return complex(a.re+b.re,a.im+b.im);}
complex operator -(const complex &a,const complex &b){return complex(a.re-b.re,a.im-b.im);}
complex operator *(const complex &a,const complex &b){return complex(a.re*b.re-a.im*b.im,a.re*b.im+a.im*b.re);}

void DFT(complex *a,int n,int f){
	rep(i,0,n-1){
		int y=i,x=0;
		for(int k=1;k<n;k<<=1,y>>=1) (x<<=1)|=(y&1);
		if(x>i) swap(a[i],a[x]);
	}
	complex x,y;
	for(int i=2;i<=n;i<<=1){
		complex wn(cos(2*pi/i),f*sin(2*pi/i));
		for(int j=0;j<n;j+=i){
			complex w(1);
			for(int k=0;k<i>>1;k++){
				x=a[j+k];
				y=a[j+k+(i>>1)]*w;
				a[j+k]=x+y;
				a[j+k+(i>>1)]=x-y;
				w=w*wn;
			}
		}
	}
	if(f==-1) rep(i,0,n-1) a[i].re/=n;
}

int n,m,a[N],ans[N],tmd;

int main(){
	scanf("%d%d",&n,&m);
	for(tmd=1;tmd<=m;tmd<<=1);
	rep(i,1,n) scanf("%d",a+i),b[a[i]].re=1;
	DFT(b,tmd<<1,1);
	rep(i,0,tmd<<1) b[i]=b[i]*b[i];
	DFT(b,tmd<<1,-1);
	rep(i,1,n){
		if((int)(b[a[i]].re+0.5)==0) ans[++*ans]=a[i];
		b[a[i]].re=0;
	}
	rep(i,0,m) if((int)(b[i].re+0.5)){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%d\n",*ans);
	rep(i,1,*ans) printf("%d ",ans[i]);
}