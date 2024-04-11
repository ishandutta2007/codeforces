#define NDEBUG
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)

const int MAXN = 100005;
vector<int> adj[MAXN];

char boja[MAXN];

void dfs(int a, int col) {
  if (boja[a]) {
    if (boja[a] != col) {
      throw 1;
    }
    return;
  }
  boja[a] = col;

  for (int b : adj[a]) {
    dfs(b, 3-col);
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  int V, E;
  cin >> V >> E;
  repeat (E) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i=1; i<=V; ++i) {
    try {
      if (!boja[i]) {
        dfs(i, 1);
      }
    } catch (...) {
      puts("-1");
      return 0;
    }
  }

  vector<int> out[3];
  for (int i=1; i<=V; ++i) {
    out[boja[i]].push_back(i);
  }
  for (int b=1; b<=2; ++b) {
    const vector<int>& v = out[b];
    cout << v.size() << '\n';
    for (int i=0; i<(int)v.size(); ++i) {
      cout << v[i] << "\n "[i < (int)v.size() - 1];
    }
  }
}