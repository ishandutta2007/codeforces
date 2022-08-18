#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  int res = -1;
  for(int i = 0; i * 7 <= N; i++) {
    if((N - i * 7) % 4 == 0) {
      res = i;
    }
  }
  if(res == -1) {
    cout << -1 << endl;
  } else {
    cout << string((N - res * 7) / 4, '4') << string(res, '7') << endl;
  }
}