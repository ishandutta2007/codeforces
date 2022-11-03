#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define N 1048576
#define LL long long

int c[N],n,m;
LL t,P,a[N],b[N];

LL mult(LL a,LL b){
	return (a*b-(LL)((long double)a*b/P)*P)%P;
}

LL power(LL x,LL v){
	LL ans=1;
	for(;v;v>>=1,x=mult(x,x)) if(v&1) ans=mult(ans,x);
	return ans;
}

void xorDFT(LL *a,int n){
	for(int i=1;i<n;i<<=1)
		for(int j=0;j<n;j+=i<<1)
			for(int k=0;k<i;k++){
				LL x=a[j+k],y=a[j+k+i];
				a[j+k]=(x+y)%P;
				a[j+k+i]=(x-y+P)%P;
			}
}

int main(){
	scanf("%d%I64d%I64d",&n,&t,&P),m=1<<n,P<<=n;
	rep(i,0,m-1) scanf("%I64d",a+i);
	rep(i,0,n) scanf("%d",c+i);
	rep(i,0,m-1){
		int cnt=0,j=i;
		while(j) cnt+=j&1,j>>=1;
		b[i]=c[cnt];
	}
	xorDFT(a,m);
	xorDFT(b,m);
	rep(i,0,m-1) a[i]=mult(a[i],power(b[i],t));
	xorDFT(a,m);
	rep(i,0,m-1) printf("%I64d\n",a[i]>>n);
}