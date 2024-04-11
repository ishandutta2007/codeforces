#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int P[100010];

vector<int> factor(int x) {
  if(x == 1) return vector<int>(1, 1);

  int f = P[x];
  int e = 0;
  while(P[x] == f) {
    x /= P[x];
    e++;
  }

  vector<int> res = factor(x);
  vector<int> ret;

  int m = 1;
  for(int i = 0; i <= e; i++) {
    for(int j = 0; j < res.size(); j++) {
      ret.push_back(res[j] * m);
    }
    m *= f;
  }
  return ret;
}

int LST[100010];

int main() {
  memset(P, -1, sizeof(P));
  for(int i = 2; i < 100010; i++) {
    if(P[i] != -1) continue;
    for(int j = i; j < 100010; j += i) {
      P[j] = i;
    }
  }

  int N; cin >> N;
  memset(LST, -1, sizeof(LST));

  for(int i = 0; i < N; i++) {
    int x, y; cin >> x >> y;

    int res = 0;
    vector<int> f = factor(x);
    for(int j = 0; j < f.size(); j++) {
      if(i - LST[f[j]] > y) res++;
      LST[f[j]] = i;
    }
    cout << res << endl;
  }
}