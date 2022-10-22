#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

llint T;
string s;
vector<llint> G[26];
bool used[26];
string ans;

bool dfs(llint v, llint p)
{
	used[v] = true;
	
	bool ret = false;
	if(G[v].size() <= 1) ret = true;
	ans += (char)(v+'a');
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		ret |= dfs(G[v][i], v);
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		for(int i = 0; i < 26; i++) G[i].clear();
		
		for(int i = 1; i < s.size(); i++){
			int u = s[i]-'a', v = s[i-1]-'a';
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(int i = 0; i < 26; i++){
			sort(G[i].begin(), G[i].end());
			G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
		}
		for(int i = 0; i < 26; i++){
			if(G[i].size() >= 3){
				cout << "NO" << "\n";
				goto end;
			}
		}
		
		ans = "";
		for(int i = 0; i < 26; i++) used[i] = false;
		for(int i = 0; i < 26; i++){
			if(used[i]) continue;
			if(G[i].size() >= 2) continue;
			if(!dfs(i, -1)){
				cout << "NO" << "\n";
				goto end;
			}
		}
		if(ans.size() < 26){
			cout << "NO" << "\n";
			goto end;
		}
		cout << "YES" << "\n";
		cout << ans << "\n";
		
		end:;
	}
	flush(cout);
	
	return 0;
}