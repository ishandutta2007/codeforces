#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300300;

int N;
int P[MAXN];
int invP[MAXN];
int Q[MAXN];
int ans[MAXN];

struct Node {
   int sum;
   int pref;
   void recalc() {
      pref = min(0, sum);
   }
};

Node merge(Node L, Node R) {
   Node ans;
   ans.sum = L.sum + R.sum;
   ans.pref = min(L.pref, L.sum + R.pref);
   return ans;
}

Node tr[MAXN << 2];

void modify(int v, int l, int r, int p, int x) {
   if (l == r) {
      tr[v].sum += x;
      tr[v].recalc();
      return;
   }
   int mid = (l + r) >> 1;
   if (p <= mid) modify(v << 1, l, mid, p, x);
   else modify(v << 1 | 1, mid + 1, r, p, x);
   tr[v] = merge(tr[v << 1], tr[v << 1 | 1]);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 1; i <= N; ++i) cin >> P[i], invP[P[i]] = i;
   for (int i = 1; i <= N; ++i) cin >> Q[i];
   int ans = N;
   modify(1, 1, N, invP[N], +1);
   for (int i = 1; i <= N; ++i) {
      while (tr[1].sum <= tr[1].pref) {
         modify(1, 1, N, invP[--ans], +1);
      }
      cout << ans << " ";
      modify(1, 1, N, Q[i], -1);
   }
}