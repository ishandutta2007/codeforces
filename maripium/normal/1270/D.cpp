#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N, K;
   cin >> N >> K;
   if (K == 1) {
      cout << "! 1" << endl;
      return 0;
   }
   map<int, int> cnt;
   for (int i = 0; i < K + 1; ++i) {
      cout << "? ";
      for (int z = 0; z < K + 1; ++z) {
         if (z != i) {
            cout << z + 1 << " ";
         }
      }
      cout << endl;
      int pos, val;
      cin >> pos >> val;
      ++cnt[val];
   }
   cout << "! " << cnt.rbegin()->second << endl;
}