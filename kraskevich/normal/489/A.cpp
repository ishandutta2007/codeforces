#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector<int> L;
  vector<int> R;
  for (int i = 0; i < n; i++) {
    int p = min_element(a.begin() + i, a.end()) - a.begin();
    if (p != i) {
      swap(a[p], a[i]);
      L.push_back(i);
      R.push_back(p);
    }
  }
  cout << L.size() << endl;
  for (int i = 0; i < L.size(); i++)
    cout << L[i] << " " << R[i] << endl;
  return 0;
}