#include <iostream>
#include <vector>
#include <string>
using namespace std;

void testcase(){
  int N,X; cin>>N>>X;
  vector<int> A(N); for(int i=0; i<N; i++) cin>>A[i];
  vector<int> ans;
  int sum = 0;
  while(A.size()){
    if(sum + A.back() == X){
      if(A.size() == 1){ cout<<"NO\n"; return; }
      swap(A.front(),A.back());
    }
    ans.push_back(A.back());
    sum += A.back();
    A.pop_back();
  }
  cout<<"YES\n";
  for(int i=0; i<N; i++){
    if(i) cout<<" ";
    cout<<ans[i];
  }
  cout<<"\n";
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