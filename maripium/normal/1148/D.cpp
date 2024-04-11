#include <bits/stdc++.h>

using namespace std;

const int N = 600600;

int n;
int a[N], b[N];
pair<int, int> ft[N];
pair<int, int> f[N];

void reset() {
   for (int i = 1; i <= n + n; ++i) ft[i] = {0, 0};
}

void upd(int p, pair<int, int> v, bool rev) {
   if (rev) p = 2 * n + 1 - p;
   for (; p <= 2 * n; p += p & -p) {
      ft[p] = max(ft[p], v);
   }
}

pair<int, int> get(int p, bool rev) {
   if (rev) p = 2 * n + 1 - p;
   pair<int, int> ans = {0, 0};
   for (; p > 0; p -= p & -p) {
      ans = max(ans, ft[p]);
   }
   return ans;
}

vector<int> up() {
   reset();
   vector<int> values;
   for (int i = 1; i <= n; ++i) {
      if (a[i] < b[i]) values.push_back(i);
   }
   sort(values.begin(), values.end(), [&](int u,int v) {
      return b[u] > b[v];
   });
   // return {};
   for (auto id : values) {
      f[id] = get(a[id], true);
      f[id].first++;
      upd(b[id], make_pair(f[id].first, id), true);
   }
   int id = get(1, true).second;
   vector<int> ans;
   while (id) {
      ans.push_back(id);
      id = f[id].second;
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

vector<int> down() {
   reset();
   vector<int> values;
   for (int i = 1; i <= n; ++i) {
      if (a[i] > b[i]) values.push_back(i);
   }
   sort(values.begin(), values.end(), [&](int u,int v) {
      return b[u] < b[v];
   });
   // for (int v : values) cout << v << ' '; cout << '\n';
   // return {};
   for (auto id : values) {
      f[id] = get(a[id], false);
      f[id].first++;
      upd(b[id], make_pair(f[id].first, id), false);
      // cout << f[id].first << '\n';
   }
   int id = get(2 * n, false).second;
   vector<int> ans;
   while (id) {
      ans.push_back(id);
      id = f[id].second;
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n;
   for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
   // return 0;
   // cout << "LoL\n";
   auto f = ::up();
   auto g = ::down();
   if (f.size() < g.size()) f = g;
   cout << f.size() << '\n';
   for (int v : f) cout << v << ' ';
}