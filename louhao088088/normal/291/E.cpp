// Problem: CF1017E The Supersonic Rocket
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1017E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 2022-03-28 19:30:00
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=3e5+5,M=34005,mod=1e9+7,mod2=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,fa[maxn],t,ans=0;
string a[maxn];vector<int>e[maxn];
char c[maxn],g[maxn];
struct Hash{
	int x,y;
	Hash operator +(const Hash &k)const{return{(x+k.x)%mod,(y+k.y)%mod2};}
	Hash operator -(const Hash &k)const{return{(x-k.x+mod)%mod,(y-k.y+mod2)%mod2};}
	Hash operator *(const Hash &k)const{return{1ll*x*k.x%mod,1ll*y*k.y%mod2};}
	bool operator ==(const Hash &k)const{return x==k.x&&y==k.y;}
}base,fac[maxn],s[maxn],inv[maxn],p;
bool check(int l,int r){
	Hash h=s[r]-s[l-1]*fac[r-l+1];
	if(h==p)return 1;return 0;
}
void dfs(int x,int fa){
	for(auto i:e[x]){
		int len=a[i].length();
		for(int j=0;j<len;j++){
			int o=t+j+1;g[o]=a[i][j];
			s[o]=s[o-1]*base+(Hash){a[i][j],a[i][j]};
			if(o>=m&&check(o-m+1,o))ans++;
		}
		t+=len;dfs(i,x);t-=len;
	}
}
signed main()
{
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();base={137,197};fac[0]={1,1};inv[0]={1,1};
	for(int i=2;i<=n;i++)fa[i]=read(),e[fa[i]].pb(i),cin>>a[i];
	scanf("%s",c+1);m=strlen(c+1);p={0,0};
	for(int i=1;i<=m;i++)
		p=p*base+(Hash){c[i],c[i]};
	for(int i=1;i<=3e5;i++)fac[i]=fac[i-1]*base;
	dfs(1,0);cout<<ans<<endl;
 	return 0;
}