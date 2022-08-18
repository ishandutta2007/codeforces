#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 2010

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int A[MAXN];

int main() {
  int N; 

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int ones = 0;
  int result = N + 1;
  for (int i = 0; i < N; i++) {
    if (A[i] == 1) {
      ones++;
    }

    int g = A[i];
    int sz = 1;
    while (i + sz < N && g > 1) {
      g = gcd(g, A[i + sz++]);
    }
    if (g == 1) {
      result = min(result, sz);
    }
  }
  if (ones > 0) {
    result = N - ones;
  } else if (result > N) {
    result = -1;
  } else {
    result = N + result - 2;
  }
  cout << result << endl;

  return 0;
}