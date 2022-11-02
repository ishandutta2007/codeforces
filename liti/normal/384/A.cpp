//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
 int n;
 cin >> n;
 cout << n*n - n*n/2 << endl;
 for( int i = 0 ; i < n ; i++ ) {
   for( int j = 0 ; j < n ; j++ ) 
     cout << ((i+j)%2==0?'C':'.') ;
   cout << endl;
 }
}