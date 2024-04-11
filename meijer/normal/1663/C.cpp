#include <bits/stdc++.h>
using namespace std;

int n;
int a[200];

int main() {
  cin >> n;
  for (int i=0; i<n; i++) cin >> a[i];
  int sm = 0;
  for (int i=0; i<n; i++) sm += a[i];
  cout << sm << endl;
}