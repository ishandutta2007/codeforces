#include <bits/stdc++.h>
using namespace std;

// This code uses the bossle/cp library
// Available at https://github.com/bossle/cp

// #pragma STDC FENV_ACCESS OFF
// #pragma STDC FP_CONTRACT ON
// #pragma STDC CX_LIMITED_RANGE ON
// #pragma GCC optimize "O3"

namespace cp_base {

auto init = (
  ios::sync_with_stdio(false),
  cin.tie(nullptr)
);

}  // namespace cp_base

       

#define LOG(x) 

typedef long long int lli;

const lli MOD = 1e9+7;

int main() {
  vector<int> primeFactor(2e6+1, -1);
  for (int i=2; i<primeFactor.size(); ++i) {
    if (primeFactor[i] == -1) {
      for (int j=i; j<primeFactor.size(); j+=i)
        primeFactor[j] = i;
    }
  }
  int n;
  cin >> n;
  vector<int> inp(n);
  for (int& i : inp)
    cin >> i;
  sort(inp.begin(), inp.end(), greater<int>());
  vector<int> pPow(2e6+1, 0), contributors(2e6+1, 0), choice(inp.size());
  for (int id=0; id<inp.size(); ++id) {
    int i = inp[id];
    if (pPow[i] == 0) {
      choice[id] = i;
      pPow[i] = 1;
      contributors[i] = 1;
    } else {
      choice[id] = i-1;
      int x = i-1;
      while (x > 1) {
        int f = primeFactor[x];
        int pow;
        for (pow=0; x%f==0; ++pow)
          x /= f;
        if (pPow[f] < pow) {
          pPow[f] = pow;
          contributors[f] = 1;
        } else if (pPow[f] == pow) {
          contributors[f]++;
        }
      }
    }
  }
  bool plus1 = false;
  for (int x : choice) {
    bool contributes = false;
    while (x > 1) {
      int f = primeFactor[x];
      int pow;
      for (pow=0; x%f==0; ++pow)
        x /= f;
      if (pPow[f] == pow && contributors[f] == 1)
        contributes = true;
    }
    if (!contributes)
      plus1 = true;
  }
  lli ans=1;
  for (int x=0; x<pPow.size(); ++x) {
    for (int i=0; i<pPow[x]; ++i)
      ans = (ans*x)%MOD;
  }
  if (plus1)
    ans = (ans+1)%MOD;
  cout << ans << endl;
}