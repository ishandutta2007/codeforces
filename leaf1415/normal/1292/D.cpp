#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<int, int> P;

struct TrieNode{
	int num;
	unordered_map<int, int> next;
	TrieNode(){
		num = 0;
	}
};

int n, m;
llint cnt[5005];
bool prime[5005];
vector<int> pvec;
int f[5005][705], fact[5005][705];

vector<TrieNode> trie;
int v[705];

int calc(int pos)
{
	int p = 0;
	for(int j = m-1; j >= pos+1; j--){
		int c = v[j];
		if(trie[p].next.count(c) == 0){
			trie.push_back(TrieNode());
			trie[p].next[c] = (int)trie.size()-1;
		}
		p = trie[p].next[c];
	}
	int presum = trie[p].num;
	for(int j = pos; j >= 0; j--){
		int c = v[j];
		if(trie[p].next.count(c) == 0){
			trie.push_back(TrieNode());
			trie[p].next[c] = (int)trie.size()-1;
		}
		p = trie[p].next[c];
		if(presum - trie[p].num > n/2) return j;
		presum = trie[p].num;
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 2; i < 5005; i++){
		if(prime[i]) continue;
		pvec.push_back(i);
		for(int j = 2*i; j < 5005; j += i) prime[j] = true;
	}
	m = (int)pvec.size();
	
	for(int i = 1; i <= 5000; i++){
		for(int j = 0; j < m; j++){
			int cnt = 0, t = i;
			while(t % pvec[j] == 0){
				cnt++;
				t /= pvec[j];
			}
			f[i][j] = cnt;
		}
	}
	for(int i = 2; i <= 5000; i++){
		for(int j = 0; j < m; j++) fact[i][j] += fact[i-1][j] + f[i][j];
	}
	
	cin >> n;
	int x;
	for(int i = 1; i <= n; i++){
		cin >> x;
		cnt[x]++;
	}
	
	trie.push_back(TrieNode());
	for(int i = 0; i <= 5000; i++){
		if(cnt[i] == 0) continue;
		int p = 0;
		trie[p].num += cnt[i];
		for(int j = m-1; j >= 0; j--){
			int c = fact[i][j];
			if(trie[p].next.count(c) == 0){
				trie.push_back(TrieNode());
				trie[p].next[c] = (int)trie.size()-1;
			}
			p = trie[p].next[c];
			trie[p].num += cnt[i];
		}
	}
	
	int p = m-1;
	while(1){
		p = calc(p);
		if(p == -1) break;
		v[p]++;
	}
	
	llint ans = 0;
	for(int i = 0; i <= 5000; i++){
		bool flag = false;
		for(int j = m-1; j >= 0; j--){
			if(flag) ans += (fact[i][j] + v[j]) * cnt[i];
			else if(fact[i][j] != v[j]){
				flag = true;
				ans += abs(fact[i][j] - v[j]) * cnt[i];
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}