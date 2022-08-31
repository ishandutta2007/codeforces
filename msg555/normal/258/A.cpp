#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

int main() {
  string S; cin >> S;
  int N = S.size();
  for(int i = 0; i < N; i++) {
    if(S[i] == '0' || i + 1 == N) {
      cout << S.substr(0, i) << S.substr(i + 1) << endl;
      break;
    }
  }
  return 0;
}