#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  int res = 0;
  map<pair<int, int>, int> mp;
  for(int i = 0; i < N; i++) {
    pair<int, int> pr;
    cin >> pr.first >> pr.second;
    res = max(res, ++mp[pr]);
  }
  cout << res << endl;
}