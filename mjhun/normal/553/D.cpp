#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> g[100005];
int n,m;
bool f[100005];
bool f2[100005];
int a[100005];
vector<int> sol;
queue<int> q;

bool can(double w){  // w: maximo porcentaje de malas
	memset(f2,true,sizeof(f2));
	fore(x,0,n){
		if(f[x])continue;
		f2[x]=false;
		a[x]=0;
		fore(i,0,g[x].size()){
			a[x]+=f[g[x][i]];
		}
		if(1.*a[x]/g[x].size()>w)f2[x]=true,q.push(x);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		fore(i,0,g[x].size()){
			int y=g[x][i];
			if(f2[y])continue;
			a[y]++;
			if(1.*a[y]/g[y].size()>w)f2[y]=true,q.push(y);
		}
	}
	sol.clear();
	fore(i,0,n)if(!f2[i])sol.pb(i);
	return !sol.empty();
}

int main(){
	int k;
	scanf("%d%d%d",&n,&m,&k);
	while(k--){int x;scanf("%d",&x);f[x-1]=true;}
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		g[x].pb(y);g[y].pb(x);
	}
	double s=-0.00001,e=1.00001;
	while(e-s>1e-10){
		double m=(s+e)/2;
		if(can(m))e=m;
		else s=m;
	}
	can(e);
	printf("%d\n",(int)sol.size());
	printf("%d",sol[0]+1);fore(i,1,sol.size())printf(" %d",sol[i]+1);puts("");
	return 0;
}