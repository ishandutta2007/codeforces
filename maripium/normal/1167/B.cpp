#include <bits/stdc++.h>

using namespace std;

int get(int i,int j) {
   cout << "? " << i << ' ' << j << endl;
   int ans; cin >> ans;
   return ans;
}

int main() {
   vector<int> a = {4, 8, 15, 16, 23, 42};

   vector<vector<int>> val(6);

   for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) if (i != j) {
         val[i].push_back(a[i] * a[j]);
      }
   }

   vector<int> ans(6);

   ans[0] = sqrt(get(1, 1));
   ans[1] = sqrt(get(2, 2));
   int g34 = get(3, 4);
   int g35 = get(3, 5);

   for (int i = 0; i < 6; ++i) {
      if (!binary_search(val[i].begin(), val[i].end(), g34)) continue;
      if (!binary_search(val[i].begin(), val[i].end(), g35)) continue;
      ans[2] = a[i];
   }

   ans[3] = g34 / ans[2];
   ans[4] = g35 / ans[2];

   ans[5] = accumulate(a.begin(), a.end(), 0) - accumulate(ans.begin(), ans.end(), 0);

   cout << "! ";
   for (int v : ans) cout << v << ' ';
   cout << endl;
}