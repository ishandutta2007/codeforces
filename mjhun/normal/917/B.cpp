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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

vector<pair<int,int> > g[128];int n,m;
bool vis[128][128][32];
bool w[128][128][32];

bool f(int x, int y, int l){
	if(vis[x][y][l])return w[x][y][l];
	vis[x][y][l]=true;
	bool& r=w[x][y][l];
	for(auto p:g[x])if(p.snd>=l&&!f(y,p.fst,p.snd)){r=true;break;}
	return r;
}

int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int x,y;char s[4];
		scanf("%d%d%s",&x,&y,s);x--;y--;
		g[x].pb(mp(y,s[0]-'a'));
	}
	fore(i,0,n){
		fore(j,0,n)putchar(f(i,j,0)?'A':'B');
		puts("");
	}
	return 0;
}