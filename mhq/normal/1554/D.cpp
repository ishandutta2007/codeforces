#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tst;
  cin >> tst;
  while (tst--) {
      int n;
      cin >> n;
      if (n == 1) {
          cout << "a\n";
      }
      else {
          if (n % 2 == 0) {
              cout << string(n / 2 - 1, 'a') << 'b' << string(n / 2, 'a') << '\n';
          }
          else {
              n--;
              cout << string(n / 2 - 1, 'a') << "bc" << string(n / 2, 'a') << '\n';
          }
      }
  }
}