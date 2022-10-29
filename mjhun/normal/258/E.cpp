#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[100005];
vector<int> q[100005];
int l[100005];
int r[100005];
int st[400005];
int lz[400005];
int res[100005];
int n,m,k;

int query(int k, int s, int e){
	if(lz[k])return e-s;
	return st[k];
}

void upd(int k, int s, int e, int a, int b, int v){
	if(s>=b||e<=a)return;
	if(s>=a&&e<=b)lz[k]+=v;
	else {
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);
		upd(2*k+1,m,e,a,b,v);
		st[k]=query(2*k,s,m)+query(2*k+1,m,e);
	}
}

void dfs0(int x, int f){
	l[x]=k++;
	fore(i,0,g[x].size()){
		if(g[x][i]!=f){
			dfs0(g[x][i],x);
		}
	}
	r[x]=k;
}

void dfs1(int x, int f){
	fore(i,0,q[x].size()){
		int y=q[x][i];
		upd(1,0,n,l[x],r[x],1);
		upd(1,0,n,l[y],r[y],1);
	}
	res[x]=query(1,0,n);
	if(res[x])res[x]--;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y!=f)dfs1(y,x);
	}
	fore(i,0,q[x].size()){
		int y=q[x][i];
		upd(1,0,n,l[x],r[x],-1);
		upd(1,0,n,l[y],r[y],-1);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		q[x].pb(y);
		q[y].pb(x);
	}
	dfs0(0,-1);
	dfs1(0,-1);
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",res[i]);
	}
	puts("");
	return 0;
}