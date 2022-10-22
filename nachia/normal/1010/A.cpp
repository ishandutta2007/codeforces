#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N,M;
vector<double> A;

int main(){
  cin >> N >> M;
  A.resize(2*N);
  rep(i,N) cin >> A[i*2];
  cin >> A[N*2-1];
  rep(i,N-1) cin >> A[i*2+1];
  for(double a : A){ if(a == 1){ cout << "-1\n"; return 0; } }
  reverse(A.begin(),A.end());
  double ans = M;
  for(double a : A) ans = (a * ans) / (a - 1.0);
  ans -= M;
  cout << fixed << setprecision(10) << ans << "\n";
  return 0;
}


struct ios_do_not_sync{
  ios_do_not_sync(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }
} ios_do_not_sync_inst;