#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200200;

int n;
int a, b, c;
int t[MAX_N];

multiset<int, greater<int> > s;

void order(int &a, int &b, int &c) {
  if (a > c) {
    swap(a, c);
  }
  if (b > c) {
    swap(b, c);
  }
  if (a > b) {
    swap(a, b);
  }
}

void beat_strongest(int x) {
  auto it = s.lower_bound(x);

  if (it != s.end()) {
    s.erase(it);
  }
}

int process(int A, int B, int C, int limit) {
  int result = 0;

  while (true) {
    if (s.size() == 0 || (*s.begin()) <= limit) {
      break;
    }

    result += 1;

    beat_strongest(A);
    beat_strongest(B);
    beat_strongest(C);
  }

  return result;
}

void solve() {
  scanf("%d", &n);
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
    s.insert(t[i]);
  }

  order(a, b, c);

  if ((*s.begin()) > a + b + c) {
    printf("-1\n");
    return;
  }

  int answer = 0;
  answer += process(a + b + c, 0, 0, b + c);
  answer += process(b + c, a, 0, a + c);

  if (a + b <= c) {
    answer += process(a + c, b, 0, c);
  } else {
    answer += process(a + c, b, 0, a + b);
    answer += process(a + b, c, 0, c);
  }

  int n = 0;
  while (s.size()) {
    t[n++] = (*s.begin());
    s.erase(s.begin());
  }

  int left = 0, right = n - 1, delta = n;

  while (left <= right) {
    int middle = (left + right) / 2;

    bool flag = true;
    int days_a_b = 0;
    int days_a = 0;
    int days_b = 0;

    for (int i = middle; i < n; i++) {
      if (t[i] > a + b) {
        flag = false;
      } else if (t[i] > b) {
        days_a_b += 1;
      } else if (t[i] > a) {
        days_b += 1;
      } else  {
        days_a += 1;
      }
    }

    while (days_b < days_a) {
      days_b += 1;
      days_a -= 1;
    }

    if (flag && days_a_b + days_b <= middle) {
      delta = middle;
      right = middle - 1;
    } else {
      left = middle + 1;
    }
  }

  answer += delta;

  printf("%d\n", answer);
}

int main() {
  int cases; cases = 1;

  for (int i = 0; i < cases; i++) {
    solve();
  }

  return 0;
}