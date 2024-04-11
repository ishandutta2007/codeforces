#include <iostream>

using namespace std;

int n, k;

int main(void)
{
  cin >> n >> k;
  int x = (n-k)/2;

  for(int i = 0 ;i < n; i++){
    if(i%(x+1) == x) cout << 1;
    else cout << 0;
  }
  cout<< endl;
  return 0;
}