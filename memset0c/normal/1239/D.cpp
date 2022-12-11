#include<bits/stdc++.h>
#define ll long long
// #define int long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=1e6+10;
int T,n,m,tim,res,top,pos,a[N],ins[N],dfn[N],low[N],stk[N],col[N],tag[N],siz[N];
std::vector<int> G[N];
std::vector<std::pair<int,int>> E;
void tarjan(int u){
	stk[++top]=u,ins[u]=1,dfn[u]=low[u]=++tim;
	for(int v:G[u])if(!dfn[v]){
		tarjan(v);
		low[u]=std::min(low[u],low[v]);
	}else if(ins[v]){
		low[u]=std::min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]){
		int v; ++pos;
		do{
			v=stk[top--],++siz[pos];
			col[v]=pos,ins[v]=false;
		}while(u!=v);
	}
}
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
#endif
	for(read(T);T--;){
		read(n),read(m);
		for(int u,v,i=1;i<=m;i++){
			read(u),read(v);
			G[u].push_back(v);
			E.push_back(std::make_pair(u,v));
		}
		for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
		// print(siz,1,pos);
		// for(int i=1;i<=n;i++)print(col[i]," \n"[i==n]);
		if(pos==1){
			puts("No");
		}else{
			puts("Yes");
			for(auto it:E)if(col[it.first]!=col[it.second])tag[col[it.first]]=1;
			res=-1;
			for(int i=1;i<=n;i++)if(!tag[col[i]]){res=col[i];break;}
			assert(~res);
			printf("%d %d\n",siz[res],n-siz[res]);
			for(int i=1;i<=n;i++)if(col[i]==res)print(i,' '); puts("");
			for(int i=1;i<=n;i++)if(col[i]!=res)print(i,' '); puts("");
		}
		E.clear(),top=pos=tim=0;
		for(int i=1;i<=n;i++){
			G[i].clear();
			ins[i]=dfn[i]=low[i]=stk[i]=col[i]=tag[i]=siz[i]=0;
		}
	}
}