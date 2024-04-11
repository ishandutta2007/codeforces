#include <bits/stdc++.h>

using namespace std;

int get(vector<int> a) {
   assert(a.size() == 100);
   cout << "? ";
   for (int v : a) {
      cout << v << " ";
   }
   cout << "\n";
   cout.flush();
   int ans;
   cin >> ans;
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   int x, y;
   vector<int> a;
   for (int i = 1; i <= 100; ++i) {
      a.emplace_back(i);
   }
   x = get(a);
   x = (x >> 7) << 7;
   for (int i = 1; i <= 100; ++i) {
      a[i - 1] = i << 7;
   }
   y = get(a);
   y &= (1 << 7) - 1;
   cout << "! " << x + y << "\n";
}