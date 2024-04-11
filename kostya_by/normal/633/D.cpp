#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;
const int INF = (int) 1e9;

int a[MAX_N];
int b[MAX_N];
int c[MAX_N];
int d[MAX_N];
int e[MAX_N];

int h = 0;
int timer = 0;

map<int, int> counter;

bool contains(long long x) {
  if (x < -INF || x > INF) {
    return false;
  }

  int id = lower_bound(b, b + h, (int) x) - b;
  if (id == h || b[id] != x) {
    return false;
  }
  if (e[id] < timer) {
    e[id] = timer;
    d[id] = 0;
  }
  if (d[id] + 1 > c[id]) {
    return false;
  } 
  d[id] += 1;
  return true;
}

bool flag_0_0 = false;

int simulate(long long a, long long b) {
  if (a == 0 && b == 0) {
    if (flag_0_0) {
      return -1;
    } else {
      flag_0_0 = true;
    }
  }

  timer += 1;

  int result = 2;
  contains(a);
  contains(b);
  while (true) {
    long long c = a + b;
    if (contains(c)) {
      result += 1;
      tie(a, b) = make_tuple(b, c);
    } else {
      break;
    }
  }

  return result;
}

void solve() {  
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    counter[a[i]] += 1;
  }

  for (auto p : counter) {
    b[h] = p.first;
    c[h] = p.second;
    d[h] = 0;
    e[h] = 0;
    h += 1;
  }

  int answer = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      answer = max(answer, simulate(a[i], a[j]));
      answer = max(answer, simulate(a[j], a[i]));
    }
  }

  cout << answer << "\n";
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}