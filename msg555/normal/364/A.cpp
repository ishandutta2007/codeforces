#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

#define BMAXN (1 << 18)
int BT[BMAXN];

void bit_add(int x, int v) {
  for(int i = x | BMAXN; i < (BMAXN << 1); i += i & -i) {
    BT[i ^ BMAXN] += v;
  }
}

int bit_get(int x) {
  long long ret = BT[0];
  for(int i = x; i; i &= i - 1) ret += BT[i];
  return ret;
}

int DP[4010][4010];

int main() {
  long long A;
  string S;
  cin >> A >> S;

  int N = S.size();
  map<int, int> cnt;
  for(int i = 0; i < N; i++) {
    int s = 0;
    for(int j = i; j < N; j++) {
      s += S[j] - '0';
      cnt[s]++;
    }
  }
  map<int, int> ocnt = cnt;

  long long result = 0;
  if(A == 0) {
    result = 2ll * cnt[0] * N * (N + 1) / 2 - 1LL * cnt[0] * cnt[0];
  } else for(map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++) {
    int v = it->first;
    if(v != 0 && A % v == 0) {
      result += 1LL * it->second * ocnt[A / v];
    }
  }

  cout << result << endl;
  return 0;
}