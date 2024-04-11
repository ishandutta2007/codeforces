#include <iostream>
#include <vector>
#include <string>
#define llint long long
#define inf 1e9

using namespace std;

struct Node{
	int num, sum;
	int next[26];
	Node(){
		num = sum = 0;
		for(int i = 0; i < 26; i++) next[i] = -1;
	}
};

llint n, k;
vector<Node> trie;
llint a[1000005];
llint dp[1000005][2];

void predfs(int v)
{
	trie[v].sum = trie[v].num;
	for(int i = 0; i < 26; i++){
		int u = trie[v].next[i];
		if(u != -1){
			predfs(u);
			trie[v].sum += trie[u].sum;
		}
	}
}

void calcdfs(int v)
{
	llint presum = 0;
	if(trie[v].num) dp[v][1]++;
	for(int i = 0; i < 26; i++){
		int u = trie[v].next[i];
		if(u == -1) continue;
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++){
				if(v != 0 && trie[v].num == 0 && j == 1 && k == 0) continue;
				llint cost = 1;
				if(k == 1) cost = presum;
				if(trie[v].num == 1 && j == 0 && k == 1) cost++;
				dp[u][k] = min(dp[u][k], dp[v][j] + cost);
			}
		}
		calcdfs(u);
		presum += trie[u].sum;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	trie.push_back(Node());
	
	cin >> n;
	llint x; char c;
	for(int i = 1; i <= n; i++){
		cin >> x >> c;
		trie.push_back(Node());
		trie[x].next[c-'a'] = i;
	}
	
	cin >> k;
	for(int i = 1; i <= k; i++){
		cin >> a[i];
		trie[a[i]].num = 1;
	}
	
	predfs(0);
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	calcdfs(0);
	
	for(int i = 1; i <= k; i++){
		cout << min(dp[a[i]][0], dp[a[i]][1]) << " ";
	}
	cout << endl;
	
	return 0;
}