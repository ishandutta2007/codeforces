#include <bits/stdc++.h>

using namespace std;

const int N = 100 * 1000 + 10;
const int SQRT = 333;

struct HashPair {
  std::hash<int> h;
  
  size_t operator()(const pair<int, int>& p) const {
    return h(p.first) * (1000 * 1000 + 3) + h(p.second);
  }
};

vector<int> fr[N];
vector<int> to[N];
vector<int> at[N];
unordered_map<pair<int, int>, int, HashPair> res;
unordered_set<pair<int, int>, HashPair> was;
int qa[N];
int qb[N]; 
int n, m;
int q;

vector<int> g[N];
int col[N];
int cur;

void dfs(int v) {
  col[v] = cur;
  for (int to : g[v])
    if (col[to] == 0)
      dfs(to);
}

void solveHeavy(int c) {
  for (int i = 0; i < fr[c].size(); i++) {
    int f = fr[c][i];
    int t = to[c][i];
    g[f].push_back(t);
    g[t].push_back(f);
  }
  cur = 0;
  for (int i = 0; i < n; i++)
    if (col[i] == 0) {
      cur++;
      dfs(i);
    }
  for (auto elem : was)
    if (col[elem.first] == col[elem.second])
      res[elem]++;
  for (int i = 0; i < n; i++) {
    g[i].clear();
    col[i] = 0;
  }
}

void solveLight(int c) {
  for (int i = 0; i < fr[c].size(); i++) {
    int f = fr[c][i];
    int t = to[c][i];
    g[f].push_back(t);
    g[t].push_back(f);
  }
  cur = 0;
  for (int i : at[c])
    if (col[i] == 0) {
      cur++;
      dfs(i);
    }
  for (int i = 0; i < at[c].size(); i++)
    for (int j = i + 1; j < at[c].size(); j++)
      if (col[at[c][i]] == col[at[c][j]] && was.count(make_pair(at[c][i], at[c][j]))) {
	    res[make_pair(at[c][i], at[c][j])]++;
      }
  for (int v : at[c]) {
    g[v].clear();
    col[v] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    fr[c].push_back(a);
    to[c].push_back(b);
    at[c].push_back(a);
    at[c].push_back(b);
  }
  for (int i = 0; i < N; i++) {
    sort(at[i].begin(), at[i].end());
    at[i].resize(unique(at[i].begin(), at[i].end()) - at[i].begin());
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> qa[i] >> qb[i];
    qa[i]--;
    qb[i]--;
    if (qa[i] > qb[i])
      swap(qa[i], qb[i]);
    was.insert(make_pair(qa[i], qb[i]));
  }
  for (int c = 0; c < N; c++)
    if (fr[c].size() >= SQRT)
      solveHeavy(c);
    else
      solveLight(c);
  for (int i = 0; i < q; i++)
    cout << res[make_pair(qa[i], qb[i])] << "\n";
  return 0;
}