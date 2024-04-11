#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid ((l+r)>>1)
#define lowbit(x) (x&-x)
#define int long long
const int maxn=1e6+5,M=34005,mod=1e9+9;
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
    while(top) putchar(a[--top]+48);
}
int n,m,l,r,op,a[maxn],f[maxn],g[maxn],s1[maxn*4],s[maxn],tag1[maxn*4],tag2[maxn*4];
void pushx(int rt,int l,int r,int x,int x2){
	s1[rt]=(s1[rt]+x*(s[r+1]-s[l]))%mod;tag1[rt]+=x;tag1[rt]%=mod;
	s1[rt]=(s1[rt]+x2*(s[r]-s[l-1]))%mod;tag2[rt]+=x2;tag2[rt]%=mod;
}
void push(int rt,int l,int r){
	if(tag1[rt]||tag2[rt]){
		pushx(ls,l,mid,tag1[rt],tag2[rt]);
		pushx(rs,mid+1,r,tag1[rt],tag2[rt]);
		tag1[rt]=tag2[rt]=0;
	}
}
void build(int rt,int l,int r){
	if(l==r){s1[rt]=a[l];return;}
	build(ls,l,mid),build(rs,mid+1,r);
	s1[rt]=s1[ls]+s1[rs]+mod;s1[rt]%=mod;
}
void add(int rt,int l,int r,int L,int R,int x,int x2){
	if(l>R||r<L)return ;
	if(l>=L&&r<=R){pushx(rt,l,r,x,x2);return;}
	push(rt,l,r);add(ls,l,mid,L,R,x,x2);add(rs,mid+1,r,L,R,x,x2);
	s1[rt]=s1[ls]+s1[rs]+mod;s1[rt]%=mod;
}
int query(int rt,int l,int r,int L,int R){
	if(l>R||r<L)return 0;
	if(l>=L&&r<=R)return s1[rt];push(rt,l,r);
	return (query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R)+mod)%mod;
}
signed main(){
	//freopen("1.in","r",stdin);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	g[0]=0,g[1]=1;s[1]=1;build(1,1,n);
	for(int i=2;i<=n+5;i++)g[i]=g[i-2]+g[i-1],g[i]%=mod,s[i]=(s[i-1]+g[i])%mod;
	f[0]=0,f[1]=1;
	for(int i=2;i<=n+5;i++)f[i]=f[i-2]-f[i-1]+mod,f[i]%=mod;
	for(int i=1;i<=m;i++){
		op=read(),l=read(),r=read();
	//	for(int j=1;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
		if(op==1)add(1,1,n,l,r,f[l-1],f[l]);
		else printf("%lld\n",query(1,1,n,l,r));
	}
}