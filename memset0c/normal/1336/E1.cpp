#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
const int N=60,mod=998244353;
int n,m,k,t,c[N];
long long f[N],g[N];
struct z {
	int x;
	z(int x=0):x(x){}
	friend inline z operator*(z a,z b){return (long long)a.x*b.x%mod;}
	friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+mod:a.x;}
	friend inline z operator+(z a,z b){return (a.x+=b.x)>=mod?a.x-mod:a.x;}
}p[N],q[N],fac[N],ifac[N];
inline z C(int n,int m){return n<m?0:fac[n]*ifac[m]*ifac[n-m];}
inline z fpow(z a,int b){z s=1;for(;b;b>>=1,a=a*a)if(b&1)s=s*a;return s;}
inline void insert(long long x){for(int i=m-1;i>=0;i--)if((x>>i)&1){if(f[i])x^=f[i]; else {f[i]=x; return;}}}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m);
	for(int i=1;i<=n;i++){long long x; read(x),insert(x);}
	for(int i=0;i<m;i++)for(int j=i+1;j<m;j++)if((f[j]>>i)&1)f[j]^=f[i];
	for(int i=0;i<m;i++)if(f[i])c[i]=k++;
	for(int i=0;i<m;i++)if(!f[i])c[i]=k+(t++);
	for(int i=0;i<m;i++)if(f[i])for(int j=0;j<m;j++)if((f[i]>>j)&1)g[c[i]]|=1ll<<c[j];
	for(int i=0;i<k;i++)for(int j=k;j<m;j++)if((g[i]>>j)&1)g[j]|=1ll<<i;
	for(int i=k;i<m;i++)g[i]|=1ll<<i;
	// for(int i=0;i<m;i++){for(int j=0;j<m;j++)putchar('0'+((g[i]>>j)&1));putchar('\n');}
	if(k<=((m+1)>>1)){
		std::function<void(int,long long)> dfs=[&](int i,long long s){
			if(i>=k){p[__builtin_popcountll(s)].x++;return;}
			dfs(i+1,s),dfs(i+1,s^g[i]);
		};
		dfs(0,0ll);
	}else{
		std::function<void(int,long long)> dfs=[&](int i,long long s){
			if(i>=m){q[__builtin_popcountll(s)].x++;return;}
			dfs(i+1,s),dfs(i+1,s^g[i]);
		};
		dfs(k,0ll);
		fac[0]=ifac[0]=ifac[1]=1;
		for(int i=1;i<=m;i++)fac[i]=fac[i-1]*i;
		for(int i=2;i<=m;i++)ifac[i]=(mod-mod/i)*ifac[mod%i];
		for(int i=1;i<=m;i++)ifac[i]=ifac[i-1]*ifac[i];
		for(int c=0;c<=m;c++)for(int d=0;d<=m;d++)for(int i=0;i<=c;i++){
			p[c]=p[c]+fpow(2,mod-1+k-m)*q[d]*(i&1?mod-1:1)*C(d,i)*C(m-d,c-i);
		}
	}
	for(int i=0;i<=m;i++)printf("%d%c",(p[i]*fpow(2,n-k)).x," \n"[i==m]);
}