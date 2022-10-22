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
const int N=288,p=998244353;
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
int n,m,f[N][N];
int fac[N],ifac[N];
int sum(int l,int r){return (l+r)*(r-l+1)/2;}
inline int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
signed main(){
	n=250;fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	n=read()-1,m=read();
	f[0][m+1]=1;
	For(i,0,n){
		Rof(k,m,1)(f[i][k]+=f[i][k+1])%=p;
		For(x,1,n-i)For(k,1,m){
			(f[i+x][k]+=inv(k,sum(i,i+x-1))*C(n-i,x)%p*f[i][k+1])%=p;
		}
	}cout<<f[n][1]<<endl;
//	For(i,1,n)For(k,1,m)printf("f[%d][%d] = %d\n",i,k,f[i][k]-f[i][k+1]);
	return 0;
}