#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void testcase(){
  int L,R,N; cin>>N>>L>>R;
  vector<int> A(L); for(int i=0; i<L; i++){ cin>>A[i]; A[i]--; }
  vector<int> B(R); for(int i=0; i<R; i++){ cin>>B[i]; B[i]--; }
  if(L > R){ swap(L,R); swap(A,B); }
  vector<int> C(N);
  vector<int> CB(N);
  int ans = (R-L)/2 + (N/2);
  int RRmatchesLeft = (R-L)/2;
  for(int i=0; i<L; i++) C[A[i]]++;
  for(int b : B){
    if(C[b] >= 1){
      C[b]--;
      ans--;
    }
    else if(RRmatchesLeft != 0 && CB[b] >= 1){
      CB[b]--;
      RRmatchesLeft--;
      ans--;
    }
    else{
      CB[b]++;
    }
  }
  cout<<ans<<"\n";
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