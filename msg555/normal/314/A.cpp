#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {
  int N, K; cin >> N >> K;

  long long s1 = 0;
  for(int i = 0, j = 0; i < N; i++) {
    int v; cin >> v;
    long long r = s1 - (long long)j * (N - (i - j) - j - 1) * v;
    if(r < K) {
      cout << i + 1 << '\n';
    } else {
      s1 += (long long)j++ * v;
    }
  }

  return 0;
}