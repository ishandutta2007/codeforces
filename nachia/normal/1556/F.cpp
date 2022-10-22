
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
#define rep(i,n) for(int i=0; i<(n); i++)

const u32 MOD = 1000000007;

u32 powm(u32 a, u64 i){
  u32 r = 1;
  while(i){
    if(i&1) r = (u64)r * a % MOD;
    a = (u64)a * a % MOD;
    i /= 2;
  }
  return r;
}

u32 inv_mod(u32 a){ return powm(a,MOD-2); }
u32 add_mod(u32 a, u32 b){ a += b; if(a >= MOD) a -= MOD; return a; }
u32 sub_mod(u32 a, u32 b){ a += MOD - b; if(a >= MOD) a -= MOD; return a; }
u32 mul_mod(u32 a, u32 b){ return (u64)a * b % MOD; }
u32 div_mod(u32 a, u32 b){ return mul_mod(a,inv_mod(b)); }


void testcase(){
  int N; cin >> N;
  vector<u32> A(N); rep(i,N) cin >> A[i];
  vector<vector<u32>> Win(N,vector<u32>(N));
  rep(i,N) rep(j,N) Win[i][j] = div_mod(A[i], add_mod(A[i],A[j]));
  vector<u32> dptemplate(1<<N,1);
  rep(b,1<<N) rep(i,N) rep(j,N) if(!(b&(1<<i))) if(b&(1<<j)) dptemplate[b] = mul_mod(dptemplate[b],Win[i][j]);
  vector<vector<pair<u32,int>>> dp2(1<<N);
  rep(i,1<<N){
    for(int j=i; j<(1<<N); j=(j+1)|i) if(j!=i){
      int d0 = (1<<N) - 1 - j;
      int d2 = j - i;
      u32 tmp = 1;
      rep(a,N) if(d2&(1<<a)) rep(b,N) if(d0&(1<<b)) tmp = mul_mod(tmp,Win[b][a]);
      dp2[i].push_back({tmp,j});
    }
  }
  u32 ans = 0;
  rep(s,N){
    vector<u32> dp = dptemplate;
    rep(i,1<<N) if(!(i&(1<<s))) dp[i] = 0;
    for(int i=1<<s; i<(1<<N); i=(i+1)|(1<<s)) for(auto a : dp2[i]){
      int j = a.second;
      dp[j] = sub_mod(dp[j], mul_mod(dp[i], a.first));
    }
    ans = add_mod(ans,dp[(1<<N)-1]);
  }
  cout << ans << endl;
}

int main(){
  //int T; cin >> T;
  //rep(t,T)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;