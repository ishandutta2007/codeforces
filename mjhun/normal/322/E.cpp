#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

vector<int> g[100005];
char r[100005];
int d[100005];
int n;
int nc;

void dfs(int x, int f){
	nc++;
	d[x]=1;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(r[y]||y==f)continue;
		dfs(y,x);
		d[x]+=d[y];
	}
}

void doit(int x, char c){
	nc=0;
	dfs(x,-1);
	int a=-1;
	while(1){
		bool f=false;
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(y==a)continue;
			if(r[y])continue;
			if(d[y]>=nc/2){
				a=x;
				x=y;
				f=true;
				break;
			}
		}
		if(!f)break;
	}
	r[x]=c;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(!r[y])doit(y,c+1);
	}
}

int main(){
	scanf("%d",&n);
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	doit(0,'A');
	fore(i,0,n){
		if(i)putchar(' ');
		putchar(r[i]);
	}
	puts("");
	return 0;
}