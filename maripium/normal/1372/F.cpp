#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   auto query = [&](int l, int r) -> pair<int, int> {
      cout << "? " << l + 1 << ' ' << r + 1 << endl;
      int x, f; cin >> x >> f;
      return make_pair(x, f);
   };
   int N; cin >> N;
   int i = 0;
   vector<int> ans(N, -1);
   vector<pair<int, int>> st;
   while (i < N) {
      while (i < N && ans[i] != -1) i++;
      if (i == N) break;
      int cur = query(i, i).first;
      while (st.size() && st.back().first < cur) st.pop_back();
      int nxt = -1, len = N - i;
      if (st.size()) {
         tie(nxt, len) = st.back();
      }
      while (st.empty() || st.back().first != cur) {
        auto ret = query(i, i + len - 1);
        if (ret.first == nxt) {
            int loc = i + len - ret.second;
            for (int z = loc; z < loc + len; ++z) ans[z] = nxt;
            st.pop_back();
            len -= ret.second;
        } else {
            st.emplace_back(ret);
            tie(nxt, len) = ret;
        }
      }
      for (int z = i; z < i + st.back().second; ++z) ans[z] = cur;
      st.pop_back();
   }
   cout << '!';
   for (int v : ans) cout << ' ' << v; cout << endl;
}