#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 131072
#define LL long long
#define P 998244353
#define G 3

int power(int x,int v){
	int ans=1;
	for(;v;v>>=1,x=(LL)x*x%P) if(v&1) ans=(LL)ans*x%P;
	return ans;
}

void NTT(int *a,int n,int f){
	rep(i,0,n-1){
		int y=i,x=0;
		for(int k=1;k<n;k<<=1,y>>=1) (x<<=1)|=(y&1);
		if(i>x) swap(a[i],a[x]);
	}
	for(int i=2;i<=n;i<<=1){
		int wn=power(power(G,(P-1)/n),n/i);
		if(f) wn=power(wn,P-2);
		for(int j=0;j<n;j+=i){
			int w=1;
			for(int k=0;k<i>>1;k++){
				int x,y;
				x=a[j+k];
				y=(LL)a[j+k+(i>>1)]*w%P;
				a[j+k]=(x+y)%P;
				a[j+k+(i>>1)]=(x-y+P)%P;
				w=(LL)w*wn%P;
			}
		}
	}
	if(f){
		int inv=power(n,P-2);
		rep(i,0,n-1) a[i]=(LL)a[i]*inv%P;
	}
}

void getinv(int *a,int *b,int n){
	*b=power(*a,P-2);
	static int c[N<<2]={0};
	for(int t=2;t<=n;t<<=1){
		rep(i,0,t-1) c[i]=a[i];
		NTT(c,t<<1,0),NTT(b,t<<1,0);
		rep(i,0,t<<1) c[i]=(2-(LL)c[i]*b[i]%P+P)%P;
		rep(i,0,t<<1) c[i]=(LL)c[i]*b[i]%P;
		//if(t==n){rep(i,0,t<<1) b[i]=c[i],c[i]=0;return;}
		NTT(c,t<<1,1);
		rep(i,0,t-1) b[i]=c[i];
		rep(i,t,t<<1) b[i]=0;
		rep(i,0,t<<1) c[i]=0;
	}
}

void getsqrt(int *a,int *b,int n){
	static int c[N<<2]={0},v[N<<2]={0},ii[N<<2]={0};
	int inv2=power(2,P-2);
	*b=*v=1;
	for(int t=2;t<=n;t<<=1){
		getinv(b,v,t);
		rep(i,0,t-1) c[i]=a[i];
		NTT(c,t<<1,0),NTT(v,t<<1,0);
		rep(i,0,t<<1) c[i]=(LL)c[i]*v[i]%P,v[i]=0;
		NTT(c,t<<1,1);
		rep(i,0,t-1) b[i]=(LL)(b[i]+c[i])%P*inv2%P;
	}
}

int n,m,a[N<<2],b[N<<2],c[N<<2],x;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&x),a[x]++;
	for(n=1;n<=m;n<<=1);
	rep(i,1,m) a[i]=(-4ll*a[i]%P+P)%P;
	a[0]=1;
	getsqrt(a,b,n);
	b[0]++;
	rep(i,0,n-1) b[i]=(LL)b[i]*(P+1)/2%P;
	getinv(b,c,n);
	rep(i,1,m) printf("%d\n",c[i]);
}