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
#include <unordered_set>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<int, int> P;

int T;
ll n, m, k;
vector<int> G[100005];
int deg[100005];
bool used[100005];
set<P> S;
unordered_set<int> E[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m >> k;
		rep(i, 1, n) G[i].clear(), E[i].clear(), used[i] = false;
		
		ll u, v;
		rep(i, 1, m){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			E[u].insert(v);
			E[v].insert(u);
		}
		if(k*(k-1)/2 > m+10){
			cout << -1 << "\n";
			continue;
		}
		
		S.clear();
		rep(i, 1, n){
			deg[i] = G[i].size();
			S.insert(P(deg[i], i));
		}
		while(S.size()){
			ll v = S.begin()->second, d = S.begin()->first;
			if(d >= k){
				cout << 1 << " " << (int)S.size() << "\n";
				for(auto p : S) cout << p.second << " "; cout << "\n";
				goto end;
			}
			S.erase(S.begin());
			
			vector<int> tmp;
			for(auto u : G[v]){
				if(!used[u]) tmp.push_back(u);
			}
			G[v] = tmp;
			
			if(d == k-1){
				bool flag = true;
				rep(i, 0, (int)G[v].size()-1){
					int x = G[v][i];
					rep(j, i+1, (int)G[v].size()-1){
						int y = G[v][j];
						if(E[x].count(y) == 0){
							flag = false;
							goto end2;
						}
					}
				}
				end2:;
				if(flag){
					cout << 2 << "\n";
					cout << v << " ";
					for(auto x : G[v]) cout << x << " ";
					cout << "\n";
					goto end;
				}
			}
			
			used[v] = true;
			for(auto x : G[v]){
				S.erase(P(deg[x], x));
				deg[x]--;
				S.insert(P(deg[x], x));
			}
		}
		cout << -1 << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}