#include <iostream>
#include <vector>
#define llint long long

using namespace std;

int n, m;
int a[15][100005];
int pos[15][100005];
int nx[100005];
bool used[100005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      cin >> a[i][j];
    }
  }
  for(int i = 1; i <= m; i++){
    for(int j = 1; j <= n; j++){
      pos[i][a[i][j]] = j;
    }
  }

  for(int i = 1; i <= n; i++){
    bool flag = true;
    for(int j = 1; j <= m; j++){
      int p = pos[j][i];
      if(p == n || a[j][p+1] != a[1][pos[1][i]+1]){
        flag = false;
        break;
      }
    }
    if(flag) nx[i] = a[1][pos[1][i]+1];
  }

  for(int i = 1; i <= n; i++){
    if(nx[i]) used[nx[i]] = true;
  }

  //for(int i = 1; i <= n; i++) cout << nx[i] << " "; cout << endl;

  llint ans = 0;
  for(int i = 1; i <= n; i++){
    if(used[i]) continue;
    llint cnt = 1, p = i;
    while(nx[p]) p = nx[p], cnt++;
    ans += cnt*(cnt-1)/2 + cnt;
  }
  cout << ans << endl;
  return 0;
}