#include<bits/stdc++.h>
#define N 1000009
using namespace std;

int n,tp,tot=1,a[N],b[N],c[N],q[N],fst[N],cur[N],pnt[N],len[N],nxt[N];
bool bo[N],vis[N];
void add(int x,int y,int z){
	pnt[++tot]=y; len[tot]=z; nxt[tot]=fst[x]; fst[x]=tot;
}
void dfs(int x,bool flag){
	int i;
	//cerr<<x<<endl;
	for (i=cur[x]; i; i=cur[x]){
		cur[x]=nxt[i];
		if (!vis[i]){
			if (!flag){
				bo[i]=1; vis[i]=vis[i^1]=1;
			} else vis[i]=1;
			dfs(pnt[i],flag);
			//cerr<<x<<"->"<<pnt[i]<<endl;
			q[++tp]=len[i];
		}
	}
	cur[x]=0;
}
int main(){
	scanf("%d",&n); n<<=2;
	int i;
	for (i=1; i<=n; i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		add(b[i],c[i],i); add(c[i],b[i],i);
	}
	for (i=1; i<=n; i++) cur[i]=fst[i];
	for (i=1; i<=n; i++) if (cur[i]) dfs(i,0);
	//puts("");
	for (i=2; i<=tot; i+=2){
		if (!bo[i]) swap(b[i>>1],c[i>>1]);
	}
	tot=tp=0; memset(fst,0,sizeof(fst));
	for (i=1; i<=n; i++){
		add(b[i],a[i],i);
	//	cerr<<i<<": "<<b[i]<<' '<<a[i]<<endl;
	}
	for (i=1; i<=n; i++) cur[i]=fst[i];
	//puts("dfs2");
	memset(vis,0,sizeof(vis));
	for (i=1; i<=n; i++) if (cur[i]) dfs(i,1);
	puts("YES");
	//cerr<<"tp:"<<tp<<endl;
	for (i=1; i<=n; i++) printf("%d%c",q[i],i<n?' ':'\n');
	return 0;
}