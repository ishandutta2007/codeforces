#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll a,b,c,l;
    cin>>a>>b>>c>>l;

    ll ans = 0;
    
    for (ll i = 0; i <= l; i += 1) {
         ans += (i + 1)*(i + 2) / 2;
    }
    
    for (ll la = 0; la <= l; la += 1) {
         ll x = a - b - c + la;
         if (x > l - la) {
              x = l - la;
         }

         if (x < 0) {
              continue;
         }
         
         ans -= (x + 1)*(x + 2) / 2;
    }

    for (ll lb = 0; lb <= l; lb += 1) {
         ll x = b - a - c + lb;
         if (x > l - lb) {
              x = l - lb;
         }

         if (x < 0) {
              continue;
         }
         
         ans -= (x + 1)*(x + 2) / 2;
    }

    for (ll lc = 0; lc <= l; lc += 1) {
         ll x = c - a - b + lc;
         if (x > l - lc) {
              x = l - lc;
         }

         if (x < 0) {
              continue;
         }
         
         ans -= (x + 1)*(x + 2) / 2;
    }
    
    cout<<ans<<'\n';    
}

int main()
{
      solve();
}