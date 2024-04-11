//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
 int n,m,k; cin >> n >> m >> k;
 int ret = 0 ;
 for( int i = 0 ; i < n ; i++ ) { 
  int num;
  cin >> num;
  if( num == 1 ) m--;
  else k--;
  if( k < 0 ) k = 0 , m --;
  if( m < 0 ) m = 0 , ret ++;
 }
 cout << ret << endl;
}