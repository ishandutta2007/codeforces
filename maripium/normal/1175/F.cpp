#include <bits/stdc++.h>

using namespace std;

const int N = 300300;
const int mod = 1000000007;

int n;
int a[N];
int pw[N];
int pref[N];
int l[N], r[N];

int main() {
   scanf("%d", &n);
   pw[0] = 1;
   for (int i = 1; i <= n + 1; ++i) {
      pw[i] = pw[i - 1] + pw[i - 1];
      if (pw[i] >= mod) {
         pw[i] -= mod;
      }
   }
   for (int i = 1; i <= n; ++i) {
      scanf("%d", a + i);
      pref[i] = pref[i - 1] + pw[a[i]];
      if (pref[i] >= mod) {
         pref[i] -= mod;
      }
   }
   vector<int> st;
   for (int i = 1; i <= n; ++i) {
      while (st.size() && a[st.back()] < a[i]) {
         st.pop_back();
      }
      l[i] = st.empty() ? 1 : st.back() + 1;
      st.emplace_back(i);
   }
   st.clear();
   for (int i = n; i > 0; --i) {
      while (st.size() && a[st.back()] < a[i]) {
         st.pop_back();
      }
      r[i] = st.empty() ? n : st.back() - 1;
      st.emplace_back(i);
   }
   int ans = 0;
   for (int i = 1; i <= n; ++i) {
      int len = a[i];
      int need = pw[len + 1] - 2;
      if (need < 0) need += mod;
      // printf("%d %d %d\n", i, l[i], r[i]);
      if (i - l[i] > r[i] - i) {
         for (int j = i; j <= r[i]; ++j) {
            if (j - len + 1 > i) continue;
            if (j - len + 1 < l[i]) continue;
            int cur = pref[j] - pref[j - len];
            if (cur < 0) cur += mod;
            ans += cur == need;
         }
      } else {
         for (int j = l[i]; j <= i; ++j) {
            if (j + len - 1 < i) continue;
            if (j + len - 1 > r[i]) continue;
            int cur = pref[j + len - 1] - pref[j - 1];
            if (cur < 0) cur += mod;
            ans += cur == need;
         }
      }
   }
   printf("%d\n", ans);
}