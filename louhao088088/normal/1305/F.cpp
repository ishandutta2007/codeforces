// Problem: CF1305F Kuroni and the Punishment
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1305F
// Memory Limit: 250 MB
// Time Limit: 2500 ms
// 2022-09-19 16:30:17
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
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
const int maxn=2e5+5,M=1e6+5,mod=998244353;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1){x=-x;}return x;
}
void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,vis[M],p[maxn],tot=0,res,a[maxn];
map<int,int>f;
mt19937 rnd(random_device{}());
void init(int n){
	for(int i=2;i<=n;i++){
		if(!vis[i])p[++tot]=i;
		for(int j=1;j<=tot&&p[j]*i<=n;j++)vis[i*p[j]]=1;
	}memset(vis,0,sizeof vis);
}
void get(int x){
	if(f[x])return;f[x]=1;int s=0;
	for(int i=1;i<=n;i++){
		if(a[i]<x)s+=x-a[i];
		else s=s+min(a[i]%x,x-a[i]%x);
	}
	res=min(res,s);
}
void solve(int x){
	for(int i=1;i<=tot&&p[i]*p[i]<=x;i++){
		if(x%p[i]==0){
			get(p[i]);
			while(x%p[i]==0)x/=p[i];
		}
	}if(x>1)get(x);
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	init(1e6);n=read();res=n;
	for(int i=1;i<=n;i++)a[i]=read();
	while(1.0*clock()/CLOCKS_PER_SEC<=2.0){
		int x=rnd()%n+1;solve(a[x]),solve(a[x]+1),solve(a[x]-1);
	}cout<<res<<endl;
 	return 0;
}