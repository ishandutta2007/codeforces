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

struct edge{
	llint to, weight, cost;
	edge(llint a, llint b, llint c){
		to = a, weight = b, cost = c;
	}
};

llint T;
llint n, s;
vector<edge> G[100005];
vector<llint> vec[3];

llint dfs(int v, int p)
{
	llint deg = 0, ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		deg++;
		llint res = dfs(G[v][i].to, v), x = G[v][i].weight;
		s -= x * res;
		while(x > 0){
			vec[G[v][i].cost].push_back((x - x/2) * res);
			x /= 2;
		}
		ret += res;
	}
	if(deg == 0) ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> s;
		for(int i = 1; i <= n; i++) G[i].clear();
		
		llint u, v, w, c;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v >> w;// >> c;
			c = 1;
			G[u].push_back(edge(v, w, c));
			G[v].push_back(edge(u, w, c));
		}
		
		vec[1].clear(), vec[2].clear();
		
		dfs(1, -1);
		sort(vec[1].rbegin(), vec[1].rend());
		sort(vec[2].rbegin(), vec[2].rend());
		
		s *= -1;
		if(s <= 0){
			cout << 0 << endl;
			continue;
		}
		
		/*cout << s << endl;
		for(int i = 0; i < vec[1].size(); i++) cout<< vec[1][i] << " "; cout << endl;
		for(int i = 0; i < vec[2].size(); i++) cout<< vec[2][i] << " "; cout << endl;*/
		
		llint ans = inf;
		llint l = -1, r = -1;
		while(l+1 < vec[1].size() && s > 0){
			l++;
			s -= vec[1][l];
		}
		while(r+1 < vec[2].size() && s > 0){
			r++;
			s -= vec[2][r];
		}
		ans = min(ans, (l+1) + (r+1)*2);
		
		while(l >= 0){
			s += vec[1][l];
			l--;
			while(r+1 < vec[2].size() && s > 0){
				r++;
				s -= vec[2][r];
			}
			if(s <= 0) ans = min(ans, (l+1) + (r+1)*2);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}