#include <iostream>
#include <vector>

using namespace std;

int n;
int a[1005], d[1005];

int main(void)
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) d[i] = a[i] - a[i-1];

vector<int> ans;
  for(int i = 1; i <= n; i++){
    bool flag = true;
    for(int j = 1; j <= n; j++){
      if(j+i > n) break;
      if(d[j] != d[j+i]){
        flag = false;
        break;
      }
    }
    if(flag) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
  return 0;
}