#include <bits/stdc++.h>

using namespace std;

multiset<multiset<char>> query(int l, int r) {
   if (l > r) {
      return {};
   }
   cout << "? " << l + 1 << " " << r + 1 << endl;
   int len = (r - l + 1);
   int numSubt = len * (len + 1) / 2;
   multiset<multiset<char>> ans;
   for (int z = 0; z < numSubt; ++z) {
      string s;
      cin >> s;
      multiset<char> ss;
      for (char c : s) {
         ss.emplace(c);
      }
      ans.emplace(ss);
   }
   return ans;
}

int main() {
   ios_base::sync_with_stdio(false);
   int N;
   cin >> N;
   auto l = query(0, N - 1);
   auto r = query(1, N - 1);
   for (auto z : r) {
      l.erase(l.find(z));
   }
   assert(l.size() == N);
   vector<multiset<char>> vl(l.begin(), l.end());
   vl.emplace_back();
   sort(vl.begin(), vl.end(), [&](const multiset<char> &l, const multiset<char> &r) {
      return l.size() < r.size();
   });
   string s = string(N, ' ');
   for (int i = N - 1; i >= 0; --i) {
      for (auto z : vl[i]) {
         vl[i + 1].erase(vl[i + 1].find(z));
      }
      s[i] = *vl[i + 1].begin();
   }
   cout << "! " << s << "\n";
}