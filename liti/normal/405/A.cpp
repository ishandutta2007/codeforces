//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
int a[100];
int main() {
 int n;
 cin >> n;
 for( int i =0  ; i < n ; i++ ) cin >> a[i];
 sort( a , a + n ) ; 
 copy( a , a + n , ostream_iterator<int>( cout , " " ) ) ;
}