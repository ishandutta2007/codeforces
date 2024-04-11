
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

const ll INF = 1001001001001001001;

void testcase(){
  string S; cin >> S;
  int N = S.size();
  ll X,Y; cin >> X >> Y;
  if(X > Y){
    for(char& c : S){
      if(c == '0') c = '1';
      else if(c == '1') c = '0';
    }
    swap(X,Y);
  }
  
  vector<int> cnt0(N+1,0);
  vector<int> cnt1(N+1,0);
  vector<int> cntQ(N+1,0);
  rep(i,N){
    if(S[i] == '0') cnt0[i+1]++;
    if(S[i] == '1') cnt1[i+1]++;
    if(S[i] == '?') cntQ[i+1]++;
    cnt0[i+1] += cnt0[i];
    cnt1[i+1] += cnt1[i];
    cntQ[i+1] += cntQ[i];
  }

  vector<ll> sumL(N+1,0);
  {
    ll cnt0 = 0;
    ll cnt1 = 0;
    for(int i=0; i<N; i++){
      if(S[i] == '1'){
        sumL[i+1] += cnt0 * X;
        cnt1++;
      }
      else{
        sumL[i+1] += cnt1 * Y;
        cnt0++;
      }
    }
    rep(i,N) sumL[i+1] += sumL[i];
  }
  vector<ll> sumR(N+1,0);
  {
    ll cnt0 = 0;
    ll cnt1 = 0;
    for(int i=N-1; i>=0; i--){
      if(S[i] == '0'){
        sumR[i] += cnt1 * X;
        cnt0++;
      }
      else{
        sumR[i] += cnt0 * Y;
        cnt1++;
      }
    }
    rep(i,N) sumR[N-1-i] += sumR[N-i];
  }

  ll ans = INF;
  rep(i,N+1){
    ll tmp = sumL[i] + sumR[i];
    tmp += X * (cnt0[i] + cntQ[i]) * ((cnt1[N]-cnt1[i]) + (cntQ[N]-cntQ[i]));
    tmp += Y * cnt1[i] * (cnt0[N]-cnt0[i]);
    ans = min(ans,tmp);
  }
  cout << ans << "\n";
}

int main(){
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;