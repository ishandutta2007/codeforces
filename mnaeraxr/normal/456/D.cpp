#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int trie[MAXN][26];
int tot;

void push(string &s){
	int cur = 0;
	for (auto c : s){
		if (!trie[cur][c - 'a'])
			trie[cur][c - 'a'] = tot++;
		cur = trie[cur][c - 'a'];
	}
}

bool dfs1(int s){
	for (int i = 0; i < 26; ++i)
		if (trie[s][i] && !dfs1(trie[s][i]))
			return true;
	return false;
}

bool dfs2(int s){
	int t = 0;
	for (int i = 0; i < 26; ++i){
		if (trie[s][i]){
			if (!dfs2(trie[s][i]))
				return true;
			else ++t;
		}
	}
	return t == 0;
}

int main()
{
	int n, k;
	cin >> n >> k;
	tot = 1;
	for (int i = 0; i < n; ++i){
		string s; cin >> s;
		push(s);
	}

	bool w = dfs1(0);
	bool l = dfs2(0);

	if (w && l) cout << "First" << endl;
	else if (!w && !l) cout << "Second" << endl;
	else if (w && !l) cout << ((k & 1) ? "First" : "Second") << endl;
	else cout << "Second" << endl;
}