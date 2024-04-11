#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2020;

int N;
vector<int> adj[MAXN];
int sz[MAXN];
int A[MAXN];
int par[MAXN];
int cnt[MAXN];

vector<int> getOrder(int v) {
   vector<int> order;
   for (int u : adj[v]) {
      if (u) {
         auto curOrder = getOrder(u);
         for (auto z : curOrder) {
            order.emplace_back(z);
         }
      }
   }
   // cerr << v << " " << "\n";
   if (cnt[v] > order.size()) {
      cout << "NO\n";
      exit(0);
   }
   order.insert(order.begin() + cnt[v], v);
   return order;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   int root = -1;
   for (int i = 1; i <= N; ++i) {
      int par;
      cin >> par >> cnt[i];
      if (par == 0) {
         root = i;
      } else {
         adj[par].emplace_back(i);
      }
   }
   // cerr << root << "\n";
   vector<int> order = getOrder(root);
   for (int i = 0; i < N; ++i) {
      A[order[i]] = i + 1;
   }
   cout << "YES\n";
   for (int i = 1; i <= N; ++i) {
      cout << A[i] << " ";
   }
}