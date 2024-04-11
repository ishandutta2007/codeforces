#include <iostream>
#include <string>
using namespace std;
using ll = long long;

void testcase(){
  ll A,B; cin>>A>>B;
  if(B == 1){
    cout<<"NO\n";
    return;
  }
  cout<<"YES\n";
  cout<<A<<" "<<(A*B*2-A)<<" "<<(A*B*2)<<"\n";
}

int main(){
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