#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int adjust(map<int, int>& have, map<int, int>& cond, int x, int v) {
  if(cond.find(x) == cond.end()) return 0;

  int res = 0;
  int& rhv = have[x];
  int cnd = cond[x];
  if(rhv == cnd) res++;
  rhv += v;
  if(rhv == cnd) res--;
  return res;
}

int main() {
  int N, M, P;
  cin >> N >> M >> P;

  map<int, int> bcond;
  vector<int> A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < M; i++) {
    int x; cin >> x;
    ++bcond[x];
  }

  vector<int> res;
  if(1ll * (M - 1) * P < N) for(int r = 0; r < P; r++) {
    map<int, int> ahave;
    int need = bcond.size();
    for(int i = r; i < N; i += P) {
      need += adjust(ahave, bcond, A[i], 1);
      if(i - M * P >= 0) {
        need += adjust(ahave, bcond, A[i - M * P], -1);
      }
      if (!need) {
        res.push_back(i - (M - 1) * P);
      }
    }
  }

  sort(res.begin(), res.end());
  cout << res.size() << endl;
  for(int i = 0; i < res.size(); i++) {
    if(i) cout << ' ';
    cout << res[i] + 1;
  }
  cout << endl;
  return 0;
}