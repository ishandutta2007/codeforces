
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int n;
int a[1005];
P p[1005];
int ans[1005][1005], ans2[1005][1005];

void calc(int n)
{
  if(n == 1){
    ans[1][1] = 1;
    return;
  }
  calc(n-1);
  for(int i = 1; i <= n-1; i++){
    if(p[i].first >= n) ans[n][i] = 1;
  }
  ans[n][n] = 1;
  for(int i = 0; i < min(n-1, p[n].first-1); i++) ans[i][n] = 1;
}

int main(void)
{
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    p[i] = P(a[i], i);
  }
  sort(p+1, p+n+1);
  reverse(p+1, p+n+1);

  calc(n);

  for(int i = 0; i <= n; i++){
    for(int j = 1; j <= n; j++){
      ans2[i][p[j].second] = ans[i][j];
    }
  }
  cout << n+1 << endl;
  for(int i = 0; i <= n; i++){
    for(int j = 1; j <= n; j++){
      cout << ans2[i][j];
    }
    cout << endl;
  }

  return 0;
}