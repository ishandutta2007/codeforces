#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint m, n;
vector<int> vec[55];
int used[10005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;

  int k, x;
  for(int i = 1; i <= m; i++){
    cin >> k;
    for(int j = 0; j < k; j++){
      cin >> x;
      vec[i].push_back(x);
    }
  }

  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= m; j++){
      if(i >= j) continue;
      for(int k = 1; k <= n; k++) used[k] = 0;
      for(int k = 0; k < vec[i].size(); k++) used[vec[i][k]]++;
      for(int k = 0; k < vec[j].size(); k++) used[vec[j][k]]++;
      bool ans = false;
      for(int k = 1; k <= n; k++) if(used[k] >= 2) ans = true;
      if(!ans) {
        cout << "impossible" << endl;
        return 0;
      }
    }
  }
  cout << "possible" << endl;

  return 0;
}