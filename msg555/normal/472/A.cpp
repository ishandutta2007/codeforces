#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cstdlib>

using namespace std;

#define MAXV 1000010

bool isp[MAXV];

int main() {
  for(int i = 2; i < MAXV; i++) {
    isp[i] = true;
  }
  for(int i = 2; i < MAXV; i++) {
    if(!isp[i]) continue;
    for(int j = 2 * i; j < MAXV; j += i) {
      isp[j] = false;
    }
  }

  int N; cin >> N;
  for(int i = 4; ; i++) {
    if (!isp[i] && !isp[N - i]) {
      cout << i << ' ' << N - i << endl;
      break;
    }
  }

  return 0;
}