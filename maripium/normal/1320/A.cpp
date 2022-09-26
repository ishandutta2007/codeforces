#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   map<int, ll> cnts;
   for (int i = 0; i < N; ++i) {
      int z;
      cin >> z;
      cnts[z - i] += z;
   }
   ll mx = 0;
   for (auto p : cnts) mx = max(mx, p.second);
   cout << mx;
}