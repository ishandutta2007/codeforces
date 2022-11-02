//In the name of God
#include <bits/stdc++.h>;
using namespace std;
int a[30][60];
int main() { 
 int ret = 0;
 int n;
 cin >> n;
 for( int i = 0 ; i <n ; i++ ) { 
  int a,b;
  cin >> a >> b;
  ret = max( ret,++::a[a][b]);
 }
 cout << ret << endl;
}