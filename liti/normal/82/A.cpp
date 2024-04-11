#include <iostream>
using namespace std;

string s[] = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" } ; 
int a[5];

int main() { 
  int n;
  cin >> n;
  while( 1 ) { 
    for( int i = 0 ; i < 5 ; i++ ) { 
      a[i] = max(1,a[i]*2);
      n -= a[i]; 
      if( n <= 0 ) { 
        cout << s[i] << endl;
        return 0;
      }
    }
  }
}