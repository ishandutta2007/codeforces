#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>

using namespace std;

int A[100010];
int F[100010];
int L[100010];

int main() {
  memset(F, -1, sizeof(F));
  for(int i = 2; i < 100010; i++) {
    if(F[i] != -1) continue;
    for(int j = i; j < 100010; j += i) {
      F[j] = i;
    }
  }

  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }

  int res = 0;
  memset(L, 0, sizeof(L));
  for(int i = N - 1; i >= 0; i--) {
    int x = A[i];
    vector<int> pf;
    while(x != 1) {
      int f = F[x];
      while(x % f == 0) x /= f;
      pf.push_back(f);
    }

    int r = 1;
    for(int i = 0; i < pf.size(); i++) {
      r = max(r, 1 + L[pf[i]]);
    }
    for(int i = 0; i < pf.size(); i++) {
      L[pf[i]] = r;
    }
    res = max(res, r);
  }

  cout << res << endl;
  return 0;
}