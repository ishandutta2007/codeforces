#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
const int maxn=2e5+5,M=1e6+5,mod=1e9+7,g=11;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);puts("");
}
int n,m,l,r,cnt=0,tot=0,a[maxn],c[g+1][maxn],h[maxn],p[maxn];
int inv[M],las[M],d[M],s[maxn*65],ls[maxn*65],rs[maxn*65],rt[maxn];
inline int Pow(int x,int y){int res=1;while(y){if(y&1)res=1ll*res*x%mod;x=1ll*x*x%mod;y=y/2;}return res;}
inline void init(){
	inv[0]=inv[1]=1;
	for(int i=2;i<M;i++)inv[i]=1ll*inv[mod%i]*(mod-mod/i)%mod;
	for(int i=2;i<M;i++){
		if(!d[i])d[i]=i,p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<M;j++){d[p[j]*i]=p[j];if(i%p[j]==0)break;}
	}
}
inline void add(int x,int y,int num){for(int i=y;i<=n;i+=lowbit(i))c[x][i]+=num;}
inline int qry(int x,int y){int res=0;for(int i=y;i;i-=lowbit(i))res+=c[x][i];return res;}
inline void upd(int &rt,int rt1,int l,int r,int pos,int x){
	if(l>pos||r<pos)return;
	rt=++tot;s[rt]=s[rt1];ls[rt]=ls[rt1],rs[rt]=rs[rt1];
	if(l==r){s[rt]=1ll*s[rt]*x%mod;return;}
	upd(ls[rt],ls[rt1],l,mid,pos,x),upd(rs[rt],rs[rt1],mid+1,r,pos,x);
	s[rt]=1ll*s[ls[rt]]*s[rs[rt]]%mod;
}
inline void upd(int x,int num){
	upd(rt[x],rt[x],1,n,x,1ll*(num-1)*inv[num]%mod);
	if(las[num])upd(rt[x],rt[x],1,n,las[num],1ll*num*inv[num-1]%mod);
	las[num]=x;
}
inline int query(int rt,int l,int r,int L,int R){
	if(l>R||r<L||!rt)return 1;
	if(l>=L&&r<=R)return s[rt];
	return 1ll*query(ls[rt],l,mid,L,R)*query(rs[rt],mid+1,r,L,R)%mod;
}
inline int query(int l,int r){
	int res=1;for(int i=1;i<=g;i++){
		int u=qry(i,r)-qry(i,l-1);if(u)res=1ll*res*(p[i]-1)%mod;
		if(u>1)res=1ll*res*Pow(p[i],u-1)%mod;
	}
	res=1ll*res*h[r]%mod*Pow(h[l-1],mod-2)%mod;
	res=1ll*res*query(rt[r],1,n,l,r)%mod;return res;
}
signed main(){
	n=read();init();h[0]=1;s[0]=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		for(int j=1;j<=g;j++)while(a[i]%p[j]==0){
			a[i]=a[i]/p[j];add(j,i,1);
		}rt[i]=rt[i-1];h[i]=1ll*h[i-1]*a[i]%mod;
		while(a[i]>1){upd(i,d[a[i]]),a[i]/=d[a[i]];}
	}m=read();
	for(int i=1;i<=m;i++)
		l=read(),r=read(),print(query(l,r));
	return 0;
}