#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

template<class T> using nega_queue = priority_queue<T,vector<T>,greater<T>>;

void testcase(){
  int N,M,X; cin>>N>>M>>X;
  vector<int> A(N); for(int i=0; i<N; i++) cin>>A[i];
  nega_queue<pair<int,int>> Q;
  vector<int> sum(M);
  vector<int> ans(N);
  for(int i=0; i<M; i++) Q.push({sum[i],i});
  for(int i=0; i<N; i++){
    int p = Q.top().second; Q.pop();
    sum[p] += A[i];
    ans[i] = p;
    Q.push({sum[p],p});
  }
  cout<<"YES\n";
  for(int i=0; i<N; i++){
    if(i) cout<<" ";
    cout<<(ans[i]+1);
  } cout<<"\n";
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