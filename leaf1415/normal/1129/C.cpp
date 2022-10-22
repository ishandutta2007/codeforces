#include <iostream>
#include <string>
#include <vector>
#define llint long long
#define mod 1000000007

using namespace std;

struct node{
	int mn;
	int nx[2];
	node(){
		mn = 1e4;
		for(int i = 0; i < 2; i++) nx[i] = -1;
	}
};

llint m;
llint a[3005];
string s;
string ban[] = {"0011", "0101", "1110", "1111"};
vector<node> trie;
int dp[4500005][4];
llint ans[3005];

string tmp;
void dfs(int p)
{
	for(int t = 0; t < 2; t++){
		if(trie[p].nx[t] != -1){
			tmp += t+'0';
			int q = trie[p].nx[t];
			
			for(int j = 0; j < 4; j++){
				if(j < 3){
					dp[q][0] += dp[p][j], dp[q][0] %= mod;
					dp[q][j+1] += dp[p][j], dp[q][j+1] %= mod;
				}
				else{
					if(tmp.size() < 4) continue;
					for(int k = 0; k < 4; k++) if(tmp.substr(tmp.size()-4) == ban[k]) goto pass;
					dp[q][0] += dp[p][j], dp[q][0] %= mod;
				}
				pass:;
			}
			dfs(q);
			tmp.erase(tmp.end()-1);
		}
	}
}

llint S = 0;
void dfs2(int p)
{
	if(p > 0){
		S = dp[p][0], S %= mod;
		ans[trie[p].mn] += S, ans[trie[p].mn] %= mod;
	}
	for(int t = 0; t < 2; t++){
		if(trie[p].nx[t] != -1){
			dfs2(trie[p].nx[t]);
		}
	}
	if(p > 0) S += mod - dp[p][0], S %= mod;
}

int main(void)
{
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	s = "#";
	for(int i = 1; i <= m; i++) s += a[i] + '0';
	
	trie.push_back(node());
	for(int i = 1; i <= m; i++){
		int p = 0;
		for(int j = i; j <= m; j++){
			if(trie[p].nx[s[j]-'0'] == -1){
				trie.push_back(node());
				trie[p].nx[s[j]-'0'] = trie.size()-1;
			}
			p = trie[p].nx[s[j]-'0'];
			trie[p].mn = min((int)trie[p].mn, j);
		}
	} 
	//cout << trie.size() << endl;
	
	dp[0][0] = 1;
	dfs(0);
	dfs2(0);
	
	//for(int i = 0; i < trie.size(); i++) cout << dp[i][0] << " "; cout << endl;
	//for(int i = 0; i < trie.size(); i++) cout << trie[i].mn << " "; cout << endl;
	
	llint sum = 0;
	for(int i = 1; i <= m; i++){
		sum += ans[i], sum %= mod;
		cout << sum << endl;
	}
	
	return 0;
}