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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n,m;
vector<int> g[500005];
int a[500005],b[500005];
vector<vector<int> > r;

void er(int i){b[a[i]]=b[i];a[b[i]]=a[i];a[i]=-1;}

void dfs(int x, vector<int>& c){
	c.pb(x);
	vector<int> z;
	int k=0;
	for(int y=b[n];y<n;y=b[y]){
		while(k<SZ(g[x])&&g[x][k]<y)k++;
		if(k<SZ(g[x])&&g[x][k]==y)continue;
		z.pb(y);
	}
	for(int y:z)er(y);
	for(int y:z)dfs(y,c);
}

int main(){
	scanf("%d%d",&n,&m);
	fore(_,0,m){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	fore(i,0,n)sort(g[i].begin(),g[i].end());
	fore(i,0,n+1)a[i]=i-1,b[i]=i+1;
	b[n]=0;a[0]=n;
	fore(i,0,n)if(a[i]>=0){
		er(i);
		vector<int> c;
		dfs(i,c);
		r.pb(c);
	}
	printf("%d\n",SZ(r));
	for(auto v:r){
		printf("%d",SZ(v));
		for(int x:v)printf(" %d",x+1);
		puts("");
	}
	return 0;
}