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
#define mod 1000000007

using namespace std;
typedef pair<int, int> P;


multiset<int> g[1<<20];
bool used[1<<20];
stack<int> stk;

void connectdfs(vector<int> G[],int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		connectdfs(G, G[v][i]);
	}
}
void pathdfs(int v, int t, bool flag)
{	
	stk.push(v);
	if(flag && v == t) return;
	int u = *g[v].begin();
	g[v].erase(g[v].begin()), g[u].erase(g[u].lower_bound(v));
	pathdfs(u, t, true);
}


bool EulerianTrail(vector<int> G[], int V, vector<int> &dest, bool flag)
{
	for(int i = 0; i < V; i++) used[i] = false;  //check connectivity
	
	llint s;
	for(int i = 0; i < V; i++){
		if(G[i].size() > 0){
			s = i;
			connectdfs(G, s);
			break;
		}
	}
	for(int i = 0; i < V;i++){
		if(G[i].size() > 0 && !used[i]) return false;
	}
	
	for(int i = 0; i < V; i++){
		g[i].clear();
		for(int j = 0; j < G[i].size(); j++) g[i].insert(G[i][j]);
	}
	
	vector<int> odd;  //check whether the number of vertices with odd degree is not greater than 2
	for(int i = 0; i < V; i++){
		if(g[i].size()%2) odd.push_back(i);
	}
	if(odd.size() > 0) return false;
	
	if(!flag) return true;
	
	if(odd.size() > 0) pathdfs(odd[0], odd[1], true);  //find a path initially
	else pathdfs(s, s, false);
	
	dest.clear();  //extend the path to cover all edges
	while(stk.size()){
		int v = stk.top();
		stk.pop();
		if(g[v].size() == 0) dest.push_back(v);
		else pathdfs(v, v, false);
	}
	return true;
}

typedef pair<P, P> E;

int n;
int a[500005], b[500005];
llint cnt[1<<20];
vector<int> G[1<<20], dest;
set<E> S;

bool check(llint x, bool flag)
{
	llint N = 1<<20, X = 1<<x;
	for(int i = 0; i < X; i++) G[i].clear();
	
	for(int i = 1; i <= n; i++){
		G[a[i]&(X-1)].push_back(b[i]&(X-1));
		G[b[i]&(X-1)].push_back(a[i]&(X-1));
	}
	return EulerianTrail(G, X, dest, flag);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	
	llint ub = 21, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid, false)) lb = mid;
		else ub = mid;
	}
	check(lb, true);
	
	llint X = 1<<lb;
	for(int i = 1; i <= n; i++){
		S.insert(E(P(a[i]&(X-1), b[i]&(X-1)), P(i*2-1, i*2)));
		S.insert(E(P(b[i]&(X-1), a[i]&(X-1)), P(i*2, i*2-1)));
	}
	
	cout << lb << endl;
	for(int i = 1; i < dest.size(); i++){
		llint u = dest[i-1], v = dest[i];
		auto it = S.lower_bound(E(P(u, v), P(0, 0)));
		llint p = it->second.first, q = it->second.second;
		cout << p << " " << q << " ";
		S.erase(E(P(u, v), P(p, q)));
		S.erase(E(P(v, u), P(q, p)));
	}
	cout << endl;
	
	return 0;
}