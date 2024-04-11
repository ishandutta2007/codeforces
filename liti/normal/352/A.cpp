//In the name of Allah
#include <iostream>
using namespace std;
int cnt[10];

int main() { 
  int n;
  cin >> n;
  
  for( int i = 0 ; i < n ; i++ ) { 
    int num; cin >> num; cnt[num]++;
  }
  if( cnt[0] == 0 ) { cout << -1 << endl; return 0; } 
  int x = (cnt[5]/9)*9;
  for( int i = 0 ; i < x ; i++ ) 
    cout << 5;
  for( int i = 0 ; i < (x==0?1:cnt[0]) ; i++ ) 
    cout << 0;
  cout << endl;
}