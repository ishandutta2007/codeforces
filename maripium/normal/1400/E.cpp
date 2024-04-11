#include <bits/stdc++.h>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   int N; cin >> N;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) cin >> A[i];
   function<int(int, int, int)> go = [&](int l, int r, int prv) {
      int ans1 = r-l+1;
      int cur = *min_element(A.begin()+l, A.begin()+r+1);
      int ans2 = cur - prv;
      for (int i = l; i <= r; ) {
         while (i <= r && A[i] == cur) i++;
         if (i > r) break;
         int j = i;
         while (j <= r && A[j] > cur) j++;
         ans2 += go(i, j-1, cur);
         i=j;
      }
      return min(ans1, ans2);
   };
   cout << go(0, N-1, 0) << '\n';
   return 0;
}