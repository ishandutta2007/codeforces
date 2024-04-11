#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e6;

map<char, int> go[N];
int g[N];
int sz = 1;

void add(const string& s) {
  int v = 0;
  for (int i = 0; i < s.length(); i++) {
    if (go[v].find(s[i]) == go[v].end())
      go[v][s[i]] = sz++;
    v = go[v][s[i]];
  }
}

void calc(int v, int leaf) {
  if (go[v].size() == 0) {
    g[v] = leaf;
    return;
  }
  set<int> kids;
  for (auto to : go[v]) {
    calc(to.second, leaf);
    kids.insert(g[to.second]);
  }
  while (kids.count(g[v]))
    g[v]++;
}

const string F = "First";
const string S = "Second";

int main() {
  ios_base::sync_with_stdio(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    add(s);
  }
  calc(0, 0);
  bool fw = (g[0] != 0);
  fill(g, g + N, 0);
  calc(0, 1);
  bool fl = (g[0] != 0);
  cerr << fw << " " << fl << endl;
  if (fw && fl) {
    cout << F;
  }
  if (!fw && !fl) {
    cout << S;
  }
  if (fw && !fl) {
    if (k % 2 == 1)
      cout << F;
    else
      cout << S;
  }
  if (!fw && fl) {
    cout << S;
  }

  return 0;
}