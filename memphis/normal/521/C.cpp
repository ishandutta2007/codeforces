#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define P 1000000007
#define N 100005

int n,k,fac[N],inv[N],f[N],w[N],ans,g[N];
char s[N];

int power(int x,int v){
	int ans=1;
	for(;v;v>>=1,x=(LL)x*x%P) if(v&1) ans=(LL)ans*x%P;
	return ans;
}

inline int C(int n,int m){
	if(m>n) return 0;
	if(m<0 || n<0) return 0;
	return (LL)fac[n]*inv[m]%P*inv[n-m]%P;
}

int main(){
	scanf("%d%d",&n,&k);
	fac[0]=1;
	rep(i,1,n) fac[i]=(LL)fac[i-1]*i%P;
	inv[n]=power(fac[n],P-2);
	dep(i,n-1,0) inv[i]=(LL)inv[i+1]*(i+1)%P;
	w[0]=1;
	rep(i,1,n) w[i]=(LL)w[i-1]*10%P;
	rep(i,0,n) f[i]=(LL)w[i]*C(n-i-2,k-1)%P;
	rep(i,1,n) f[i]=(f[i]+f[i-1])%P;
	
	scanf("%s",s+1);
	rep(i,1,n){
		int p=s[i]-'0';
		ans=(ans+(LL)f[n-i-1]*p%P)%P;
		ans=(ans+(LL)w[n-i]*C(i-1,k)%P*p%P)%P;
	}
	printf("%d\n",ans);
}