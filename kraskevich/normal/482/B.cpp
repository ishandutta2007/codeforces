#include <bits/stdc++.h>

using namespace std;

const int N = (int)2e5;

long long sum[N][30];

bool has(int mask, int n) {
  return (mask & (1 << n)) ? 1 : 0;
}

int l[N];
int r[N];
int q[N];

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> l[i] >> r[i] >> q[i];
    l[i]--;
    r[i]--;
    for (int b = 0; b < 30; b++)
      if (has(q[i], b)) {
	sum[l[i]][b]++;
	sum[r[i] + 1][b]--;
      }
  }
  for (int b = 0; b < 30; b++) {
    long long d = 0;
    for (int i = 0; i < n; i++) {
      d += sum[i][b];
      if (d > 0)
	sum[i][b] = 1;
      else
	sum[i][b] = 0;
    }
    for (int i = 1; i < n; i++)
      sum[i][b] += sum[i - 1][b];
  }
  for (int i = 0; i < m; i++) {
    for (int b = 0; b < 30; b++) {
      int s = sum[r[i]][b] - (l[i] ? sum[l[i] - 1][b] : 0);
      bool all = (s == r[i] - l[i] + 1);
      if (all != has(q[i], b)) {
	cout << "NO\n";
	return 0;
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) {
    int a = 0;
    for (int b = 0; b < 30; b++) {
      int s = sum[i][b] - (i ? sum[i - 1][b] : 0);
      if (s)
	a += (1 << b);
    }
    cout << a << " ";
  }
  cout << "\n";
  return 0;
}