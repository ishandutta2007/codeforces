#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;

  while(t--){
    int n, m;
    cin>>n>>m;

    int sx = 0, sy = 0;

    cout<<"SCAN 1 1"<<endl;
    int t1;
    cin>>t1;

    cout<<"SCAN 1 "<<m<<endl;
    int t2;
    cin>>t2;

    sx = ((t1 + t2) - (m - 1) * 2)/2;
    sy = (t1 - sx);

    int mx = sx / 2 + 1, my = sy / 2 + 1;

    cout<<"SCAN 1 "<<my<<endl;
    cin>>t2;

    cout<<"SCAN "<<mx<<" 1"<<endl;
    cin>>t1;

    t2 -= sx;
    t1 -= sy;

    int dy = t2;
    int dx = t1;

    int x1, y1, x2, y2;
    x1 = 1 + (sx - dx) / 2;
    x2 = 1 + (sx + dx) / 2;
    y1 = 1 + (sy - dy) / 2;
    y2 = 1 + (sy + dy) / 2;

    cout<<"DIG "<<x1<<' '<<y1<<endl;
    cin>>t1;
    if(t1 == 1){
      cout<<"DIG "<<x2<<" "<<y2<<endl;
      cin>>t1;
    } else {
      cout<<"DIG "<<x1<<" "<<y2<<endl;
      cin>>t1;
      cout<<"DIG "<<x2<<" "<<y1<<endl;
      cin>>t1;
    }
  }
}