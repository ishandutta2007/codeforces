#include <iostream>

using namespace std;

int n;
int a[200005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  int l = 1, r = n, pre = 0;
  string s;
  while(l <= r){
    if(a[l] <= pre && a[r] <= pre) break;
    if(a[l] == a[r]){
      if(l == r){
        s += "L";
        break;
      }
      int lcnt = 0, p = a[l];
      for(int j = l+1; j <= r; j++){
        if(a[j] > p) lcnt++;
        else break;
        p = a[j];
      }
      int rcnt = 0; p = a[r];
      for(int j = r-1; j >= l; j--){
        if(a[j] > p) rcnt++;
        else break;
        p = a[j];
      }
      if(lcnt > rcnt){
        for(int j = 0; j < lcnt+1; j++) s += "L";
      }else{
        for(int j = 0; j < rcnt+1; j++) s += "R";
      }
      break;
    }
    if(a[l] < a[r]){
      if(a[l] > pre) s += "L", pre = a[l], l++;
      else s += "R", pre = a[r], r--;
    }
    else{
      if(a[r] > pre) s += "R", pre = a[r], r--;
      else s += "L", pre = a[l], l++;
    }
  }
  cout << s.size() << endl;
  cout << s << endl;

  return 0;
}