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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<llint, P> T;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

struct edge{
	int to, id;
	edge(){}
	edge(int a, int b){
		to = a, id = b;
	}
};

int n;
vector<edge> G[200005];
bool used[200005];
int fib[35];
int sum[200005];

void dfs(int v, int p)
{
	sum[v] = 1;
	for(auto e : G[v]){
		int u = e.to;
		if(used[e.id]) continue;
		if(u == p) continue;
		dfs(u, v);
		sum[v] += sum[u];
	}
}

void dfs2(int v, int p, int d, vector<T> &tmp)
{
	for(auto e : G[v]){
		int u = e.to;
		if(used[e.id]) continue;
		if(u == p) continue;
		if(sum[u] == fib[d-2]) tmp.push_back(T(e.id, P(u, v)));
		if(sum[u] == fib[d-1]) tmp.push_back(T(e.id, P(v, u)));
		dfs2(u, v, d, tmp);
	}
}

bool calc(int v, int d)
{
	//cout << "! " << v << " " << d << endl;
	
	dfs(v, -1);
	if(d <= 1) return sum[v] == 1;
	
	vector<T> tmp;
	dfs2(v, -1, d, tmp);
	if(tmp.size() == 0) return false;
	
	for(auto e : tmp) used[e.first] = true;
	if(tmp.size() == 1){
		return calc(tmp[0].second.first, d-2) && calc(tmp[0].second.second, d-1);
	}
	if(tmp.size() == 2){
		return calc(tmp[0].second.first, d-2) && calc(tmp[0].second.second, d-3) && calc(tmp[1].second.first, d-2);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	fib[0] = fib[1] = 1;
	rep(i, 2, 30) fib[i] = fib[i-1] + fib[i-2];
	
	//rep(i, 0, 10) cout << fib[i] << " "; cout << endl;
	
	cin >> n;
	int u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(edge(v, i));
		G[v].push_back(edge(u, i));
	}
	
	int d = -1;
	rep(i, 0, 30) if(fib[i] == n) d = i;
	if(d == -1){
		cout << "NO" << endl;
		return 0;
	}
	
	if(calc(1, d)) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}