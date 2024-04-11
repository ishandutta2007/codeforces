//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
pair<int,int> a[10000];
int main() { 
 int s,n;
 cin >> s >> n;
 for( int i = 0 ; i < n ; i++ ) cin >> a[i].first >> a[i].second;
 sort( a , a + n ) ;  
 for( int i =0 ; i < n ; i++ ) { 
  int a = ::a[i].first , b = ::a[i].second;
  if( s <= a ) { cout << "NO" << endl; return 0; } 
  s += b;
 }
 cout << "YES" << endl;
}