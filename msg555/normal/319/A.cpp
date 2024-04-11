#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MOD 1000000007

int main() {
  string S; cin >> S;

  int r = 0;
  int pt = 1;
  for(int i = 1; i < S.size(); i++) {
    pt = (2 * pt) % MOD;
  }
  reverse(S.begin(), S.end());
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == '1') {
      r = (r + pt) % MOD;
    }
    pt = (2 * pt) % MOD;
  }
  cout << r << endl;

  return 0;
}