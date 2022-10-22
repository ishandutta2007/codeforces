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
const int N=1e3+10,p=1e9+7;
int fac[N],ifac[N];
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
void init(int n=N-10){
	fac[0]=1;For(i,1,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
}
int C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%p*ifac[n-m]%p;}
int f[65][N],n,l,r,z;
inline int solve(int S){
	memset(f,0,sizeof f);f[61][0]=1;Rof(i,60,0)For(j,0,n){
		int now=(j<<1)+(S>>i&1);
		if(z>>i&1)for(int k=1;k<=n&&k<=now;k+=2)(f[i][min(n,now-k)]+=f[i+1][j]*C(n,k))%=p;
		else for(int k=0;k<=n&&k<=now;k+=2)(f[i][min(n,now-k)]+=f[i+1][j]*C(n,k))%=p;
	}int ans=0;For(i,0,n)(ans+=f[0][i])%=p;return ans;
}
signed main(){
	init(),n=read(),l=read(),r=read(),z=read();
	cout<<(solve(r)-solve(l-1)+p)%p<<endl;
	return 0;
}//fasdasdas//dsadas