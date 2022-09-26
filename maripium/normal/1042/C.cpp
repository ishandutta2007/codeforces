#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n;
int a[N], f[N];
vector<pair<int,int>> neg;
vector<int> zero;

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      if (a[i] == 0) zero.push_back(i);
      else if (a[i] < 0) {
         neg.push_back({a[i], i});
      }
   }
   sort(neg.begin(), neg.end());
   if (zero.size() + (neg.size() % 2) == n) {
      for (int i = 2; i <= n; ++i) {
         cout << 1 << ' ' << i << ' ' << 1 << '\n';
      }
      return 0;
   }
   if (zero.size()) {
      for (int i = 1; i < zero.size(); ++i) {
         cout << 1 << ' ' << zero[i] << ' ' << zero[0] << '\n';
      }
      if (neg.size() & 1) cout << 1 << ' ' << neg.back().second << ' ' << zero[0] << '\n';
      cout << 2 << ' ' << zero[0] << '\n';
   }
   else if (neg.size() & 1) cout << 2 << ' ' << neg.back().second << '\n';
   vector<int> pos;
   for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) continue;
      if ((neg.size() & 1) && i == neg.back().second) continue;
      pos.push_back(i);
   }
   for (int i = 1; i < pos.size(); ++i) {
      cout << 1 << ' ' << pos[i] << ' ' << pos[0] << '\n';
   }
}