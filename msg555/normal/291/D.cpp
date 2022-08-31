#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  for(int i = 0; i < K; i++) {
    for(int j = N - 1; j >= 0; j--) {
      int v;
      if(j < 1 << i) {
        v = N;
      } else if(j < 2 << i) {
        v = N - j + (1 << i);
      } else {
        v = 1;
      }
      
      cout << v;
      if(j) cout << ' ';
    }
    cout << '\n';
  }

  return 0;
}