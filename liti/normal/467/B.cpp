//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

int a[1005];
int main() { 
  int n,m,k;
  cin >> n >> m >> k;
  for( int i = 0 ; i < m ; i++ ) cin >> a[i];
  int x; cin >> x; 
  int ret = 0;
  for( int i = 0 ; i < m ; i++ ) if( __builtin_popcount((x^a[i])) <= k ) ret++;
  cout << ret << endl;
}