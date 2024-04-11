#include <bits/stdc++.h>

using namespace std;

const int N = 400400;

int n;
int a[N];
int rmq[19][N];

int mrg(int x, int y) {
   if (a[x] > a[y]) {
      return y;
   } else {
      return x;
   }
}

int get(int l, int r) {
   int lg = __lg(r - l + 1);
   return mrg(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
}

int t[N << 2];
int ad[N << 2];

void add(int v, int vv) {
   t[v] += vv;
   ad[v] += vv;
}

void push(int v) {
   if (ad[v]) {
      add(v << 1, ad[v]);
      add(v << 1 | 1, ad[v]);
      ad[v] = 0;
   }
}

void add(int v, int l, int r, int L, int R, int val) {
   if (L <= l && r <= R) {
      add(v, val);
      return;
   }
   push(v);
   int md = (l + r) >> 1;
   if (L <= md) add(v << 1, l, md, L, R, val);
   if (md < R) add(v << 1 | 1, md + 1, r, L, R, val);
   t[v] = max(t[v << 1], t[v << 1 | 1]);
}

int get(int v, int l, int r, int L, int R) {
   if (L <= l && r <= R) {
      return t[v];
   }
   push(v);
   int md = (l + r) >> 1;
   int ans = 0;
   if (L <= md) {
      ans = max(ans, get(v << 1, l, md, L, R));
   }
   if (md < R) {
      ans = max(ans, get(v << 1 | 1, md + 1, r, L, R));
   }
   return ans;
}

int l[N];
int r[N];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for (int i = 1; i <= n; ++i) {
      a[i + n] = a[i];
   }
   vector<int> st;
   for (int i = 1; i <= n + n; ++i) {
      while (!st.empty() && a[i] < a[st.back()]) {
         st.pop_back();
      }
      l[i] = st.empty() ? 1 : st.back() + 1;
      st.emplace_back(i);
   }
   st.clear();
   for (int i = n + n; i > 0; --i) {
      while (!st.empty() && a[i] < a[st.back()]) {
         st.pop_back();
      }
      r[i] = st.empty() ? n + n : st.back() - 1;
      st.emplace_back(i);
   }
   for (int i = 1; i <= n; ++i) {
      add(1, 1, 2 * n, l[i], r[i], +1);
   }
   pair<int, int> ans(get(1, 1, 2 * n, 1, n), 0);
   for (int i = 1; i < n; ++i) {
      add(1, 1, 2 * n, l[i], r[i], -1);
      add(1, 1, 2 * n, l[i + n], r[i + n], +1);
      ans = min(ans, make_pair(get(1, 1, 2 * n, i + 1, n + i), i));
   }
   cout << ans.first << " " << ans.second << "\n";
}