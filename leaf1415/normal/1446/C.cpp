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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

struct BinaryTrie{
	struct BTNode{
		llint size;
		llint next[2];
		BTNode(){
			size = 0;
			next[0] = next[1] = -1;
		}
	};
	
	llint len;
	vector<BTNode> trie;
	BinaryTrie(){}
	BinaryTrie(llint l){
		len = l;
		trie.push_back(BTNode());
	}
	void clear(){
		trie.clear();
		trie.push_back(BTNode());
	}
	llint size(){
		return trie[0].size;
	}
	void insert(llint x, llint num = 1){
		llint p = 0;
		for(int i = len-1; i >= 0; i--){
			trie[p].size += num;
			int e = (x>>i) & 1;
			if(trie[p].next[e] == -1){
				trie.push_back(BTNode());
				trie[p].next[e] = trie.size()-1;
			}
			p = trie[p].next[e];
		}
		trie[p].size += num;
	}
	llint count(llint x){
		llint p = 0;
		for(int i = len-1; i >= 0; i--){
			int e = (x>>i) & 1;
			if(trie[p].next[e] == -1) return 0;
			p = trie[p].next[e];
		}
		return trie[p].size;
	}
	llint get(llint x){
		llint p = 0, ret = 0;
		for(int i = len-1; i >= 0; i--){
			int e = (x>>i) & 1;
			if(trie[p].next[e] == -1) return 0;
			if(trie[p].next[1-e] != -1 && trie[trie[p].next[1-e]].size > 0) ret++;
			p = trie[p].next[e];
		}
		return ret;
	}
	void erase(llint x, llint num = 1){
		num = min(num, count(x));
		llint p = 0;
		for(int i = len-1; i >= 0; i--){
			trie[p].size -= num;
			int e = (x>>i) & 1;
			if(trie[p].next[e] == -1){
				trie.push_back(BTNode());
				trie[p].next[e] = trie.size()-1;
			}
			p = trie[p].next[e];
		}
		trie[p].size -= num;
	}
};

llint n;
llint a[200005];
map<llint, llint> mp;
BinaryTrie bt(30);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) bt.insert(a[i]);
	
	llint ans = 0;
	rep(i, 1, n){
		chmax(ans, bt.get(a[i])+1);
	}
	cout << n-ans << endl;
	
	return 0;
}