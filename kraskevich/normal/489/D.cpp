#include <bits/stdc++.h>

using namespace std;

const int N = 3333;

vector<int> g[N];
vector<int> gr[N];
bool rev[N][N];
int in[N][N];
int out[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    g[a].push_back(b);
    gr[b].push_back(a);
    rev[b][a] = true;
  }
  for (int v = 0; v < n; v++)
    for (int a : g[v])
      for (int b : g[v])
	if (a < b && a != v && b != v)
	  in[a][b]++;
  for (int v = 0; v < n; v++)
    for (int a : gr[v])
      for (int b : gr[v])
	if (a < b && a != v && b != v)
	  out[a][b]++;
  long long res = 0;
  for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)
      res += in[a][b] * 1ll * out[a][b];
  for (int v = 0; v < n; v++)
    for (int a : g[v])
      for (int b : g[v])
	if (a < b && a != v && b != v && rev[v][a] && rev[v][b])
	  res--;
  cout << res << endl;
  return 0;
}