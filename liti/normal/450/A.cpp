//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000 + 10;

int a[maxN];
int b[maxN];
int main() { 
 int n,m;
 cin >> n >> m;
 for( int i = 0 ; i <n ; i++ ) { 
  cin >> b[i];
  a[i] = i;
 }
 for( int i = 0 ; i < n ; i++ ) {
  b[a[i]]-=m;
  if( b[a[i]] > 0 ) a[n++] = a[i];
 }
 cout << a[n-1] + 1 << endl;
}