#include <bits/stdc++.h>

using namespace std;

int n, d, k;
vector<vector<int>> seq;

void gen(vector<int>& cur) {
  if (seq.size() >= n)
    return;
  if (cur.size() == d) {
    seq.push_back(cur);
    return;
  }
  for (int c = 1; c <= min(k, n) && seq.size() < n; c++) {
    cur.push_back(c);
    gen(cur);
    cur.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);

  cin >> n >> k >> d;
  vector<int> cur;
  cur.reserve(d);
  gen(cur);
  if (seq.size() < n) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < n; j++)
      cout << seq[j][i] << " ";
    cout << "\n";
  }
  return 0;
}