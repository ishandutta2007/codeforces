#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int X[3], Y[3];
    for (int z = 0; z < 3; ++z) {
      cin >> X[z] >> Y[z];
    }

    auto getMed = [&](int A[3]) {
      int mx = max({A[0], A[1], A[2]});
      int mn = min({A[0], A[1], A[2]});
      return A[0] + A[1] + A[2] - mn - mx;
    };

    int tx = getMed(X);
    int ty = getMed(Y);
    vector<array<int, 4>> ans;
    for (int z = 0; z < 3; ++z) {
      int sx = X[z];
      int sy = Y[z];
      if (sx != tx) {
        ans.push_back({sx, sy, tx, sy});
        sx = tx;
      }
      if (sy != ty) {
        ans.push_back({tx, sy, tx, ty});
      }
    }

    cout << int(ans.size()) << '\n';
    for (auto v : ans) {
      cout << v[0] << ' ' << v[1] << ' ' << v[2] << ' ' << v[3] << '\n';
    }
    return 0;
}