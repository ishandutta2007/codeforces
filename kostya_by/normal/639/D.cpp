#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200200;
const int INF = (int) 1e9;
const long long LINF = (long long) 1e18;

int a[MAX_N];

pair<int, long long> buffer[MAX_N];
priority_queue<long long> pq;

void solve() {
  int n, k, b, c; scanf("%d%d%d%d", &n, &k, &b, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i] += INF;
  }

  long long answer = LINF;
  b = min(b, 5 * c);
  for (int r = 0; r < 5; r++) {
    while (pq.size()) {
      pq.pop();
    }

    for (int i = 0; i < n; i++) {
      long long cost = 0;

      int fi = a[i] / 5;
      int se = a[i] % 5;

      if (se <= r) {
        cost += c * (r - se);
      } else {
        cost += c * (5 + r - se);
        fi += 1;
      }

      buffer[i] = make_pair(fi, cost - fi * 1ll * b);
    }

    sort(buffer, buffer + n);
    long long optimal_sum = 0;
    for (int i = 0; i < n; i++) {
      if (pq.size() == k - 1) {
        long long candidate = buffer[i].first * 1ll * k * 1ll * b + optimal_sum + buffer[i].second; 
        answer = min(answer, candidate);

        // cerr << r << " " << i << " " << candidate << "\n";
      }

      optimal_sum += buffer[i].second;
      pq.push(buffer[i].second);
      if (pq.size() > k - 1) {
        optimal_sum -= pq.top();
        pq.pop();
      }
    }
  }

  printf("%I64d\n", answer);
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}