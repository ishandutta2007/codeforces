#include <bits/stdc++.h>
using namespace std;

int main() { 
 int a,b,n;
 cin >> a >> b >> n;
 for( int ret = 0; ; ret++ ) { 
   n -= __gcd( n , a ) ;
   swap(a,b);
   if( n == 0 ) { 
     cout << ret % 2 << endl;
     return 0;
   } 
 }
}