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
const int N=1e6+10,p=998244353;
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
int n,m,ans[N];
struct node{
	int a,b,id;
	bool operator < (const node &x) const {
		return b>x.b;
	}
}q[N];
int d[N],s1,s2,c;
signed main(){
	init(),n=read(),m=read();
	For(i,1,n)s1+=d[i]=read();sort(d+1,d+1+n);
	For(i,1,m)q[i].a=read(),q[i].b=read(),q[i].id=i;
	sort(q+1,q+1+m);int j=n;For(i,1,m){
		while(j>=1&&d[j]>=q[i].b)s1-=d[j],s2+=d[j],j--,c++;
		int a=q[i].a,b=q[i].b,id=q[i].id;
		int v2=C(n,c)*fac[c]%p*fac[n-c]%p*(c-a)%p*inv(c)%p;
		int v1=C(n,c+1)*fac[c+1]%p*fac[n-c-1]%p*(c-a+1)%p*inv(c+1)%p;
		ans[id]=((c>=a)*s1%p*v1+(c>a)*s2%p*v2)%p;
	}For(i,1,m)printf("%lld\n",ans[i]*ifac[n]%p);
	return 0;
}