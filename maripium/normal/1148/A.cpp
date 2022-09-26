#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   long long a, b, c; cin >> a >> b >> c;
   cout << 2 * min(a, b) + 2 * c + (a != b) << endl;
}