#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[100005];
int v[100005];
int n;
map<vector<int>,int> id;
int nid;
set<int> r;

void dfs(int x, int f){
	vector<int> vs;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		dfs(y,x);
		vs.pb(v[y]);
	}
	sort(vs.begin(),vs.end());
	if(!id.count(vs))id[vs]=nid++;
	v[x]=id[vs];
}

void dfs2(int x, int f, int vf){
	vector<int> vs;
	if(f>=0)vs.pb(vf);
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		vs.pb(v[y]);
	}
	sort(vs.begin(),vs.end());
	if(!id.count(vs))id[vs]=nid++;
	if(vs.size()<4)r.insert(id[vs]);
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		vector<int> vs2=vs;
		vs2.erase(find(vs2.begin(),vs2.end(),v[y]));
		if(!id.count(vs2))id[vs2]=nid++;
		dfs2(y,x,id[vs2]);
	}
}

int main(){
	scanf("%d",&n);
	fore(_,1,n){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);g[b].pb(a);
	}
	dfs(0,-1);
	dfs2(0,-1,-1);
	printf("%d\n",(int)r.size());
	return 0;
}