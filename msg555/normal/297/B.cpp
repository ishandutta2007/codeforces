#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>

using namespace std;

int main() {
  int N, M, K;
  map<int, int> mp;

  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    ++mp[-x];
  }
  for(int i = 0; i < M; i++) {
    int x; cin >> x;
    --mp[-x];
  }

  int ps = 0;
  for(typeof(mp.begin()) it = mp.begin(); it != mp.end(); ++it) {
    ps += it->second;
    if(ps > 0) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}