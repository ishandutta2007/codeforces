#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int sgn(int x) {
  return x < 0 ? -1 : x == 0 ? 0 : 1;
}

int main() {
  int A[3] = {0};

  int N; cin >> N;
  string S; cin >> S;
  map<char, int> mp;
  mp['R'] = 0;
  mp['G'] = 1;
  mp['B'] = 2;
  for (int i = 0; i < S.size(); i++) {
    A[mp[S[i]]]++;
  }

  string res;
  int nz = sgn(A[0]) + sgn(A[1]) + sgn(A[2]);
  if (nz == 3) {
    res = "RGB";
  } else if (nz == 1) {
    if (A[0]) res = "R";
    if (A[1]) res = "G";
    if (A[2]) res = "B";
  } else {
    int ones = (A[0] == 1 ? 1 : 0) +
               (A[1] == 1 ? 1 : 0) +
               (A[2] == 1 ? 1 : 0);
    if (ones == 2) {
      if (!A[0]) res = "R";
      if (!A[1]) res = "G";
      if (!A[2]) res = "B";
    } else if (ones == 1) {
      if (A[0] > 1) res = "BG";
      if (A[1] > 1) res = "RB";
      if (A[2] > 1) res = "RG";
    } else {
      res = "RGB";
    }
  }

  sort(res.begin(), res.end());
  cout << res << endl;

  return 0;
}