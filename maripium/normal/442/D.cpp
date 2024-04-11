#include <bits/stdc++.h>

using namespace std;

int main() {
   int N;
   scanf("%d", &N);
   vector<int> P(N + 1);
   P[0] = -1;
   vector<int> ans(N + 1);
   vector<int> nxt(N + 1);
   for (int i = 1; i <= N; ++i) {
      scanf("%d", &P[i]);
      --P[i];
      int cans = 1;
      for (int v = i; P[v] >= 0; v = P[v]) {
         int par = P[v];
         if (ans[par] < cans) {
            ans[par] = cans;
            nxt[par] = v;
         } else if (ans[par] == cans && v != nxt[par]) {
            cans++;
         } else {
            break;
         }
      }
      printf("%d ", ans[0]);
   }
}