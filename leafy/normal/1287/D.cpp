#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,mod=998244353;
inline int pls(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int dec(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
inline void chkmin(int &x,int y){
	if(y<x) x=y;
}
int n,rt;
int fa[N],c[N],siz[N],p[N];
vector<int> G[N];
vector<int> dfs(int u){
	siz[u]=1;vector<int> a,b;
	for(int v:G[u]) {
		b=dfs(v);
		siz[u]+=siz[v];
		for(int i:b) a.push_back(i);
	}
	if(c[u]>=siz[u]) {
		puts("NO");
		exit(0);
	}
	int t=a.size();
	a.resize(t+1);
	for(int i=t-1;i>=c[u];i--) a[i+1]=a[i];
	a[c[u]]=u;
	return a;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		fa[i]=read();c[i]=read();
		if(!fa[i]) rt=i;
		else G[fa[i]].push_back(i);
	}
	vector<int> a=dfs(rt);
	puts("YES");
	for(int i=0;i<a.size();i++) p[a[i]]=i+1;
	for(int i=1;i<=n;i++) printf("%d ",p[i]); 
	return 0;
}