#include <bits/stdc++.h>
#define maxn 200005
int n,q,head[maxn]={0},cl=0,tail=0,u,v;
char cmd[10];

struct edge{int v,next;}edges[maxn<<1];
void add_edge(int u,int v){edges[++tail].v=v;edges[tail].next=head[u];head[u]=tail;}

namespace BIT {
	int sum[maxn<<2]={0};
	void add(int p,int x) {if (p==0) return;while (p<=500000) {sum[p]+=x;p+=p&-p;}}
	int query(int p) {int ans=0;while (p>0) {ans+=sum[p];p-=p&-p;}return ans;}
}namespace LCT {
	int ch[maxn][2]={0},fa[maxn]={0},tag[maxn]={0},col[maxn]={0},rev[maxn]={0},size[maxn]={0};
	int not_root(int x){return ch[fa[x]][0]==x||ch[fa[x]][1]==x;}
	void update(int x){size[x]=size[ch[x][0]]+size[ch[x][1]]+1;}
	void reverse(int x) {std::swap(ch[x][0],ch[x][1]);rev[x]^=1;}
	void pushdown(int x) {if (x&&rev[x]) {reverse(ch[x][0]);reverse(ch[x][1]);rev[x]=0;}}
	void cover(int x) {if (x&&tag[x])
	 {col[ch[x][0]]=col[ch[x][1]]=tag[ch[x][0]]=tag[ch[x][1]]=tag[x];tag[x]=0;}}
	void rotate(int x) {
		int f=fa[x],g=fa[f],l=ch[f][1]==x,c=ch[x][l^1];
		if (not_root(f)) ch[g][ch[g][1]==f]=x;
		ch[x][l^1]=f;ch[f][l]=c;
		fa[x]=g;fa[f]=x;if (c) fa[c]=f;
		update(f);update(x);
	} void splay(int x) {
		std::stack<int>stk;int u=x;stk.push(u);while (not_root(u)){stk.push(u=fa[u]);}
		while (!stk.empty()){pushdown(stk.top());cover(stk.top());stk.pop();}
		for (;not_root(x);rotate(x)) 
		if (not_root(fa[x]))rotate((ch[fa[x]][1]==x)==(ch[fa[fa[x]]][1]==fa[x])?fa[x]:x);
	} void access(int x,int c) {
		for (int y=0;x;x=fa[y=x]) {
			splay(x);BIT::add(col[x],-size[x]+size[ch[x][1]]);
			BIT::add(c,size[x]-size[ch[x][1]]);
			col[x]=tag[x]=c;ch[x][1]=y;update(x);
		}
	}void make_root(int x){access(x,++cl);splay(x);reverse(x);}
}

void dfs(int u,int f) {LCT::fa[u]=f;LCT::size[u]=1;
	for (int i=head[u];i;i=edges[i].next){
		if (edges[i].v==f)continue;
		dfs(edges[i].v,u);
	}
}int query(int x){LCT::splay(x);return BIT::query(LCT::col[x])-LCT::size[LCT::ch[x][0]];}

int main() {
	scanf("%d%d",&n,&q);
	for (int i=1;i<n;++i) {
		scanf("%d%d",&u,&v);
		add_edge(u,v);add_edge(v,u);
	}dfs(1,0);
	for (int i=1;i<=n;++i) LCT::make_root(i);
	while (q--) {
		scanf("%s",cmd+1);
		if (cmd[1]=='w') {scanf("%d",&u);printf("%d\n",query(u));}
		if (cmd[1]=='c') {scanf("%d%d",&u,&v);printf("%d\n",query(u)<query(v)?u:v);}
		if (cmd[1]=='u') {scanf("%d",&u);LCT::make_root(u);}
	}return 0;
}