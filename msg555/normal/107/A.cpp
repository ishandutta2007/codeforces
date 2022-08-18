#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int E[1000];
int D[1000];
int RE[1000];

int main() {
  int N, P; cin >> N >> P;

  memset(E, -1, sizeof(E));
  memset(RE, -1, sizeof(RE));
  for(int i = 0; i < P; i++) {
    int a, b, d; cin >> a >> b >> d; a--; b--;
    E[a] = b;
    RE[b] = a;
    D[a] = d;
  }

  vector<pair<int, pair<int, int> > > V;
  for(int i = 0; i < N; i++) {
    if(RE[i] != -1) continue;
    if(E[i] == -1) continue;

    int d = 1000000000;
    int x;
    for(x = i; E[x] != -1; x = E[x]) {
      d = min(d, D[x]);
    }
    V.push_back(make_pair(i, make_pair(x, d)));
  }

  sort(V.begin(), V.end());
  cout << V.size() << endl;
  for(int i = 0; i < V.size(); i++) {
    cout << V[i].first + 1 << ' ' << V[i].second.first + 1 << ' '
         << V[i].second.second << endl;
  }
}