#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> g[200005];
int n,k;
int d[200005];

void dfs(int x, int f){
	//printf("  %d %d\n",x,d[x]);
	for(int y:g[x]){
		if(y==f)continue;
		d[y]=d[x]+1;
		dfs(y,x);
	}
}

int main(){
	scanf("%d%d",&n,&k);
	int x=2;
	fore(i,0,k){
		int d=(n-1)/k;
		if(i<(n-1)%k)d++;
		g[0].pb(x-1);g[x-1].pb(0);
		//printf("1 %d\n",x);
		fore(_,0,d-1){
			g[x-1].pb(x);
			g[x].pb(x-1);
			//printf("%d %d\n",x,x+1);
			x++;
		}
		x++;
	}
	assert(x==n+1);
	d[0]=0;
	dfs(0,-1);
	x=max_element(d,d+n)-d;
	//printf(" %d\n",x);
	d[x]=0;
	dfs(x,-1);
	printf("%d\n",*max_element(d,d+n));
	fore(i,0,n){
		for(int j:g[i]){
			if(i<j)printf("%d %d\n",i+1,j+1);
		}
	}
	return 0;
}