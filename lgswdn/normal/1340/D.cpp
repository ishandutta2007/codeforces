#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

const int N=1e5+9;
int n,deg[N],md;
vi e[N];
vector<pii> ans;

void add(int u,int tick) {ans.emplace_back(pii(u,tick));}
void dfs(int u,int fa,int tick) {
	int d=tick,sn=0; add(u,d);
	if(d==md) d-=deg[u], add(u,d);
	for(auto v:e[u]) if(v!=fa) {
		dfs(v,u,++d), add(u,d), sn++;
		if(sn!=deg[u]-1*(fa!=0)&&d==md) d-=deg[u], add(u,d);
	}
	if(u!=1&&d!=tick-1) add(u,tick-1);
}

int main() {
	n=read();
	if(n==1) return puts("1\n1 0"), 0;
	rep(i,2,n) {
		int u=read(), v=read();
		e[u].push_back(v), e[v].push_back(u);
		deg[u]++, deg[v]++;
		md=max(md,max(deg[u],deg[v]));
	}
	dfs(1,0,0);
	printf("%Ld\n",ans.size());
	for(auto p:ans) printf("%d %d\n",p.fi,p.se);
	return 0;
}