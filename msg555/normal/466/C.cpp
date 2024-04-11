#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

#define MAXN 500010

long long A[MAXN];

int main() {
  int N; cin >> N;
  long long sm = 0;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    sm += A[i];
  }

  if (sm % 3) {
    cout << 0 << endl;
    return 0;
  }
  sm /= 3;

  long long s = 0;
  vector<int> pend;
  for(int i = N - 1; i >= 2; i--) {
    s += A[i];
    if (s == sm) {
      pend.push_back(i);
    }
  }

  s = 0;
  long long res = 0;
  for(int i = 0; i < N; i++) {
    s += A[i];
    if (s == sm) {
      res += pend.size();
    }
    if (!pend.empty() && pend.back() == i + 2) {
      pend.resize(pend.size() - 1);
    }
  }

  cout << res << endl;
  return 0;
}