
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void testcase(){
  int H,W; cin >> H >> W;
  vector<string> ans(H,string(W,'0'));
  for(int x=0; x<W; x+=2) ans[0][x] = ans[H-1][W-1-x] = '1';
  for(int y=2; y<H-2; y+=2) ans[y][0] = ans[H-1-y][W-1] = '1';
  rep(y,H) cout << ans[y] << "\n";
}

int main() {
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;