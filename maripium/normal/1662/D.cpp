#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
const int SQ = 400;
const int N = 200005;

void go(){
  string v, u;
  cin>>v>>u;
  string vv = "", uu = "";

  int t = 0;
  for(auto c : v){
    if(c == 'B') ++t;
    else if(c == 'A'){
      if(vv.empty() || vv.back() != 'A') vv.push_back('A');
      else vv.pop_back();
    }
    else if(c == 'C'){
      if(vv.empty() || vv.back() != 'C') vv.push_back('C');
      else vv.pop_back();
    }
  }
  if(t & 1) vv.push_back('B');

  t = 0;
  for(auto c : u){
    if(c == 'B') ++t;
    else if(c == 'A'){
      if(uu.empty() || uu.back() != 'A') uu.push_back('A');
      else uu.pop_back();
    }
    else if(c == 'C'){
      if(uu.empty() || uu.back() != 'C') uu.push_back('C');
      else uu.pop_back();
    }
  }
  if(t & 1) uu.push_back('B');

  cout<<(vv == uu ? "YES\n" : "NO\n");
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