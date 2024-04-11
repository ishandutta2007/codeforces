#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


const ull MOD = 998244353;

int N;
vector<ull> X,Y;
vector<int> InitialOn;

vector<ull> Cost;
vector<ull> sumCost;

int main(){
  cin >> N;
  X.resize(N);
  Y.resize(N);
  InitialOn.resize(N);
  rep(i,N) cin >> X[i] >> Y[i] >> InitialOn[i];

  Cost.assign(N,0);
  sumCost.assign(N+1,0);
  rep(i,N){
    int pre = upper_bound(X.begin(),X.end(),Y[i]) - X.begin();
    Cost[i] = sumCost[i] + MOD - sumCost[pre] + (X[i] - Y[i]);
    Cost[i] %= MOD;
    sumCost[i+1] = (sumCost[i] + Cost[i]) % MOD;
  }

  ull ans = X.back() + 1;
  rep(i,N) if(InitialOn[i]) ans += Cost[i];
  ans %= MOD;
  cout << ans << "\n";
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_instance;