#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;

int N, M;
int A[MAXN];
pair<int, int> B[MAXN];
int ft[MAXN];
int ans[MAXN];
vector<pair<int, int>> qs[MAXN];

void addf(int x) {
   for (; x <= N; x += x & -x) {
      ft[x]++;
   }
}

int getf(int x) {
   int ans = 0;
   for (; x > 0; x -= x & -x) {
      ans += ft[x];
   }
   return ans;
}

int findf(int x) {
   int l = 0, r = N;
   while (l < r) {
      int md = (l + r) >> 1;
      if (getf(md) >= x) {
         r = md;
      } else {
         l = md + 1;
      }
   }
   return l;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 1; i <= N; ++i) {
      cin >> A[i];
      B[i] = {-A[i], i};
   }
   sort(B + 1, B + 1 + N);
   cin >> M;
   for (int i = 1; i <= M; ++i) {
      int len, pos;
      cin >> len >> pos;
      qs[len].emplace_back(pos, i);
   }
   for (int i = 1; i <= N; ++i) {
      addf(B[i].second);
      for (auto q : qs[i]) {
         ans[q.second] = A[findf(q.first)];
      }
   }
   for (int i = 1; i <= M; ++i) {
      cout << ans[i] << "\n";
   }
}