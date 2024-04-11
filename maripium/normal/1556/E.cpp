#include <bits/stdc++.h>

using namespace std;

struct Node {
   int64_t sum;
   int64_t max_pref;
   int64_t min_pref;
   Node(int64_t v = 0) {
      sum = v;
      max_pref = max<int64_t>(0, v);
      min_pref = min<int64_t>(0, v);
   }
   Node operator +(const Node &n) const {
      Node ans;
      ans.sum = sum + n.sum;
      ans.max_pref = max(max_pref, sum + n.max_pref);
      ans.min_pref = min(min_pref, sum + n.min_pref);
      return ans;
   } 
};

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   
   int N, Q; cin >> N >> Q;
   vector<int64_t> A(N); for (auto &a : A) cin >> a;
   vector<int64_t> B(N); for (auto &a : B) cin >> a;

   int S = 1;
   while (S < N) S *= 2;

   vector<Node> st(2 * S);
   for (int i = 0; i < N; ++i) {
      st[i + S] = Node(A[i] - B[i]);
      for (int v = (i + S) / 2; v > 0; v /= 2) {
         st[v] = st[2 * v] + st[2 * v + 1];
      }
   }

   auto query = [&](int l, int r) {
      Node ansl{};
      Node ansr{};
      for (l += S, r += S; l <= r; l /= 2, r /= 2) {
         if (l & 1) ansl = ansl + st[l++];
         if (!(r & 1)) ansr = st[r--] + ansr;
      }
      return ansl + ansr;
   };

   while (Q--) {
      int l, r; cin >> l >> r; --l, --r;
      Node ans = query(l, r);
      if (ans.sum || ans.max_pref > 0) {
         cout << "-1\n";
      } else {
         cout << -ans.min_pref << '\n';
      }
   }
   return 0;
}