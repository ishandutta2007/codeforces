//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
int a[101];
int main() { 
 int n;
 cin >> n;
 for( int t = 0 ; t < 2 ; t++ ) {
  int c; cin >> c;
  for( int i = 0 ; i < c ; i++ ) { 
   int num; cin >> num;
   a[num] = 1; 
  } 
 }
 cout << ( accumulate(a+1,a+n+1,0) == n ? "I become the guy." : "Oh, my keyboard!" ) << endl;
}