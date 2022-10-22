#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

bool solve() {

   int n, p;
   cin >> n >> p;
   
   vec< string > s(n);
   
   for(int i = 0;i < n;i++) cin >> s[i];
   
   ll now = 0;
   
   for(int i = n - 1;i >= 0;i--) {
      if(s[i] == "halfplus") {
         now = now * 2 + 1;
      }else now = now * 2;
   }
   
   ll ans = 0;
   
   for(int i = 0;i < n;i++) {
      if(now % 2) {
         ans = ans + (now / 2ll) * (ll)p + (ll)p / 2ll;
      }else ans = ans + (now / 2) * p;
      now /= 2;
   }

   cout << ans << '\n';

   return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}