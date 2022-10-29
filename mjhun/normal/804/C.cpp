#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

set<int> s[300005];

int n,m,nc;
vector<int> g[300005];
int r[300005];
bool u[300005];

void dfs(int x, int f){
	for(int y:g[x]){
		if(y==f)continue;
		for(int a:s[y])if(r[a]>=0)u[r[a]]=true;
		int k=0;
		for(int a:s[y])if(r[a]<0){
			while(u[k])k++;
			r[a]=k;
			u[k]=true;
		}
		for(int a:s[y])u[r[a]]=false;
		dfs(y,x);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int q;
		scanf("%d",&q);
		while(q--){
			int x;
			scanf("%d",&x);x--;
			s[i].insert(x);
		}
	}
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	pair<int,int> w=mp(-1,-1);
	fore(i,0,n)w=max(w,mp((int)s[i].size(),i));
	nc=w.fst;
	printf("%d\n",max(nc,1));
	memset(r,-1,sizeof(r));
	int k=0;
	for(int a:s[w.snd])r[a]=k++;
	dfs(w.snd,-1);
	fore(i,0,m)if(r[i]<0)r[i]=0;
	fore(i,0,m){
		if(i)putchar(' ');
		printf("%d",r[i]+1);
	}
	puts("");
	return 0;
}