#include <bits/stdc++.h>
using namespace std;

string repr="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void solve() {
  int r, c, k;
  cin >> r >> c >> k;
  vector<string> inp(r);
  for (string& s : inp)
    cin >> s;
  int rice=0;
  for (string s : inp)
    for (char c : s)
      if (c == 'R')
        rice++;
  vector<int> dist(rice+1, 0);
  for (int i=0; i<rice; ++i)
    dist[i+1] = i%k;
  sort(dist.begin(), dist.end());
  vector<string> ans(r, string(c, ' '));
  int curRice=0;
  for (int i=0; i<r; ++i)
    for (int j=(i%2==0 ? 0 : c-1); j>=0 && j<c; j += (i%2==0 ? 1 : -1)) {
      curRice += (inp[i][j] == 'R' ? 1 : 0);
      ans[i][j] = repr[dist[curRice]];
    }
  for (string s : ans)
    cout << s << endl;
}

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    solve();
  }
}