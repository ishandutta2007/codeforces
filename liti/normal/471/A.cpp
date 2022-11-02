// In the name of Allah
#include <iostream>
using namespace std;
int a[10];
int main() { 
 for( int i = 0 ; i < 6 ; i++ ) { 
  int num; cin >> num; a[num]++;
 }
 bool cfg = false;
 for( int i = 0 ; i < 10 ; i++ ) 
  if( a[i] >= 4 ) { 
   a[i]-=4;
   cfg = true;
  }
 if( !cfg ) { cout << "Alien" << endl; return 0; } 
 for( int i = 0 ; i < 10 ; i++ ) 
  if( a[i] == 2 ) { cout << "Elephant" << endl; return 0; } 
  cout << "Bear" << endl;
}