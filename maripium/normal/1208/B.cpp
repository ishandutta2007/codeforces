#include <bits/stdc++.h>

using namespace std;

int a[2005];

int main() {
   ios_base::sync_with_stdio(false);
   int n;
   cin >> n;
   set<int> st;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
      st.emplace(a[i]);
   }
   if (st.size() == n) {
      cout << 0 << "\n";
      return 0;
   }
   int ans = 0;
   st.clear();
   for (int i = 1; i <= n; ++i) {
      if (st.size() != i - 1) {
         break;
      }
      set<int> cst = st;
      int cnt = i - 1;
      for (int j = n; j >= i; --j) {
         if (cst.count(a[j])) {
            break;
         } else {
            cnt++;
            cst.emplace(a[j]);
         }
      }
      st.emplace(a[i]);
      ans = max(ans, cnt);
   }
   cout << n - ans << "\n";
}