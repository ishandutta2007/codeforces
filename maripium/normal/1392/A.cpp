#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);
   int T; cin >> T;
   while (T--) {
   int N; cin >> N;
   vector<int> A(N);
   for (int &x : A) cin >> x;
   if (*max_element(A.begin(), A.end()) == *min_element(A.begin(), A.end())) {
      cout << N << '\n';
   } else {
      cout << "1\n";
   }
   }
}