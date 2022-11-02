//In the name of Allah
#include <bits/stdc++.h>
using namespace std;
int cnt[2];
int main() { 
  int n;
  cin >> n;
  deque<int> a;
  for( int i = 0 ; i < n ; i++ ) { 
    int x; cin >> x; a.push_back(x);
  }
  for( int i = 0 ; i < n ; i++ )
    if( a.front() > a.back() ) {
      cnt[i%2] += a.front(); a.pop_front();
    } else { 
      cnt[i%2] += a.back(); a.pop_back();
    }
  cout << cnt[0] << ' ' << cnt[1] << endl;
}