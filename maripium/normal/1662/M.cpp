#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

const int SQ = 400;
int b[105];
void go(){
  int n, m;
  cin>>n>>m;
  int r = 0, w = 0;
  while(m--){
    int rr, ww;
    cin>>rr>>ww;
    r = max(r, rr);
    w = max(w, ww);
  }
  if(r + w > n){
    cout<<"IMPOSSIBLE\n";
    return;
  }
  w = max(n - r, w);
  while(w--)
    cout<<'W';
  while(r--)
    cout<<'R';
  cout<<'\n';
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin>>t;
  while(t--){
    go();
  }
}