#include <bits/stdc++.h>
using namespace std;

// To execute C++, please define "int main()"
int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    int x;
    cin >> x; 
    if (x <= 30)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      int v = x - 30;
      int last = 14;
      
      if(set<int>({6, 10, 14}).count(v)) {
        last++;
        v--;
      }
      cout << "6 10 " << last << ' ' << v << endl;
    }
  }
  
  return 0;
}