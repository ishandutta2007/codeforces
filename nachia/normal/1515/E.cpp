#include <iostream>
#include <vector>
//#include <queue>
using namespace std;
using ll = long long;
using ull = unsigned long long;

//template<class T> using nega_queue = priority_queue<T,vector<T>,greater<T>>;

int N;
ull M;

vector<ull> F,I,iF;
void initCombination(int Z){
  F.assign(Z+1,1);
  for(int i=1; i<=Z; i++) F[i] = F[i-1] * i % M;
  I.assign(Z+1,1);
  for(int i=2; i<=Z; i++) I[i] = M - M / i * I[M%i] % M;
  iF.assign(Z+1,1);
  for(int i=1; i<=Z; i++) iF[i] = iF[i-1] * I[i] % M;
}
ull Combination(int n,int r){
  return F[n] * iF[r] % M * iF[n-r] % M;
}

vector<ull> Pow2;
void initPos2(int Z){
  Pow2.assign(Z+1,1);
  for(int i=1; i<=Z; i++) Pow2[i] = Pow2[i-1] * 2 % M;
}

vector<vector<ull>> dp;

void testcase(){
  int N; cin>>N>>M; N++;
  initCombination(N);
  initPos2(N);

  dp.assign(N+1,vector<ull>(N+1,0));
  dp[0][0] = 1;
  for(int i=0; i<N; i++) for(int k=0; k<=N; k++){
    for(int d=2; d<=N; d++){
      if(i+d > N) break;
      if(k+d-1 > N) break;
      dp[i+d][k+d-1] += dp[i][k] * iF[d-1] % M * Pow2[d-2];
      dp[i+d][k+d-1] %= M;
    }
  }

  ull ans = 0;
  for(int k=0; k<=N; k++){
    ans += dp[N][k] * F[k];
    ans %= M;
  }
  cout<<ans<<"\n";
}

int main(){
  int T; //cin>>T;
  T=1;
  while(T--) testcase();
  return 0;
}



struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;