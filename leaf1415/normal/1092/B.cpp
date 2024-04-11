#include <iostream>
#include <algorithm>

using namespace std;

int n;
int a[105];

int main(void)
{
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int ans = 0;
  for(int i = 0; i < n; i+=2) ans += a[i+1]-a[i];
  cout << ans << endl;
  return 0;
}