#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;

struct Node{
	int nx[35];
	int val;
	Node(){
		for(int i = 0; i < 35; i++) nx[i] = -1;
	}
};

llint n;
llint a[105];
llint pop[1<<15];
vector<llint> vec;
vector<Node> trie;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	llint N = 1<<15;
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < N; i++) pop[i] = pop[i&(i-1)] + 1;
	
	trie.push_back(Node());
	for(int i = 0; i < N; i++){
		vec.clear();
		for(int j = 1; j <= n; j++) vec.push_back(pop[(a[j] & (N-1)) ^ i]);
		llint p = 0;
		for(int j = 0; j < vec.size(); j++){
			llint c = vec[j];
			if(trie[p].nx[c] == -1){
				trie.push_back(Node());
				trie[p].nx[c] = (int)trie.size()-1;
			}
			p = trie[p].nx[c];
		}
		trie[p].val = i;
	}
	
	for(int i = 0; i < N; i++){
		vec.clear();
		for(int j = 1; j <= n; j++) vec.push_back(pop[(a[j]>>15) ^ i]);
		
		for(int k = 0; k <= 30; k++){
			llint p = 0; bool flag = true;
			for(int j = 0; j < vec.size(); j++){
				int c = k - vec[j];
				if(c < 0 || c >= 35 || trie[p].nx[c] == -1){
					flag = false;
					break;
				}
				p = trie[p].nx[c];
			}
			if(flag){
				cout << (i<<15) + trie[p].val << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	
	return 0;
}