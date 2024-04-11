#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 10010;
const int MAX_M = 100100;
const int MAX_H = 1000100;

struct Node {
  int go[26];
  int word_id;

  Node() {
    memset(go, -1, sizeof(go));
    word_id = -1;
  }
};

int h = 1;
Node trie[MAX_H];

string s;
string t[MAX_M];

bool f[MAX_N];
int g[MAX_N];

void solve() {
  int n; cin >> n;
  cin >> s;
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    int v = 0;
    for (int j = 0; j < t[i].size(); j++) {
      int c = tolower(t[i][j]) - 'a';
      if (trie[v].go[c] == -1) {
        trie[v].go[c] = h++;
      }
      v = trie[v].go[c];
    }
    trie[v].word_id = i;
  }

  f[0] = true;
  for (int i = 1; i <= n; i++) {
    int j = i;
    int v = trie[0].go[s[i - 1] - 'a'];

    while (j > 0 && v != -1) {
      if (f[j - 1] && trie[v].word_id != -1) {
        f[i] = true;
        g[i] = trie[v].word_id;
      }
      j -= 1;
      v = trie[v].go[s[j - 1] - 'a'];
    }
  }

  vector<int> answer;
  int v = n;
  while (v) {
    answer.push_back(g[v]);
    v = v - t[g[v]].size();
  }

  reverse(answer.begin(), answer.end());
  for (int x : answer) {
    cout << t[x] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}