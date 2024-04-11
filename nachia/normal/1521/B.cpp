#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void testcase(){
  int N; cin>>N;
  vector<int> A(N); rep(i,N) cin>>A[i];
  int mi = 0; rep(i,N) if(A[mi] > A[i]) mi = i;
  cout << (N-1) << "\n";
  rep(i,N) if(mi != i){
    int tg = A[mi] + (mi+i)%2;
    cout << (mi+1) << " " << (i+1) << " " << A[mi] << " " << tg << "\n";
  }
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