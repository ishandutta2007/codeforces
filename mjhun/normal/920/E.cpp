#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<int> g[200005];
set<int> w;vector<int> r;
int n,m,s;

void dfs(int x){
	s++;
	w.erase(x);
	auto it=w.begin();
	while(it!=w.end()){
		int y=*it;
		if(binary_search(g[x].begin(),g[x].end(),y)){
			++it;
			continue;
		}
		dfs(y);
		it=lower_bound(w.begin(),w.end(),y);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	fore(i,0,n)sort(g[i].begin(),g[i].end());
	fore(i,0,n)w.insert(i);
	fore(i,0,n)if(w.count(i)){
		s=0;dfs(i);r.pb(s);
	}
	sort(r.begin(),r.end());
	printf("%d\n",SZ(r));
	fore(i,0,SZ(r))printf("%d%c",r[i]," \n"[i==SZ(r)-1]);
	return 0;
}