//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
int a[3000];
int main() { 
 int n,k;
 cin >>n >> k;
 for( int i =0 ; i < n ;i++ ) 
  cin >> a[i];
 sort( a , a + n , greater<int>() ) ; 
 int ret = 0;
 for( int i = 0 ; i < n ; i+=k ) 
  ret += 2*(a[i]-1);
 cout << ret << endl;
}