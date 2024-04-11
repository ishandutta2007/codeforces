#include <bits/stdc++.h>
using namespace std;

typedef struct {
	int v,lv;
	bool lazy;
} st_node;

void solve_lazy(st_node *st, int k, int s, int e){
	if(!st[k].lazy)return;
	st[k].v=max(st[k].v,st[k].lv);
	st[k].lazy=false;
	if(s+1==e)return;
	st[2*k].lazy=true;
	st[2*k].lv=st[k].lv;
	st[2*k+1].lazy=true;
	st[2*k+1].lv=st[k].lv;
}

int st_query(st_node *st, int k, int s, int e, int a, int b){
	//printf(" %d\n",k);
	if(s>=b||e<=a)return -2;
	solve_lazy(st,k,s,e);
	if(s>=a&&e<=b)return st[k].v;
	int m=(s+e)/2;
	return max(
		st_query(st,2*k,s,m,a,b),
		st_query(st,2*k+1,m,e,a,b)
	);
}

void st_upd(st_node *st, int k, int s, int e, int a, int b, int v){
	//printf(" %d\n",k);
	if(s>=b||e<=a)return;
	solve_lazy(st,k,s,e);
	if(s>=a&&e<=b){
		st[k].v=v;
		if(s+1==e)return;
		st[2*k].lazy=true;
		st[2*k].lv=v;
		st[2*k+1].lazy=true;
		st[2*k+1].lv=v;
	}
	else {
		int m=(s+e)/2;
		st_upd(st,2*k,s,m,a,b,v);
		st_upd(st,2*k+1,m,e,a,b,v);
		st[k].v=max(st[2*k].v,st[2*k+1].v);
	}
}

st_node ste[1<<20];
st_node stf[1<<20];

int n,m;
vector<int> g[1<<19];
int pre[1<<19],pos[1<<19];

void dfs(int v, int f){
	pre[v]=m++;
	for(int i=0;i<g[v].size();++i){
		int s=g[v][i];
		if(s==f)continue;
		dfs(s,v);
	}
	pos[v]=m;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;++i){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0,-1);
	int q;
	scanf("%d",&q);
	memset(stf,-1,sizeof(stf));
	for(int i=0;i<(1<<20);++i){
		stf[i].lazy=false;
	}
	for(int t=1;t<=q;++t){
		int c,x;
		scanf("%d%d",&c,&x);x--;
		if(c==1){
			st_upd(stf,1,0,m,pre[x],pos[x],t);
		}
		else if(c==2){
			st_upd(ste,1,0,m,pre[x],pre[x]+1,t);
		}
		else {
			int tf=st_query(stf,1,0,m,pre[x],pre[x]+1);
			int te=st_query(ste,1,0,m,pre[x],pos[x]);
			puts(tf>te?"1":"0");
		}
	}
	return 0;
}