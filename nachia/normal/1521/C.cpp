#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(n); i++)

void testcase(){
  int N; cin>>N; if(N == -1) exit(0);
  int l=0, r=N;
  while(r-l>1){
    int m=(l+r)/2;
    cout<<"? 1 2 1 "<<m<<"\n"<<flush;
    int res1; cin>>res1; if(res1 == -1) exit(0);
    cout<<"? 2 1 2 "<<m<<"\n"<<flush;
    int res2; cin>>res2; if(res2 == -1) exit(0);
    if(res2 == m) r=m;
    else if(res1 == m+1) l=m;
    else exit(0);
  }
  vector<int> A(N,-1);
  A[0] = r;
  if(A[0] > N/2){
    rep(i,N) if(A[i]==-1){
      cout<<"? 2 "<<(i+1)<<" 1 "<<(1)<<"\n"<<flush;
      int res; cin>>res; if(res == -1) exit(0);
      if(res < A[0]) A[i] = res;
    }
    rep(i,N) if(A[i]==-1){
      cout<<"? 1 1 "<<(i+1)<<" "<<(N-1)<<"\n"<<flush;
      int res; cin>>res; if(res == -1) exit(0);
      A[i] = res;
    }
  }
  else{
    rep(i,N) if(A[i]==-1){
      cout<<"? 1 1 "<<(i+1)<<" "<<(N-1)<<"\n"<<flush;
      int res; cin>>res; if(res == -1) exit(0);
      if(res > A[0]) A[i] = res;
    }
    rep(i,N) if(A[i]==-1){
      cout<<"? 2 "<<(i+1)<<" 1 "<<(1)<<"\n"<<flush;
      int res; cin>>res; if(res == -1) exit(0);
      A[i] = res;
    }
  }
  cout<<"!"; rep(i,N) cout<<" "<<A[i]; cout<<"\n"<<flush;
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