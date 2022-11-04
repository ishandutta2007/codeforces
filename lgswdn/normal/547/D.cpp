#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;

struct edge {int to,nxt;}e[N*2]; int hd[N],tot;
void add(int u,int v) {e[++tot]=(edge){v,hd[u]};hd[u]=tot;}

int n,lstx[N],lsty[N],c[N];
bool vst[N];

void dfs(int u,int col) {
	c[u]=col, vst[u]=1;
	for(int i=hd[u],v;i;i=e[i].nxt)
		if(!vst[v=e[i].to]) dfs(v,col^1);
}

int main() {
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++) {
		scanf("%d%d",&x,&y);
		if(lstx[x]) add(lstx[x],i), add(i,lstx[x]), lstx[x]=0;
		else lstx[x]=i;
		if(lsty[y]) add(lsty[y],i), add(i,lsty[y]), lsty[y]=0;
		else lsty[y]=i;
	}
	for(int i=1;i<=n;i++) if(!vst[i]) dfs(i,0);
	for(int i=1;i<=n;i++) putchar(c[i] ? 'b': 'r');
	return 0;
}