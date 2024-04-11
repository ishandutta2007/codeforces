#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,k;
vector<int> g[200005];
bool u[200005];
int s[200005];


void dfs(int x, int f){
	s[x]=u[x];
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		dfs(y,x);
		s[x]+=s[y];
	}
}

ll dfs2(int x, int f, int d){
	ll r=0;
	if(u[x])r+=d;
	fore(i,0,g[x].size()){
		int y=g[x][i];
		if(y==f)continue;
		r+=dfs2(y,x,d+1);
	}
	return r;
}

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,2*k){
		int x;
		scanf("%d",&x);x--;
		u[x]=true;
	}
	fore(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	dfs(0,-1);
	int x=0,f=-1;
	while(1){
		bool w=false;
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(y==f)continue;
			if(s[y]>=k){f=x;x=y;w=true;break;}
		}
		if(!w)break;
	}
	cout<<dfs2(x,-1,0)<<endl;
	return 0;
}