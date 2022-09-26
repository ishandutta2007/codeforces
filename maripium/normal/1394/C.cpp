#include <bits/stdc++.h>

using namespace std;

const int MX = 500500;

int N;
int cnts[MX][2];

pair<int, int> solve(int mid) {
   for (int z = 0; z < 2; ++z) {
      int low_x = 0;
      int low_y = 0;
      int high_x = MX - 1;
      int high_y = MX - 1;
      if (z) low_y = 1;
      else low_x = 1;
      int low_diff = -MX + 1; // diff = y - x
      int high_diff = MX - 1;
      for (int i = 0; i < N; ++i) {
         int x = cnts[i][0];
         int y = cnts[i][1];
         low_x = max(low_x, x - mid);
         low_y = max(low_y, y - mid);
         high_x = min(high_x, x + mid);
         high_y = min(high_y, y + mid);
         low_diff = max(low_diff, y - x - mid);
         high_diff = min(high_diff, y - x + mid);
      }
      if (low_x > high_x) continue;
      if (low_y > high_y) continue;
      low_diff = max(low_diff, low_y - high_x);
      high_diff = min(high_diff, high_y - low_x);
      if (low_diff > high_diff) continue;
      for (int x = low_x; x <= high_x; ++x) {
         int yl = x + low_diff;
         int yr = x + high_diff;
         yl = max(yl, low_y);
         yr = min(yr, high_y);
         if (yl <= yr) return make_pair(x, yl);
      }
   }
   return make_pair(-1, -1);
}

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      string S; cin >> S;
      cnts[i][0] = count(S.begin(), S.end(), 'B');
      cnts[i][1] = count(S.begin(), S.end(), 'N');
   }
   int low = 0, high = MX - 1;
   while (low < high) {
      int mid = (low + high) >> 1;
      if (solve(mid) != make_pair(-1, -1)) high = mid;
      else low = mid + 1;
   }
   int a, b;
   tie(a, b) = solve(low);
   cout << low << '\n';
   cout << string(a, 'B') << string(b, 'N') << '\n';
}