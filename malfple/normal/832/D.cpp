#include <bits/stdc++.h>

#define REPP(i,a,b,d) for(int i=a; i<=b; i+=d)
#define REP(i,a,b) REPP(i,a,b,1)

#define REVV(i,a,b,d) for(int i=a; i>=b; i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define pb push_back

using namespace std;

const int N = 100005;
const int E = 18;

int n,m;
vector<int>lst[N];

int depth[N];
int sparset[E+1][N];

void dfs(int idx, int par){
	sparset[0][idx] = par;
	
	FOR(i,lst[idx].size()){
		int& to = lst[idx][i];
		if(to == par)continue;
		depth[to] = depth[idx]+1;
		dfs(to, idx);
	}
}

int LCA(int a,int b){
	//printf("lca %d %d\n",a,b);
	if(depth[a] > depth[b]){
		REV(i,E,0){
			if(sparset[i][a] != -1 && depth[sparset[i][a]] >= depth[b])a = sparset[i][a];
		}
	}else if(depth[a] < depth[b]){
		REV(i,E,0){
			if(sparset[i][b] != -1 && depth[sparset[i][b]] >= depth[a])b = sparset[i][b];
		}
	}
	
	//printf("%d %d %d %d\n",a,b,depth[a], depth[b]);
	
	if(a == b)return a;
	
	REV(i,E,0){
		if(sparset[i][a] != sparset[i][b]){
			a = sparset[i][a];
			b = sparset[i][b];
		}
	}
	return sparset[0][a];
}

int dist(int a,int b){
	int lca = LCA(a,b);
	
	return abs(depth[a]-depth[lca]) + abs(depth[lca]-depth[b]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	
	cin>>n>>m;
	REP(i,2,n){
		int x;
		cin>>x;
		lst[i].pb(x);
		lst[x].pb(i);
	}
	
	depth[1] = 1;
	dfs(1,-1);
	
	REP(i,0,E-1){
		REP(j,1,n){
			if(sparset[i][j] == -1)sparset[i+1][j] = -1;
			else sparset[i+1][j] = sparset[i][sparset[i][j]];
		}
	}
	
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		
		int ab = LCA(a,b);
		int ac = LCA(a,c);
		int bc = LCA(b,c);
		
		int center = ab;
		if(depth[ac] > depth[center])center = ac;
		if(depth[bc] > depth[center])center = bc;
		
		cout << max(dist(a,center), max(dist(b,center), dist(c,center)))+1 << endl;
	}
	
	return 0;
}