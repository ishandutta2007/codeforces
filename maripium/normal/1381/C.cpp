#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); // cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
      int N, X, Y; cin >> N >> X >> Y;
      vector<int> B(N);
      for (int i = 0; i < N; ++i) cin >> B[i], --B[i];
      vector<deque<int>> ps(N + 1);
      for (int i = 0; i < N; ++i) ps[B[i]].emplace_back(i);
      priority_queue<pair<int, int>> q;
      for (int i = 0; i < N + 1; ++i) q.emplace(int(ps[i].size()), i);
      vector<int> A(N, -1);
      for (int z = 0; z < X; ++z) {
         auto v = q.top().second;
         q.pop();
         assert(ps[v].size());
         A[ps[v].front()] = v;
         ps[v].pop_front();
         q.emplace(int(ps[v].size()), v);
      }
      int msz = q.top().first;
      int mv = N - X;
      // cerr << msz << "\n";
      if (msz + msz > N - X) {
         int xx = msz + msz - (N - X);
         mv = N - X - xx;
      }
      if (X + mv < Y) {
         cout << "NO\n";
         continue;
      }
      mv = Y - X;
      set<int> st(B.begin(), B.end());
      int start = 0;
      while (st.count(start)) start++;
      // for (int i = 0; i < N; ++i) if (A[i] == -1) A[i] = start;
      if (X == N) {
         cout << "YES\n";
         for (int v : A) cout << v + 1 << " "; cout << "\n";
         continue;
      }
      vector<int> ord;
      while (q.size()) {
         int v = q.top().second; q.pop();
         for (int i : ps[v]) ord.emplace_back(i);
      }
      int delta = msz;
      for (int i = 0; i < N - X; ++i) {
         if (mv && B[ord[i]] != B[ord[(i + delta) % (N - X)]]) {
            A[ord[i]] = B[ord[(i + delta) % (N - X)]];
            --mv;
         } else A[ord[i]] = start;
      }
      // for (int i = mv; i < N - X; ++i) A[ord[i]] = start;
      cout << "YES\n";
      for (int v : A) cout << v + 1 << " "; cout << "\n";
   }
}