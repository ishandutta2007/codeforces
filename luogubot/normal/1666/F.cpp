#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long 
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=5e3+10,p=998244353;
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
int n,f[N>>1][N],cnt[N],s[N];
int fac[N],ifac[N]; 
signed main(){
	n=5e3;fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	int T=read();while(T--){
		memset(cnt,0,sizeof cnt);
		For(i,1,n=read())cnt[read()]++;
		int v=1;For(i,1,n)(v*=ifac[cnt[i]])%=p;
		For(i,1,n)s[i]=s[i-1]+cnt[i];
//		For(i,1,n)For(j,1,n)f[i][j]=0;
		For(j,1,n)f[1][j]=(cnt[j]*s[j-1]%p*(s[j-1]-1)%p+f[1][j-1])%p;
		int ans=0;
		if(n==2)For(j,1,n)(ans+=cnt[j]*s[j-1])%=p;
		For(i,1,n/2-1)For(k,1,n){
			f[i+1][k]=cnt[k]*f[i][k-1]%p;
			if(i+1==n/2)(ans+=f[n/2][k])%=p;
			f[i+1][k]=((s[k-1]-2*(i+1)+1)*f[i+1][k]+f[i+1][k-1])%p;
		}
		(ans*=v)%=p,printf("%lld\n",ans);
	}
	return 0;
}