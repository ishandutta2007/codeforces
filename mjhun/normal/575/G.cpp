#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<pair<int,int> > g[100005];
queue<int> q;
int d[100005];
int w[100005];
int f[100005];
int n,m;

void bfs(){
	memset(d,-1,sizeof(d));
	d[0]=0;q.push(0);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		fore(i,0,g[x].size()){
			int y=g[x][i].fst;
			if(d[y]<0){
				d[y]=d[x]+1;
				q.push(y);
				f[y]=x;
			}
		}
	}
}

void bfs2(){
	memset(w,-1,sizeof(w));
	w[n-1]=0;q.push(n-1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		fore(i,0,g[x].size()){
			if(g[x][i].snd)continue;
			int y=g[x][i].fst;
			if(w[y]<0){
				w[y]=w[x]+1;
				f[y]=x;
				q.push(y);
			}
		}
	}
}

vector<int> t;
vector<int> t2;
vector<int> sol;
char r[100005];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,m){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		g[x].pb(mp(y,c));
		g[y].pb(mp(x,c));
	}
	bfs();
	bfs2();
	int bd=(1<<30);
	fore(i,0,n){
		if(w[i]>=0)bd=min(bd,d[i]);
	}
	fore(i,0,n){
		if(w[i]>=0){
			if(d[i]==bd){
				t.pb(i);
			}
			else {
				w[i]=-1;
			}
		}
	}
	r[bd]=0;
	for(int dd=bd-1;dd>=0;--dd){
		int bp=10;
		fore(i,0,t.size()){
			int x=t[i];
			fore(j,0,g[x].size())if(d[g[x][j].fst]==dd){
				bp=min(bp,g[x][j].snd);
			}
		}
		r[bd-1-dd]='0'+bp;
		fore(i,0,t.size()){
			int x=t[i];
			fore(j,0,g[x].size())if(d[g[x][j].fst]==dd&&g[x][j].snd==bp){
				int y=g[x][j].fst;
				if(w[y]<0)t2.pb(y);
				if(w[y]<0||w[x]<w[y]){
					w[y]=w[x];
					f[y]=x;
				}
			}
		}
		t.clear();
		fore(i,0,t2.size())t.pb(t2[i]);
		t2.clear();
	}
	assert(w[0]>=0);
	int x=0;
	while(x!=n-1){
		sol.pb(x);
		x=f[x];
	}
	sol.pb(n-1);
	puts(bd?r:"0");
	printf("%d\n%d",(int)sol.size(),sol[0]);
	fore(i,1,sol.size())printf(" %d",sol[i]);
	puts("");
	return 0;
}