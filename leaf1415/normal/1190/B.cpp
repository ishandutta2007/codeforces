#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n;
llint a[100005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  if(n == 1){
    if(a[1] % 2) cout << "sjfnb" << endl;
    else cout << "cslnb" << endl;
    return 0;
  }
  sort(a+1, a+n+1);

  bool flag = false;
  for(int i = 2; i <= n; i++){
    if(a[i] == a[i-1]){
      if(a[i] == 0){
        cout << "cslnb" << endl;
        return 0;
      }
      a[i-1]--;
      flag = true;
      break;
    }
  }
  for(int i = 2; i <= n; i++){
    if(a[i] == a[i-1]){
      cout << "cslnb" << endl;
      return 0;
    }
  }

  llint sum = 0;
  if(flag) sum++;
  for(int i = 1; i <= n; i++) sum += a[i] + 1;
  sum -= n*(n+1)/2;

  if(sum% 2) cout << "sjfnb" << endl;
  else cout << "cslnb" << endl;
  return 0;
}