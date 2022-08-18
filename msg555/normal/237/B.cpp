#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <cstring>
#include <set>
#include <queue>

using namespace std;

int main() {
  int N; cin >> N;
  vector<int> C(N);
  for(int i = 0; i < N; i++) cin >> C[i];

  vector<vector<int> > A;
  vector<pair<int, int> > pos(accumulate(C.begin(), C.end(), 0));
  for(int i = 0; i < N; i++) {
    A.push_back(vector<int>(C[i]));
    for(int j = 0; j < C[i]; j++) {
      int x; cin >> x; x--;
      pos[x] = make_pair(i, j);
      A[i][j] = x;
    }
  }
  int s = 0;
  vector<pair<pair<int, int>, pair<int, int> > > res;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < C[i]; j++, s++) {
      int y = A[i][j];
      if(s == y) continue;
      res.push_back(make_pair(pos[s], pos[y]));
      swap(pos[s], pos[y]);
      A[i][j] = s;
      A[pos[y].first][pos[y].second] = y;
    }
  }

  cout << res.size() << endl;
  for(int i = 0; i < res.size(); i++) {
    cout << res[i].first.first+1 << ' ' << res[i].first.second+1 << ' ' <<
            res[i].second.first+1 << ' ' << res[i].second.second+1 << endl;
  }
  return 0;
}