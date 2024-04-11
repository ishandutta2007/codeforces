#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100100;

int N;
int sa[MAXN], ea[MAXN];
int sb[MAXN], eb[MAXN];

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
   }
   auto go = [&]() {
      vector<tuple<int, int, int>> events;
      for (int i = 0; i < N; ++i) {
         events.emplace_back(sa[i], +1, i);
         events.emplace_back(ea[i] + 1, -1, i);
      }
      multiset<int> ss;
      multiset<int> es;
      sort(events.begin(), events.end());
      for (auto z : events) {
         int x, id, t;
         tie(x, t, id) = z;
         if (t == +1) {
            if (ss.size() && *(--ss.end()) > eb[id]) {
               cout << "NO\n";
               exit(0);
            } else if (es.size() && *es.begin() < sb[id]) {
               cout << "NO\n";
               exit(0);
            }
            ss.emplace(sb[id]);
            es.emplace(eb[id]);
         } else {
            ss.erase(ss.find(sb[id]));
            es.erase(es.find(eb[id]));
         }
      }
   };
   go();
   for (int i = 0; i < N; ++i) {
      swap(sa[i], sb[i]);
      swap(ea[i], eb[i]);
   }
   go();
   cout << "YES\n";
   return 0;
}