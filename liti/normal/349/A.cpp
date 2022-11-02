//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
 int n;
 cin >> n;
 int a , b , c, num; a = c = b = 0;
 bool ch = true;
 for( int i =  0 ; i < n ; i++ ) { 
  cin >> num;
  if( num == 25 ) a++;
  else if( num == 50 ) { 
   if( a == 0 ) ch = false;
   else a--;
b++;
  } else {
   if( b ) {
    if( a ) { a--; b--; }
    else ch = false;
   } else if( a > 2 ) a -= 3;
   else ch = false;
  }
 }
 cout << (ch?"YES":"NO") << endl;
}