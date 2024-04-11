#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int k, n;
pair<LL,LL> s[7];
pair<LL,LL> m[1000];
vector<int> hits[7][1000];
vector<int> edges[7];
int vis[10];


int dfs1(int v){
	if(vis[v] == 0) return 1;
	if(vis[v] != -1) return 0;
	vis[v] = 0;
	for(int i = 0; i < edges[v].size(); i++){
		if(dfs1(edges[v][i]) == 1) return 1;
	}
	vis[v] = 1;
	return 0;
}
int w;
void dfs(vector<int> s, vector<int> e, vector<int> done, vector<int> need, vector<int> rem){ // which rocks hit, which need to hit, which rocks remain
	/*for(int i = 0; i < done.size(); i++) cout << done[i] << " ";
	cout << endl;
	for(int i = 0; i < need.size(); i++) cout << need[i] << " ";
	cout << endl;
	for(int i = 0; i < rem.size(); i++) cout << rem[i] << " ";
	cout << endl;
	cout << endl;*/
	if(w) return;
	if(need.size() > rem.size()) return;
	if(need.size() == 0){
		for(int c = 0; c < 7; c++){
			vis[c] = -1;	
			edges[c].clear();
		}
		for(int i = s.size() - 1; i >= 0; i--){
			for(int j = 0; j < hits[s[i]][e[i]].size(); j++){
				int found = 0;
				for(int k = 0; k < s.size(); k++){
					if(hits[s[i]][e[i]][j] == e[k]){
						edges[i].push_back(k);	
						found = 1;
					}
				}
				if(!found) return;
			}
		}
		for(int j = 0; j < 7; j++){
			if(vis[j] == -1){
				if(dfs1(j)) return;
			}
		}
		w = 1;
		return;
	}
	for(int i = 0; i < rem.size(); i++){
		vector<int> done1;
		vector<int> need1;
		vector<int> rem1;
		vector<int> s1;
		vector<int> e1;
		s1 = s;
		e1 = e;
		s1.push_back(rem[i]);
		e1.push_back(need[0]);
		for(int c = 1; c < need.size(); c++) need1.push_back(need[c]);
		for(int c = 0; c < done.size(); c++) done1.push_back(done[c]);
		for(int d = 0; d < rem.size(); d++) if(d != i) rem1.push_back(rem[d]);
		for(int f = 0; f < hits[rem[i]][need[0]].size(); f++){
			int a = hits[rem[i]][need[0]][f];
			int no = 0;
			for(int g = 0; g < done1.size(); g++){
				if(done1[g] == a){
					no = 1;
				}
			}
			for(int g = 0; g < need1.size(); g++){
				if(need1[g] == a){
					no = 1;
				}
			}
			if(!no) need1.push_back(a);
			if(need1.size() > rem1.size()) continue;
		}
		done1.push_back(need[0]);
		dfs(s1,e1,done1,need1,rem1);
	}
}
int main(){
	cin >> k >> n;
	for(int i = 0; i < k; i++){
		cin >> s[i].first >> s[i].second;
	}
	for(int i = 0; i < n; i++){
		cin >> m[i].first >> m[i].second;
	}
	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			for(int c = 0; c < n; c++){
				if(c == j) continue;
				LL a = (s[i].first-m[j].first)*(s[i].second-m[c].second);
				LL b = (s[i].first-m[c].first)*(s[i].second-m[j].second);
				if(a != b) continue;
				if((s[i].first-m[c].first)*(m[j].first-m[c].first) > 0) continue;
				if((s[i].second-m[c].second)*(m[j].second-m[c].second) > 0) continue;
				hits[i][j].push_back(c);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		w = 0;
		vector<int> s, e;
		vector<int> used;
		vector<int> need;
		vector<int> rem;
		need.push_back(i);
		for(int j = 0; j < k; j++) rem.push_back(j);
		dfs(s,e,used,need,rem);
		ans += w;
	}
	cout << ans;
	cout << endl;
}