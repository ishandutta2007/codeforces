#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int t[200005];

void upd(int x, int v){
	for(;x<=200001;x+=(x&(-x)))t[x]+=v;
}

int query(int x){
	int r=0;
	for(;x>=1;x-=(x&(-x)))r+=t[x];
	return r;
}

vector<int> g[200005];
vector<pair<int,int> > u[200005];
vector<int> w[200005];
int r[200005];
bool t2[200005];
int a[200005];
int d[200005];
int n,qs;

void dfs(int x, int f){
	fore(i,0,u[x].size()){
		if(d[x])upd(u[x][i].fst,-u[x][i].snd);
		else upd(u[x][i].fst,u[x][i].snd);
	}
	fore(i,0,w[x].size()){
		r[w[x][i]]=query(w[x][i]);
		if(d[x])r[w[x][i]]=-r[w[x][i]];
		r[w[x][i]]+=a[x];
	}
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		d[y]=1-d[x];
		dfs(y,x);
	}
	fore(i,0,u[x].size()){
		if(d[x])upd(u[x][i].fst,u[x][i].snd);
		else upd(u[x][i].fst,-u[x][i].snd);
	}
}

int main(){
	scanf("%d%d",&n,&qs);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	memset(r,-1,sizeof(r));
	fore(q,1,qs+1){
		int t,x;
		scanf("%d%d",&t,&x);x--;
		if(t==1){
			int v;
			scanf("%d",&v);
			u[x].pb(mp(q,v));
		}
		else {
			t2[q]=true;
			w[x].pb(q);
		}
	}
	dfs(0,-1);
	fore(q,1,qs+1)if(t2[q])printf("%d\n",r[q]);
	return 0;
}