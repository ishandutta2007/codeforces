#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> Pi;
typedef long long ll;
#define pii Pi
#define pll PL
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> PL;

int A[100010][2];
int n, m;
int P[100010];

vector <int> E[200020], F[200020];

void add(int x, int y){
	E[x].pb(y); F[y].pb(x);
	E[y^1].pb(x^1); F[x^1].pb(y^1);
}

int p[200020];
int Find(int x){return p[x] == x ? x : p[x] = Find(p[x]); }
vector <int> v;
int vis[200020];

void dfs1(int x){
	vis[x] = 1;
	for(int e : E[x])if(vis[e] == 0)dfs1(e);
	v.pb(x);
}

void dfs2(int x){
	vis[x] = 1;
	for(int e : F[x])if(vis[e] == 0){
		p[Find(x)] = Find(e);
		dfs2(e);
	}
}

void solve(){
	scanf("%d%d", &n, &m);
	for(int i=1;i<=n;i++)scanf("%d", P+i);
	for(int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		rep(j, x){
			int y; scanf("%d", &y);
			if(A[y][0] == 0)A[y][0] = i;
			else A[y][1] = i;
		}
	}
	for(int i=1;i<=n;i++){
		int x = A[i][0], y = A[i][1];
		if(P[i] == 0){
			add(x*2, y*2+1);
			add(x*2+1, y*2);
		}
		else{
			add(x*2, y*2);
			add(x*2+1, y*2+1);
		}
	}
	for(int i=2;i<=2*m+1;i++)p[i] = i;
	for(int i=2;i<=2*m+1;i++)if(vis[i] == 0)dfs1(i);
	reverse(all(v));
	memset(vis, 0, sizeof vis);
	for(int e : v)dfs2(e);
	for(int i=1;i<=m;i++)if(Find(i*2) == Find(i*2+1)){
		puts("NO");
		return;
	}
	puts("YES");
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}