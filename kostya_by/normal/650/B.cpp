#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500500;
const long long INF = (long long) 1e18;

int n, a, b;
char s[MAX_N];

int pref[MAX_N];
int suff[MAX_N];

long long check(int cnt) {
  long long mn = INF;
  for (int right = 1; right <= cnt; right++) {
    int left = right - cnt + 1;
    if (left < 1) {
      left += n;
    }

    int right_part = right - 1;
    int left_part = cnt - 1 - right_part;

    int horizontal = pref[right];
    if (left != 1) {
      horizontal += suff[left];
    }

    long long penalty = cnt + a * 1ll * (cnt - 1 + min(left_part, right_part)) + b * 1ll * horizontal;
    mn = min(mn, penalty);
  }

  return mn;
}

void solve() {
  int t; scanf("%d%d%d%d", &n, &a, &b, &t);
  scanf("%s", s + 1);

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == 'w');
  }
  for (int i = n; i >= 1; i--) {
    suff[i] = suff[i + 1] + (s[i] == 'w');
  }

  int left = 1;
  int right = n;
  int result = 0;

  while (left <= right) {
    int middle = (left + right) / 2;

    if (check(middle) <= t) {
      result = middle;
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }

  printf("%d\n", result);
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}