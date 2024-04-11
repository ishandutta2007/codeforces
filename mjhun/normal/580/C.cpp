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

vector<int> g[100005];
int c[100005];
int n,m,r;

void dfs(int x, int q, int f){
	if(c[x])q++;
	else q=0;
	if(q>m)return;
	bool asd=true;
	for(int y:g[x])if(y!=f){
		asd=false;
		dfs(y,q,x);
	}
	r+=asd;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d",c+i);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs(0,0,-1);
	printf("%d\n",r);
	return 0;
}