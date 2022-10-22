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
const int N=3e5+10,m=3e5,p=998244353;
int n,b[N],a[N];
bitset<N> st;
int pr[N],cnt;
void get(int n=N-10){
	for(int i=2;i<=n;i++){
	    if(!st[i])pr[++cnt]=i;
	    for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
	      	st[i*pr[j]]=1;
	      	if(i%pr[j]==0)break;
	    }
	}
}
int fac[N],ifac[N],s;
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
	get(),init();For(i,1,n=read())b[i]=read(),s=__gcd(s,b[i]);
	if(s>1)return puts("-1"),0;
	For(x,1,7){
		memset(a,0,sizeof a);
		For(i,1,n)a[b[i]]++;
		For(i,1,cnt)Rof(j,m/pr[i],1)(a[j]+=a[pr[i]*j])%=p;
		For(i,1,m)a[i]=C(a[i],x);
		For(i,1,cnt)For(j,1,m/pr[i])(a[j]+=p-a[pr[i]*j])%=p;
		if(a[1])return cout<<x<<endl,0;
	}
	return 0;
}