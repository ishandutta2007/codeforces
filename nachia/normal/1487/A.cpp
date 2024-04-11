#include <bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct cin_improve_speed{
  cin_improve_speed(){
    cin.tie(nullptr);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
  }
} cin_improve_speed_instance;

int N;
int A[100];

void loop(){
  cin>>N;
  rep(i,N) cin>>A[i];
  sort(A,A+N);
  int c=1;
  for(int i=1; i<N; i++) if(A[i]==A[0]) c++;
  cout<<(N-c)<<endl;
}

int main(){
  int T; cin>>T;
  while(T--) loop();
  return 0;
}