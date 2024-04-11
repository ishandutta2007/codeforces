#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

int main() {
  int N; cin >> N;

  int result = 0;
  map<int, int> mp;
  for(int i = 0; i < N; i++) {
    int x; cin >> x;
    if(x) {
      int& y = mp[x];
      ++y;
      if(y == 2) {
        result++;
      } else if(y > 2) {
        result = -1;
        break;
      }
    }
  }
  cout << result << endl;

  return 0;
}