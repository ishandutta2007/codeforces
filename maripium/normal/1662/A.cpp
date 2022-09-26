#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second

const int SQ = 400;
int b[105];
void go(){
  int n;
  cin>>n;
  for(int i = 1; i <= 10; ++i)
    b[i] = -1000;
  for(int i = 1; i <= n; ++i){
    int bb, dd;
    cin>>bb>>dd;
    b[dd] = max(b[dd], bb);
  }
  int s = 0;
  for(int i = 1; i <= 10; i++){
    s += b[i];
  }
  if(s < 0){
    cout<<"MOREPROBLEMS\n";
  } else {
    cout<<s<<'\n';
  }
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