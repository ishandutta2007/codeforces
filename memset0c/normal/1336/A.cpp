#include<bits/stdc++.h>
#include <queue>
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

const int N=2e5+10;
int n,k,fa[N],tag[N],dep[N],siz[N];
long long ans;
std::vector<int> G[N];
std::priority_queue<std::pair<int,int>> q;

void push(int u){
		tag[u]=1;
		q.push(std::make_pair(dep[u]-siz[u],u));
}

void dfs(int u){
	siz[u]=1;
	bool fl=true;
	for(int v:G[u])if(v!=fa[u]){
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		siz[u]+=siz[v];
		fl=false;
	}
	if(fl){
		push(u);
	}
}

int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(k);
	for(int u,v,i=1;i<n;i++){
		read(u),read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dep[1]=1,dfs(1);
	for(int i=1;i<=k;i++){
		auto x=q.top();
		q.pop();
		if(!tag[fa[x.second]]&&fa[x.second]){
			push(fa[x.second]);
		}
		// printf("> %d %d\n",x.first,x.second);
		ans+=x.first;
	}
	printf("%lld\n",ans);
}