#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;

string S;
int DP[3000][3000];

int csolve(int a, int b) {
  if(a >= b) return 0;

  int& ref = DP[a][b];
  if(ref != -1) return ref;

  ref = max(csolve(a + 1, b), csolve(a, b - 1));
  if(S[a] == S[b - 1]) {
    ref = max(ref, csolve(a + 1, b - 1) + (a + 1 == b ? 1 : 2));
  }

  return ref;
}

string solve(int a, int b) {
  int res = csolve(a, b);
  if(res == 0) return string();
  if(res == csolve(a + 1, b)) {
    return solve(a + 1, b);
  } else if(res == csolve(a, b - 1)) {
    return solve(a, b - 1);
  } else {
    if(a + 1 == b) {
      return S.substr(a, 1);
    } else {
      return S.substr(a, 1) + solve(a + 1, b - 1) + S.substr(a, 1);
    }
  }
}

int main() {
  cin >> S;
  int N = S.size();

  if(S.size() >= 2600) {
    map<char, int> cnt;
    for(int i = 0; ; i++) {
      if(++cnt[S[i]] == 100) {
        cout << string(100, S[i]) << endl;
        return 0;
      }
    }
  }

  memset(DP, -1, sizeof(DP));
  string res = solve(0, N);
  if(res.size() > 100) {
    res = res.substr(0, 50) + res.substr(res.size() - 50);
  }
  cout << res << endl;
  return 0;
}