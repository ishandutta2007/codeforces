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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
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

ll n, m;
ll a[300005];
ll cnt[1<<19];
BinaryTrie bt(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], cnt[a[i]]++;
	rep(i, 0, (1<<19)-1) if(cnt[i] == 0) bt.insert(i);
	
	ll sum = 0, x;
	rep(i, 1, m){
		cin >> x;
		sum ^= x;
		cout << (bt.getMin(0, sum)^sum) << "\n";
	}
	flush(cout);
	
	return 0;
}