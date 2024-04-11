#include <iostream>
#include <set>
using namespace std;
using ll = long long;

set<ll> X;

void testcase(){
  ll N; cin>>N;
  if(X.count(N) != 0){ cout<<"YES\n"; return; }
  cout << "NO\n";
}

int main(){
  for(ll x=1; x<40000; x++) X.insert(x*x*2);
  for(ll x=1; x<40000; x++) X.insert(x*x*4);
  int T; cin>>T;
  while(T--) testcase();
  return 0;
}



struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;