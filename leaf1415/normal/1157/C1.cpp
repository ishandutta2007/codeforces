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
    if(a[l] < pre && a[r] < pre) break;
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