#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int n, k; cin >> n >> k;
   int d = (n - k) / 2 + 1;
   for (int i = 0; i < n; ++i) cout << (i % d == d - 1);
}