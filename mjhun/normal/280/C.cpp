#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

double r=0.;
int n;
vector<int> g[100005];

void dfs(int x, int f, int d){
	r+=1./d;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		dfs(y,x,d+1);
	}
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int a,b;
		scanf("%d%d",&a,&b);a--;b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1,1);
	printf("%.12lf\n",r);
	return 0;
}