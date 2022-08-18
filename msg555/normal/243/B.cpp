#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> E[100000];

int main() {
  int N, M, H, T;
  cin >> N >> M >> H >> T;
  for(int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u--; v--;
    E[u].push_back(v);
    E[v].push_back(u);
  }
  for(int i = 0; i < N; i++) {
    sort(E[i].begin(), E[i].end());
  }

  for(int i = 0; i < N; i++) {
    if(E[i].size() < H + 1) continue;

    for(int ii = 0; ii < E[i].size(); ii++) {
      int j = E[i][ii];
      if(E[j].size() < T + 1) continue;

      int cnt = 0;
      bool ok = max(E[j].size(), E[i].size()) >= T + H + 2;
      if(!ok) {
        int a = 0, b = 0;
        while(a < E[i].size() && b < E[j].size()) {
          cnt++;
          if(E[i][a] == E[j][b]) {
            a++; b++;
          } else if(E[i][a] < E[j][b]) {
            a++;
          } else {
            b++;
          }
        }
        cnt += E[i].size() - a;
        cnt += E[j].size() - b;

        ok = cnt >= H + T + 2;
      } else {
        cnt = 2 + H + T;
      }
      if(ok) {
        cout << "YES" << endl;
        cout << i + 1 << ' ' << j + 1 << endl;

        vector<int> HV, TV;
        for(int k = 0; HV.size() < H && k < E[i].size(); k++) {
          if(E[i][k] == j || binary_search(E[j].begin(), E[j].end(), E[i][k]))
            continue;
          HV.push_back(E[i][k]);
        }
        int vsz = HV.size();
        for(int k = 0; HV.size() < H && k < E[i].size(); k++) {
          if(E[i][k] == j || binary_search(HV.begin(), HV.begin() + vsz, E[i][k]))
            continue;
          HV.push_back(E[i][k]);
        }
        sort(HV.begin(), HV.end());
        for(int k = 0; TV.size() < T && k < E[j].size(); k++) {
          if(E[j][k] == i) continue;
          if(binary_search(HV.begin(), HV.end(), E[j][k])) continue;
          TV.push_back(E[j][k]);
        }
        for(int k = 0; k < H; k++) {
          if(k) cout << ' ';
          cout << HV[k] + 1;
        }
        cout << endl;
        for(int k = 0; k < T; k++) {
          if(k) cout << ' ';
          cout << TV[k] + 1;
        }
        cout << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}