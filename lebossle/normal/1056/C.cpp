#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;

int main() {
  int n, m;
  cin >> n >> m;
  vector<ii> p(2*n);
  for (int i=0; i<p.size(); ++i) {
    cin >> p[i].first;
    p[i].second = i+1;
  }
  vector<int> forced(2*n+1, -1);
  vector<ii> bestf;
  for (int i=0; i<m; ++i) {
    int a, b;
    cin >> a >> b;
    forced[a] = b;
    forced[b] = a;
    bestf.push_back(ii(p[a-1].first-p[b-1].first, a));
    bestf.push_back(ii(p[b-1].first-p[a-1].first, b));
  }
  int t;
  cin >> t;
  int oppmove = -1;
  vector<bool> used(2*n+1, false);
  if (t == 2) {
    cin >> oppmove;
    used[oppmove] = true;
  }
  
  sort(p.begin(), p.end(), greater<ii>());
  sort(bestf.begin(), bestf.end(), greater<ii>());

  int curp = 0;
  int curf = 0;
  for (int ta=0; ta<n; ++ta) {
    int move;
    if (oppmove != -1 && forced[oppmove] != -1 && !used[forced[oppmove]]) {
      move = forced[oppmove];
    } else {
      while (curf < bestf.size() && used[bestf[curf].second])
        curf++;
      if (curf == bestf.size()) {
        while (curp < p.size() && used[p[curp].second])
          curp++;
        move = p[curp].second;
      } else {
        move = bestf[curf].second;
      }
    }
    cout << move << endl;
    used[move] = true;
    if (ta != n-1 || t == 1) {
      cin >> oppmove;
      used[oppmove] = true;
    }
  }
}