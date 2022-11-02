
//In the name of Allah
#include <iostream>
using namespace std;

const int maxN = 100 + 10;
char a[maxN][maxN];
int dx[] = { 0 , -1 , 0 , 1 } ; 
int dy[] = { -1 , 0 , 1 , 0 } ;
int main() { 
  int n;
  cin >> n;
  for( int i = 0 ; i < n ; i++ ) 
    for( int j = 0 ;j < n ; j++ ) 
      cin >> a[i][j];
  for( int i = 0 ; i < n ; i++ ) 
  for(int j = 0 ; j < n ; j++ ) { 
    int x = 0;
    for( int k = 0 ; k < 4 ; k++ ) 
      if( i + dx[k] >= 0 && i + dx[k] < n && 
        j + dy[k] >= 0 && j + dy[k] < n ) 
          x += (a[i+dx[k]][j+dy[k]] == 'o');
    if( (x % 2==1) ) { cout << "NO" << endl; return 0; }
  }
  cout << "YES" << endl;
}