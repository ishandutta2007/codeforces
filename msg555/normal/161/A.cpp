#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cassert>

using namespace std;

#define MAXN 100000

int A[MAXN];
int B[MAXN];

int main() {
  int n, m, x, y; cin >> n >> m >> x >> y;
  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < m; i++) cin >> B[i];
  sort(A, A + n);
  sort(B, B + m);

  int j = 0;
  vector<pair<int, int> > V;
  for(int i = 0; i < m; i++) {
    while(j < n && A[j] + y < B[i]) j++;
    if(j < n && A[j] - x <= B[i]) {
      V.push_back(make_pair(j++, i));
    }
  }
  cout << V.size() << endl;
  for(int i = 0; i < V.size(); i++) {
    cout << V[i].first + 1 << ' ' << V[i].second + 1 << '\n';
  }
}