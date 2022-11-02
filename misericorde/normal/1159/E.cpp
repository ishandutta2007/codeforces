#include <bits/stdc++.h>
#define maxn 600005
std::stack<int>rem1,rem2;
int head[maxn<<3]={0},idx[maxn<<3],n,t,nxt,max,tail=0,degr[maxn<<3]={0},ans[maxn];
struct edge {
	int v,next;
}edges[maxn<<4];
void add_edge(int u,int v) {
	edges[++tail].v=v;
	rem1.push(u); rem2.push(v);
	edges[tail].next=head[u];
	degr[v]++;
	head[u]=tail;
}

void Add_Edge(int L,int R,int l,int r,int to,int rt) {
	if (l>R||r<L) return;
	if (l<=L&&R<=r) {
		add_edge(to,rt+n+1);
		return;
	} Add_Edge(L,(L+R)>>1,l,r,to,rt<<1);
	Add_Edge(((L+R)>>1)+1,R,l,r,to,rt<<1|1);
}

void dfs1(int rt,int l,int r) {
	max=std::max(max,rt+n+1);
	if (l==r) {
		add_edge(rt+n+1,l);
		return;
	} add_edge(rt+n+1,(rt<<1)+n+1);
	add_edge(rt+n+1,((rt<<1|1)+n+1));
	dfs1(rt<<1,l,(l+r)>>1);
	dfs1(rt<<1|1,((l+r)>>1)+1,r);
}

int srt() {
	std::stack<int>stk;
	for (int i=1;i<=max;++i) {
		if (degr[i]==0) stk.push(i);
	}int dfn=n;
	while (!stk.empty()) {
		int u=stk.top();stk.pop();idx[u]=1;
		if (u<=n) ans[u]=dfn--;
		for (int i=head[u];i;i=edges[i].next) {
			degr[edges[i].v]--;
			if (degr[edges[i].v]==0) stk.push(edges[i].v);
		}
	} for (int i=1;i<=n;++i) {
		if (idx[i]==0) return 0;
	}return 1;
}
void solve() {
	tail=0;max=0;
	while (!rem1.empty()) {
		head[rem1.top()]=0;rem1.pop();
	}
	while (!rem2.empty()) {
		degr[rem2.top()]=0;rem2.pop();
	}
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		idx[i]=0;
		scanf("%d",&nxt);
		if (nxt==-1) continue;
		if (nxt<=n) add_edge(nxt,i);
		Add_Edge(1,n,i+1,nxt-1,i,1);
	} dfs1(1,1,n);
	if (!srt()) printf("-1");
	else {
		for (int i=1;i<=n;++i) printf("%d ",ans[i]);
	}printf("\n");
}

int main() {
	scanf("%d",&t);
	while (t--) solve();
	return 0;
}