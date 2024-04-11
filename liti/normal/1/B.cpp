//In the name of God
#include <bits/stdc++.h>
using namespace std;

int main() { 
 string s;
 int n;
 cin >> n;
 for( int i = 0 ; i < n ; i++ ) { 
   cin >> s;
   int (*a)(int) = &isalpha;
   int (*b)(int) = &isdigit;
   int cnt = 1;
   for( int j = 0 ; j < s.size() ; j++ ) 
     if( (*a)(s[j]) == 0 ) { 
       cnt++;
       swap(a,b);
     }
   if( cnt == 2 ) { 
     cout << "R";
     string tmp = "";
     for( int j = s.size() - 1 ; j >= 0 ; j-- ) { 
      if( !isdigit(s[j]) ) break;
      tmp = s[j] + tmp;
     }
     cout << tmp << "C" ;
     int x = 0;
     for( int j = 0 ; j < s.size() ; j++ ) { 
      if( isdigit(s[j]) ) break;
      x = x * 26 + s[j] - 'A' + 1;
     }
     cout << x << endl;
   } else { 
     int row = 0;
     int j;
     for( j = 1 ; j < s.size() ; j++ ) { 
       if( isalpha(s[j]) ) break;
       row = row*10 + s[j] - '0';
     }
     int x = 0;
     for( j = j + 1 ; j < s.size() ; j++ ) 
       x = x*10 + s[j] - '0';
     string tmp = "";
     x--;
     while( x ) {
       tmp = char(x%26 + 'A') + tmp;
       x /= 26;
       if( x == 1 ) {
        tmp  = 'A' + tmp;
        break;
       } if( x ) 
        x--;
     }
     cout << tmp << row << endl;
   }
 }
}