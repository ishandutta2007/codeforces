#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <stack>
#define llint long long
#define M 2520

using namespace std;
typedef pair<llint, llint> P;

llint n, Q;
llint m[1005], w[1005];
vector<llint> g[1005];
P G[1005][M];
llint cnt[1005][M];
bool used[1005][M];

llint get(llint x)
{
	if(x < 0){
		x = -x;
		x %= M;
		x = (M - x) % M;
	}
	x %= M;
	return x;
}

set<llint> S;
void dfs2(llint v, llint c, llint sv, llint sc)
{
	llint nv, nc;
	do{
		S.insert(v);
		nv = G[v][c].first, nc = G[v][c].second;
		v = nv, c = nc;
	}while(v != sv || c != sc);
}

void dfs(llint v, llint c)
{
	stack<P> stk;
	llint ret;
	
	while(1){
		stk.push(make_pair(v, c));
		used[v][c] = true;
		
		llint nv = G[v][c].first, nc = G[v][c].second;
		if(used[nv][nc]){
			S.clear();
			dfs2(nv, nc, nv, nc);
			ret = S.size();
			break;
		}
		else if(cnt[nv][nc]){
			ret = cnt[nv][nc];
			break;
		}
		else v = nv, c = nc;
	}
	
	while(stk.size()){
		v = stk.top().first, c = stk.top().second;
		cnt[v][c] = ret;
		used[v][c] = false;
		stk.pop();
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> w[i], w[i] = get(w[i]);
	
	llint v;
	for(int i = 1; i <= n; i++){
		cin >> m[i];
		for(int j = 0; j < m[i]; j++){
			cin >> v;
			g[i].push_back(v);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < M; j++){
			int nj = (j + w[i]) % M;
			int ni = g[i][nj % m[i]];
			G[i][j] = make_pair(ni, nj);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < M; j++){
			if(cnt[i][j] == 0) dfs(i, j);
		}
	}
	
	llint x, y;
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> x >> y;
		y = get(y);
		cout << cnt[x][y] << "\n";
	}
	flush(cout);
	
	return 0;
}