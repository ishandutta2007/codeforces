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
const int N=110,p=998244353;
int n,X[N],Y[N];
int dis(int i,int j){return abs(X[i]-X[j])+abs(Y[i]-Y[j]);}
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
int d[N][N],mn[N],a[N],m,f[N],used[N],stk[N],tp,g[N],c[N];
signed main(){
	init(); 
	n=read();For(i,1,n)X[i]=read(),Y[i]=read();
	For(i,1,n){
		mn[i]=1e9;
		For(j,1,n)if(i!=j)d[i][j]=dis(i,j),mn[i]=min(mn[i],d[i][j]);
		For(j,1,n)if(i!=j&&d[i][j]==mn[i])c[i]++;
	}
	For(i,1,n)if(!used[i]){
		tp=0;For(j,1,n)if(i!=j&&d[i][j]==mn[i]&&mn[j]==mn[i])stk[++tp]=j;
		stk[++tp]=i;int dd=mn[i],fl=1;For(i,1,tp)For(j,i+1,tp)fl&=d[stk[i]][stk[j]]==dd;
		For(i,1,tp)fl&=c[stk[i]]==tp-1; 
		if(fl){For(i,1,tp)used[stk[i]]=1;a[++m]=tp;}
		else used[i]=1,a[++m]=1;
	}
	f[0]=1;For(i,1,m){
		For(i,0,n)g[i]=f[i],f[i]=0; 
		if(a[i]>1)Rof(j,n,a[i])(f[j]+=g[j-a[i]])%=p;
		Rof(j,n,1)(f[j]+=g[j-1])%=p;
	}
	int ans=0;For(i,1,n)(ans+=f[i]*fac[i]%p*C(n,i)%p)%=p;cout<<ans<<endl;
	return 0;
}