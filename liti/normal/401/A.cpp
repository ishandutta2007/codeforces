// In the name of Allah
#include <iostream>
using namespace std;
int main() { 
 int n,x,sum;
 sum = 0;
 cin >> n >> x;
 for( int i = 0 ; i < n ; i++ ) { 
  int tmp; cin >> tmp; sum += tmp;
 } 
 if( sum < 0 ) sum = -sum;
 cout << (sum+x-1)/x << endl;
}