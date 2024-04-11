#include <bits/stdc++.h>

using namespace std;

using ld = long double;
const ld eps = 1e-7;
const int MAXN = 1000100;

int N;
ld A[MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   vector<pair<ld, int>> st;
   st.emplace_back(-1e10, 0);
   for (int i = 1; i <= N; ++i) {
      int _A;
      cin >> _A;
      A[i] = _A;
      st.emplace_back(_A, i);
      while (st.size() > 1) {
         if (st[st.size() - 2].first + eps < st.back().first) {
            break;
         }
         ld val = st.back().first;
         st.pop_back();
         ld val2; int last;
         tie(val2, last) = st.back();
         st.pop_back();
         int last2 = st.back().second;
         ld newVal = ((i - last) * val + (last - last2) * val2) / (i - last2);
         st.emplace_back(newVal, i);
      }
   }
   for (int z = 1; z < int(st.size()); ++z) {
      for (int i = st[z - 1].second + 1; i <= st[z].second; ++i) {
         cout << fixed << setprecision(10) << st[z].first << "\n";
      }
   }
}