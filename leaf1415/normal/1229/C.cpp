#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#define llint long long

using namespace std;

llint n, m, Q;
llint val[100005], in[100005], out[100005];
vector<llint> G[100005], S[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		val[i] = i;
		for(int j = 0; j < G[i].size(); j++){
			if(G[i][j] > i){
				in[i]++;
				S[i].push_back(G[i][j]);
			}
			else out[i]++;
		}
	}
	//for(int i = 1; i <= n; i++) cout << in[i] << " " << out[i] << endl; cout << endl;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) ans += in[i]*out[i];
	cout << ans << "\n";
	
	cin >> Q;
	for(int q = 1; q <= Q; q++){
		cin >> v;
		
		ans -= in[v]*out[v];
		for(auto it = S[v].begin(); it != S[v].end(); it++){
			llint u = *it;
			//cout << v << " " << u << endl;
			
			ans -= in[u]*out[u];
			if(val[u] > val[v] && val[u] < n+q){
				out[u]--, in[u]++;
				S[u].push_back(v);
				in[v]--, out[v]++;
			}
			ans += in[u]*out[u];
		}
		ans += in[v]*out[v];
		S[v].clear();
		val[v] = n+q;
		cout << ans << "\n";
		//for(int i = 1; i <= n; i++) cout << in[i] << " " << out[i] << endl; cout << endl;
	}
	flush(cout);
	
	return 0;
}