#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100100;
const long long INF = (long long)1e18;

int n, A, cf, cm;
long long m;

pair<int, int> a[MAX_N];
long long pref[MAX_N];

long long fun(int n, int value) {
  if (n == 0 || a[1].first >= value) {
    return 0ll;
  }

  int left = 2, right = n, result = 1;
  while (left <= right) {
    int middle = (left + right) / 2;
    if (a[middle].first < value) {
      result = max(result, middle);
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  return value * 1ll * result - pref[result];
}

int answer[MAX_N];

void solve() {
  cin >> n >> A >> cf >> cm >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i].first;
  }

  long long sum = 0;
  int optimal_perfect = -1;
  int optimal_min = -1;
  long long optimal_penalty = -INF;
  for (int perfect = 0; perfect <= n; perfect++) {
    if (sum > m) {
      break;
    }

    int left = 1, right = A, result = 0;

    while (left <= right) {
      int middle = (left + right) / 2;

      if (fun(n - perfect, middle) + sum <= m) {
        result = max(result, middle);
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    long long penalty = result * 1ll * cm + perfect * 1ll * cf;
    if (penalty > optimal_penalty) {
      optimal_penalty = penalty;
      optimal_perfect = perfect;
      optimal_min = result;
    }

    sum += A - a[n - perfect].first;
  }

  for (int i = 0; i < optimal_perfect; i++) {
    answer[a[n - i].second] = A;
  }

  for (int i = 1; i <= n - optimal_perfect; i++) {
    int value = a[i].first;
    if (value < optimal_min) {
      value = optimal_min;
    }

    answer[a[i].second] = value;
  }

  cout << optimal_penalty << "\n";
  for (int i = 1; i <= n; i++) {
    cout << answer[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}