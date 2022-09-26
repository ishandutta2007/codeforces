#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MAXN = 1000100;

map<char, int> go[MAXN];
int len[MAXN];
int link[MAXN];
ll cnt[MAXN];
int last;
int nodesCnt = 1;
vector<int> vals[MAXN];

void extend(char c) {
   if (go[last].count(c) && len[go[last][c]] == len[last] + 1) {
      last = go[last][c];
      return;
   }
   int cur = nodesCnt++;
   int p = last;
   len[cur] = len[p] + 1;
   while (p != -1 && !go[p].count(c)) {
      go[p][c] = cur;
      p = link[p];
   }
   if (p == -1) {
      link[cur] = 0;
   } else {
      int q = go[p][c];
      if (len[q] == len[p] + 1) {
         link[cur] = q;
      } else {
         int clone = nodesCnt++;
         link[clone] = link[q];
         go[clone] = go[q];
         len[clone] = len[p] + 1;
         while (p != -1 && go[p][c] == q) {
            go[p][c] = clone;
            p = link[p];
         }
         link[cur] = link[q] = clone;
      }
   }
   last = cur;
}

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   vector<string> T(N);
   vector<int> C(N);
   for (int i = 0; i < N; ++i) {
      cin >> T[i];
   }
   for (int i = 0; i < N; ++i) {
      cin >> C[i];
   }
   link[0] = -1;
   for (int i = 0; i < N; ++i) {
      last = 0;
      for (auto c : T[i]) {
         extend(c);
         cnt[last] += C[i];
      }
   }
   int maxLen = 0;
   for (int i = 0; i < nodesCnt; ++i) {
      maxLen = max(maxLen, len[i]);
      vals[len[i]].emplace_back(i);
   }
   ll ans = 0;
   for (int z = maxLen; z >= 0; --z) {
      for (int v : vals[z]) {
         ans = max(ans, cnt[v] * z);
         cnt[link[v]] += cnt[v];
      }
   }
   cout << ans << "\n";
   return 0;
}