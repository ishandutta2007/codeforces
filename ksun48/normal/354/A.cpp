#include<iostream>
using namespace std;
typedef long long LL;

int main(){
  int n, l, r, ql, qr;
  cin >> n >> l >> r >> ql >> qr;
  int w[n];
  int sum = 0;
  for(int i = 0; i < n; i++){
    cin >> w[i];
    sum += w[i];
  }
  int cur = 0;
  int ans = 2000000000;
  for(int i = 0; i <= n; i++){
    int k = l*cur + r*(sum-cur);
    if(i > n-i){
      k += ql*(2*i-n-1);
    } else if(i<n-i){
      k += qr*(n-2*i-1);
    }
    ans = min(ans, k);
    cur += w[i];
  }
  cout << ans << endl;
}