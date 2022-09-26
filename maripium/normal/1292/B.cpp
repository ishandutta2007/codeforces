#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 2e18;

int main() {
   ios_base::sync_with_stdio(false);
   ll X0, Y0, AX, AY, BX, BY, XS, YS, T;
   cin >> X0 >> Y0 >> AX >> AY >> BX >> BY >> XS >> YS >> T;
   vector<pair<ll, ll>> pts = {{X0, Y0}};
   while (true) {
      ll x, y;
      tie(x, y) = pts.back();
      if (x > INF / AX || y > INF / AY) {
         break;
      } else {
         pts.emplace_back(x * AX + BX, y * AY + BY);
      }
   }
   int ans = 0;
   for (int i = 0; i < pts.size(); ++i) {
      ll curCost = abs(XS - pts[i].first) + abs(YS - pts[i].second);
      if (curCost > T) continue;
      curCost = T - curCost;
      int cur = 1;
      for (int j = i - 1; j >= 0; --j) {
         ll nxtCost = pts[j + 1].first + pts[j + 1].second - pts[j].first - pts[j].second;
         if (nxtCost > curCost) break;
         else {
            curCost -= nxtCost;
            cur++;
         }
      }
      ans = max(ans, cur);
      curCost = T - abs(XS - pts[i].first) - abs(YS - pts[i].second);
      cur = 1;
      for (int j = i + 1; j < pts.size(); ++j) {
         ll nxtCost = pts[j].first + pts[j].second - pts[j - 1].first - pts[j - 1].second;
         if (nxtCost > curCost) break;
         else {
            curCost -= nxtCost;
            cur++;
         }
      }
      ans = max(ans, cur);
   }
   cout << ans << "\n";
}