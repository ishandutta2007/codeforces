#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
vector<int> g[400005];
int f[400005];
int szd[400005];
int szu[400005];
int mxd[400005];
int mxu[400005];

void dfs0(int x){
	szd[x]=1;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f[x])continue;
		f[y]=x;
		dfs0(y);
		szd[x]+=szd[y];
	}
}

void dfs1(int x){
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f[x])continue;
		szu[y]=szu[x]+szd[x]-szd[y];
		dfs1(y);
	}
}

void dfs2(int x){
	if(szd[x]<=n/2)mxd[x]=szd[x];
	else mxd[x]=-1;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f[x])continue;
		dfs2(y);
		mxd[x]=max(mxd[x],mxd[y]);
	}
}

void dfs3(int x){
	multiset<int> *ww=new multiset<int>();
	multiset<int>& w=*ww;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f[x])continue;
		if(mxd[y]<=n/2)w.insert(mxd[y]);
	}
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f[x])continue;
		if(szu[y]<=n/2)mxu[y]=szu[y];
		else {
			mxu[y]=mxu[x];
			if(mxd[y]<=n/2)w.erase(w.find(mxd[y]));
			multiset<int>::iterator it=w.end();
			if(it!=w.begin()){
				it--;
				mxu[y]=max(mxu[y],*it);
			}
			if(mxd[y]<=n/2)w.insert(mxd[y]);
		}
		dfs3(y);
	}
	w.clear();
	delete ww;
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	f[0]=-1;
	szu[0]=0;
	mxu[0]=0;
	dfs0(0);
	dfs1(0);
	dfs2(0);
	dfs3(0);
	fore(x,0,n){
		//printf("%d %d %d %d %d %d\n",i,f[i],szd[i],mxd[i],szu[i],mxu[i]);
		if(x)putchar(' ');
		vector<pair<int,int> > w;
		if(x){
			w.pb(mp(szu[x],mxu[x]));
		}
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(y==f[x])continue;
			w.pb(mp(szd[y],mxd[y]));
		}
		sort(w.begin(),w.end());
		if(w.back().fst-w.back().snd<=n/2)putchar('1');
		else putchar('0');
	}
	puts("");
	return 0;
}