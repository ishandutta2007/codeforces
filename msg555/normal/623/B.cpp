#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAXN 1000010

int A[MAXN];

vector<int> factor(int x) {
  vector<int> p;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      p.push_back(i);
      while (x % i == 0) {
        x /= i;
      }
    }
  }
  if (x > 1) {
    p.push_back(x);
  }
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);

  long long N, a, b;
  cin >> N >> a >> b;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<int> ps;
  for (int i = 0; i < 2; i++) {
    for (int j = -1; j <= 1; j++) {
      vector<int> pl = factor(A[i * (N - 1)] + j);  
      for (int i = 0; i < pl.size(); i++) {
        ps.push_back(pl[i]);
      }
    }
  }
  sort(ps.begin(), ps.end());
  ps.resize(unique(ps.begin(), ps.end()) - ps.begin());

  long long result = a * N;
  vector<long long> R(N + 1);
  vector<long long> RK(N + 1);
  for (int p : ps) {
    int i;
    for (i = N - 1; i >= 0; i--) {
      if (A[i] % p == 0) {
        R[i] = R[i + 1];
      } else if ((A[i] + 1) % p == 0 || (A[i] - 1) % p == 0) {
        R[i] = R[i + 1] + b;
      } else {
        break;
      }
    }
    for (int j = N - 1; j >= 0; j--) {
      RK[j] = a + RK[j + 1];
      if (j > i) {
        RK[j] = min(RK[j], R[j]);
      }
    }

    long long cst = 0;
    for (int i = 0; i < N; i++) {
      result = min(result, cst + RK[i]);
      if (A[i] % p == 0) {
      } else if ((A[i] + 1) % p == 0 || (A[i] - 1) % p == 0) {
        cst += b;
      } else {
        break;
      }
    }
  }

  cout << result << endl;
  return 0;
}