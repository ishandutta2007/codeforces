#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;
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
	llint lower_bound(llint x){ //x(k = 0)
		llint p = 0, ret = 0;
		for(int i = len-1; i >= 0; i--){
			int e = (x>>i) & 1;
			if(e == 1 && trie[p].next[0] != -1) ret += trie[trie[p].next[0]].size;
			if(trie[p].next[e] == -1 || trie[trie[p].next[e]].size == 0) break;
			p = trie[p].next[e];
		}
		return ret;
	}
	llint getMin(llint k = 0, llint x = 0){ //xXORk(k = 0)
		if(trie[0].size <= k) return -1;
		llint p = 0, ret = 0, sum = 0;
		for(int i = len-1; i >= 0; i--){
			int e = (x>>i) & 1;
			if(trie[p].next[e] == -1 || sum + trie[trie[p].next[e]].size <= k){
				if(trie[p].next[e] != -1) sum += trie[trie[p].next[e]].size;
				e = 1 - e;
			}
			p = trie[p].next[e];
			ret |= ((llint)e) << i;
		}
		return ret;
	}
};

llint n, m;
llint a[200005];
llint k[200005], p[200005];
vector<P> vec, qvec[200005];
llint ans[200005];
BinaryTrie bt(20);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		vec.push_back(P(-a[i], i));
	}
	sort(vec.begin(), vec.end());
	
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> k[i] >> p[i];
		qvec[k[i]].push_back(P(p[i], i));
	}
	for(int i = 1; i <= n; i++){
		bt.insert(vec[i-1].second);
		for(int j = 0; j < qvec[i].size(); j++){
			int qid = qvec[i][j].second;
			ans[qid] = a[bt.getMin(p[qid]-1)];
		}
	}
	for(int i = 1; i <= m; i++) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}