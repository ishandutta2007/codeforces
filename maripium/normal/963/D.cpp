#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q;
string s;
string t[N];
int need[N];
vector<int> pos[N];
vector<int> go[N];
int ptr;
int fail[N], which[N];
int child[N][26], nxt[N][26];

void reset() {
	for (int i = 0; i <= ptr; ++i) {
		fail[i] = which[i] = 0;
		memset(child[i], 0, sizeof(child[i]));
		memset(nxt[i], 0, sizeof(nxt[i]));
	}
	ptr = 0;
}

void add(int id) {
	int now = 0;
	for (char c : t[id]) {
		if (!child[now][c - 'a']) {
			child[now][c - 'a'] = ++ptr;
		}
		now = child[now][c - 'a'];
	}
	which[now] = id;
}

void bfs() {
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int c = 0; c < 26; ++c) {
			nxt[u][c] = nxt[fail[u]][c];
			int v = child[u][c];
			if (v) {
				fail[v] = nxt[u][c];
				nxt[u][c] = v; q.push(v);
			}
		} 
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s >> q; n = s.size(); s = '~' + s;  
	for (int i = 1; i <= q; ++i) {
		cin >> need[i] >> t[i];
		go[t[i].size()].push_back(i);
	}
	for (int len = 1; len <= n; ++len) if (go[len].size()) {
		reset();
		for (int id : go[len]) add(id);
		bfs();
		int now = 0;
		for (int i = 1; i <= n; ++i) {
			now = nxt[now][s[i] - 'a'];
			if (which[now]) {
				pos[which[now]].push_back(i);
			}
		}
	}
	for (int i = 1; i <= q; ++i) {
		int ans = 1e9;
		for (int j = need[i] - 1; j < int(pos[i].size()); ++j) {
			ans = min(ans, pos[i][j] - pos[i][j - need[i] + 1] + int(t[i].size()));
		}
		cout << (ans == 1e9 ? -1 : ans) << '\n';
	}
}