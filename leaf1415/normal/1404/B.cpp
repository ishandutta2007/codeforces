#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, a, b, da, db;
vector<llint> G[100005];

llint dtmp[100005];
llint distdfs(vector<llint> G[], int v, int p, llint d)
{
	dtmp[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i], c = 1; //
		if(u == p) continue;
		distdfs(G, u, v, d+c);
	}
}

llint getDiameter(vector<llint> G[], llint n, llint &u, llint &v)
{
	distdfs(G, 1, -1, 0);
	llint max_val = -1, max_v;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	u = max_v;
	
	distdfs(G, u, -1, 0);
	max_val = -1;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	v = max_v;
	
	return max_val;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> a >> b >> da >> db;
		llint u, v;
		for(int i = 1; i <= n; i++) G[i].clear();
		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		llint D = getDiameter(G, n, u, v);
		distdfs(G, a, -1, 0);
		if(dtmp[b] <= da) cout << "Alice" << endl;
		else if(D > 2*da && db > 2*da) cout << "Bob" << endl;
		else cout << "Alice" << endl;
	}
	
	
	return 0;
}