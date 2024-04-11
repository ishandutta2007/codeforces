#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>
#include <cstdlib>

using namespace std;

#define MOD 1000000007

int N[6000];
vector<int> M[256];

int main() {
  string S, T; cin >> S >> T;
  for(int i = 0; i < S.size(); i++) {
    M[S[i]].push_back(i);
    N[i] = 1;
  }

  int res = 0;
  for(int i = 0; i < T.size(); i++) {
    for(int j = M[T[i]].size() - 1; j >= 0; j--) {
      int x = M[T[i]][j];
      res = (res + N[x]) % MOD;
      N[x + 1] = (N[x] + N[x + 1]) % MOD;
    }
  }

  cout << res << endl;
}