#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[107];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> n >> m;
   int mx = 0;
   for (int i = 1; i <= n; ++i) cin >> a[i], mx = max(mx, a[i]);
   mx += m;
   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 1; i <= n; ++i) pq.push(a[i]);
   for (int i = 1; i <= m; ++i) {
      int u = pq.top(); pq.pop();
      pq.push(u + 1);
   }
   int mn = 0;
   while (pq.size()) mn = max(mn, pq.top()), pq.pop();
   cout << mn << ' ' << mx << '\n';
}