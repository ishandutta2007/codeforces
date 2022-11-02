//In the name of Allah
#include <iostream>
using namespace std;

int main() { 
 int ret, cnt; cnt = ret = 0; 
 int n; cin >> n;
 for( int i = 0 ; i < n ; i++ ) { 
  int num;
  cin >> num;
  if( num > 0 ) cnt += num;
  else { 
   if( cnt == 0 ) ret++; 
   else cnt--;
  }
 }
 cout << ret << endl;
}