#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
  int N; cin >> N;
  int x = 0, y = 0;
  string S; cin >> S;
  map<pair<int, int>, int> mp;
  mp[make_pair(x, y)]++;

  map<char, int> dx, dy;
  dy['U'] = -1;
  dy['D'] = 1;
  dx['L'] = -1;
  dx['R'] = 1;

  int result = 0;
  for (int i = 0; i < S.size(); i++) {
    x += dx[S[i]];
    y += dy[S[i]];
    result += mp[make_pair(x, y)]++;
  }
  cout << result << endl;

  return 0;
}