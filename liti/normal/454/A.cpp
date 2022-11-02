//In the name of Allah
#include <iostream>
using namespace std;
char a[101][101];
int main() { 
 int n;
 cin >> n;
 int x = n/2;
 for( int i = 0 ; i < n ;i++ ) for( int j = 0 ; j < n ; j++ ) a[i][j] = '*';
 for( int i = 0 ; i < x + 1 ; i++ ) { 
  for( int j = i ; j + i < n ; j++ ) 
   a[x+i][j] = a[x-i][j] = 'D';
 }
 for( int i = 0 ; i < n ; i++ ) { 
  for( int j = 0 ; j < n ;j ++ ) 
   cout << a[i][j];
  cout << endl;
 }
}