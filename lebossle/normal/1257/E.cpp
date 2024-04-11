#include <bits/stdc++.h>
using namespace std;

int main() {
  int k1, k2, k3;
  cin >> k1 >> k2 >> k3;
  int n = k1+k2+k3;
  vector<int> dist(n);
  for (int i=0; i<k1; ++i) {
    int pos;
    cin >> pos;
    dist[pos-1] = 1;
  }
  for (int i=0; i<k2; ++i) {
    int pos;
    cin >> pos;
    dist[pos-1] = 2;
  }
  for (int i=0; i<k3; ++i) {
    int pos;
    cin >> pos;
    dist[pos-1] = 3;
  }
  vector<int> dp3(n+1, 0), dp23(n+1, 0), dp123(n+1, 0);
  for (int i=n-1; i>=0; --i) {
    dp3[i] = dp3[i+1] + (dist[i]==3 ? 0 : 1);
    dp23[i] = min(dp3[i], dp23[i+1] + (dist[i]==2 ? 0 : 1));
    dp123[i] = min(dp23[i], dp123[i+1] + (dist[i]==1 ? 0 : 1));
  }
  cout << dp123[0] << endl;
}