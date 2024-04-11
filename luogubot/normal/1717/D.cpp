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
const int N=5e6+10,p=1e9+7;
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
signed main(){
	int n=read(),k=read(),ans=0;init();
	For(i,0,min(n,k))(ans+=C(n,i))%=p;cout<<ans<<endl;
	return 0;
}