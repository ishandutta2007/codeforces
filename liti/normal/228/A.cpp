#include <iostream>
#include <algorithm>
using namespace std;
int main() {
 int a[4];for( int i = 0 ; i < 4 ; i++ ) cin >> a[i];
 int cnt = 0;
 sort( a , a + 4 ) ; for( int i=1 ; i < 4 ; i++ ) if( a[i] == a[i-1] ) cnt++;
 cout << cnt << endl;
}