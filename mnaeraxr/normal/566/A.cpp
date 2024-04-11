#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 100100;

struct node{
	map<char,int> child;
	set<int> red;
	int father, depth;
};

node trie[maxn * 8];
int tot;

int push(int idx, string &s, bool red){
	int cur = 0;
	if (red) trie[cur].red.insert(idx);
	for (int i = 0; i < (int)s.size(); ++i){
		int v = s[i] - 'a';
		if (trie[cur].child.find(v) == trie[cur].child.end()){
			trie[cur].child[v] = tot++;
			trie[tot - 1].father = cur;
			trie[tot - 1].depth = trie[cur].depth + 1;
		}
		cur = trie[cur].child[v];
		if (red) trie[cur].red.insert(idx);
	}
	return cur;
}

int next[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	tot = 1;	
	for (int i = 1; i <= n; ++i){
		string s; cin >> s;
		push(i, s, true);
	}

	priority_queue<pair<int,pii>> pq;

	for (int i = 1; i <= n; ++i){
		string s; cin >> s;
		int tnode = push(i, s, false);
		pq.push(make_pair(trie[tnode].depth, pii(tnode, i)));
	}

	int ans = 0;
	vector<pii> matching;
	while (!pq.empty()){
		auto cur = pq.top(); pq.pop();
		int depth = cur.first;
		int tnode = cur.second.first;
		int idx = cur.second.second;

		if (trie[tnode].red.size()){
			ans += depth;
			int c = *trie[tnode].red.begin();
			while (tnode){
				trie[tnode].red.erase(c);
				tnode = trie[tnode].father;
			}
			trie[tnode].red.erase(c);
			matching.push_back(pii(c, idx));
		}
		else{
			while (trie[tnode].red.empty())
				tnode = trie[tnode].father;
			pq.push(make_pair(trie[tnode].depth, pii(tnode, idx)));
		}
	}

	cout << ans << endl;
	for (auto c : matching)
		cout << c.first << " " << c.second << endl;
	

	return 0;
}