
#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)


vector<int> sieve;
vector<int> nsq_factor;

int N;
vector<int> A;


void init(){
  const int Z = 1'000'000;
  nsq_factor.resize(Z+1);
  sieve.resize(Z+1);
  rep(i,Z+1) nsq_factor[i] = i;
  for(int p=2; p*p<=Z; p++) if(sieve[p] == 0){
    for(int i=p*p; i<=Z; i+=p) sieve[i] = 1;
    for(ll pk=p*p; pk<=Z; pk*=p*p){
      for(int j=pk; j<=Z; j+=pk){
        nsq_factor[j] /= p*p;
      }
    }
  }
}

void testcase(){
  cin >> N;
  A.resize(N);
  rep(i,N) cin >> A[i];

  map<int,int> C;
  rep(i,N) C[nsq_factor[A[i]]]++;

  int ans0 = 0;
  for(auto a : C) ans0 = max(ans0,a.second);
  int ans1 = 0;
  for(auto a : C) if(a.second % 2 == 0 || a.first == 1) ans1 += a.second;
  ans1 = max(ans0,ans1);

  int Q; cin >> Q;
  while(Q--){
    ll w; cin >> w;
    if(w == 0) cout << ans0 << "\n";
    else cout << ans1 << "\n";
  }
}

int main(){
  init();
  int T; cin >> T; while(T--)
  testcase();
  return 0;
}

struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;