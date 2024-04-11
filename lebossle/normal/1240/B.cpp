#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a)
    cin >> i;
  map<int, int> firstPos, lastPos;
  for (int i=0; i<n; ++i) {
    if (!firstPos.count(a[i]))
      firstPos[a[i]] =i;
    lastPos[a[i]] = i;
  }
  int best=0;
  int cur=0;
  int prevMax=-1;
  for (auto p : firstPos) {
    if (prevMax < p.second)
      cur++;
    else
      cur=1;
    best = max(best, cur);
    prevMax = lastPos[p.first];
  }
  cout << firstPos.size()-best << endl;
}

int main() {
  int q;
  cin >> q;
  for (int i=0; i<q; ++i)
    solve();
}