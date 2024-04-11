#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 1000100;

int n, w;
vector<int> a[N];
multiset<int> ms[N];
vector<tuple<int, int, int>> ad[N];

ll get(int v) {
   if (ms[v].size()) {
      return *ms[v].rbegin();
   } else {
      return 0;
   }
}

ll tot;

void doAdd(int row, int val) {
   tot -= get(row);
   ms[row].emplace(val);
   tot += get(row);
}

void doDel(int row, int val) {
   tot -= get(row);
   ms[row].erase(ms[row].find(val));
   tot += get(row);
}

void addVal(int row, int l, int r, int val) {
   ad[l].emplace_back(row, val, +1);
   ad[r + 1].emplace_back(row, val, -1);
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> w;
   for (int i = 1; i <= n; ++i) {
      int sz;
      cin >> sz;
      if (sz < w) {
         addVal(i, 1, w - sz, 0);
         addVal(i, sz + 1, w, 0);
      }
      for (int j = 1; j <= sz; ++j) {
         int x;
         cin >> x;
         addVal(i, j, j + w - sz, x);
      }
   }
   for (int i = 1; i <= w; ++i) {
      for (auto p : ad[i]) {
         int row, val, op;
         tie(row, val, op) = p;
         if (op == 1) {
            doAdd(row, val);
         } else {
            doDel(row, val);
         }
      }
      cout << tot << " ";
   }
}