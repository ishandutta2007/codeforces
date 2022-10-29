#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,r;
vector<int> g[200005];
int c[200005];

void dfs(int x, int f){
	int k=-1;
	for(int y:g[x]){
		if(y==f)continue;
		k++;
		while(k==c[x]||f>=0&&k==c[f])k++;
		c[y]=k;
		dfs(y,x);
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
	dfs(0,-1);
	fore(i,0,n)r=max(r,c[i]+1);
	printf("%d\n",r);
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",c[i]+1);
	}
	puts("");
	return 0;
}