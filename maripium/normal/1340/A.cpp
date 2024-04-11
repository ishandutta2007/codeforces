#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
      vector<int> P(N), Q(N);
      for (int i = 0; i < N; ++i) {
         cin >> P[i];
         --P[i];
         Q[P[i]] = i;
      }
      vector<bool> dead(N);
      set<pair<int, int>> st;
      vector<int> val(N, 1);
      set<pair<int, int>> segs;
      for (int z = 0; z < N; ++z) st.emplace(1, z);
      bool good = true;
      for (int i = 0; i < N; ++i) {
         int p = Q[i];
         if (val[p] != st.rbegin()->first) {
            cout << "No\n";
            good = false;
            break;
         }
         st.erase(make_pair(val[p], p));
         pair<int, int> curSeg = {p, p};
         if (p > 0 && dead[p - 1]) {
            auto it = segs.lower_bound(make_pair(p, p));
            assert(it != segs.begin());
            --it;
            curSeg.first = it->first;
            segs.erase(it);
         }
         if (p + 1 < N && dead[p + 1]) {
            auto it = segs.upper_bound(make_pair(p, p));
            assert(it != segs.end());
            curSeg.second = it->second;
            segs.erase(it);
         }
         dead[p] = true;
         segs.emplace(curSeg);
         if (curSeg.second + 1 < N) {
            int z = curSeg.second + 1;
            st.erase(make_pair(val[z], z));
            val[z] = 1 + curSeg.second - curSeg.first + 1;
            st.emplace(val[z], z);
         }
      }
      if (good) cout << "Yes\n";
   }
}