#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[100005];
vector<int> ig[100005];
bool p[100005];
bool vis[100005];
bool w[100005];
vector<int> c;
int n,m;

void dfs0(int x){
	if(p[x])return;
	p[x]=true;
	c.pb(x);
	fore(i,0,g[x].size()){
		dfs0(g[x][i]);
	}
	fore(i,0,ig[x].size()){
		dfs0(ig[x][i]);
	}
}

bool dfs1(int x){
	vis[x]=true;
	w[x]=true;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(vis[y]){
			if(w[y])return true;
		}
		else if(dfs1(y))return true;
	}
	w[x]=false;
	return false;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);ig[y].pb(x);
	}
	int r=0;
	fore(i,0,n){
		if(!p[i]){
			c.clear();
			dfs0(i);
			r+=c.size()-1;
			fore(i,0,c.size()){
				if(!vis[c[i]]&&dfs1(c[i])){r++;break;}
			}
		}
	}
	printf("%d\n",r);
	return 0;
}