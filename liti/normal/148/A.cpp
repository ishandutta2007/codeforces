#include <iostream>
using namespace std;
const int maxN = 100*1000 + 10;
int a[maxN];
int main() { 
  for( int i = 0 ; i < 4 ; i++ ) { 
      int x;
      cin >> x;
      for( int j = x ; j < maxN ; j+= x ) 
          a[j] = 1;
  }
  int d;
  cin >> d;
  int ret = 0;
  for( int i = 1 ; i <= d ; i++ ) 
      ret += a[i];
  cout << ret << endl;
}