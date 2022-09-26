#include <bits/stdc++.h>

using namespace std;

mt19937 rng(58);

#ifdef kv
vector<int> gen;

void init(int N) {
   cerr << "init\n";
   gen.assign(N, 0);
   for (int i = 0; i < N; ++i) {
      gen[i] = rng() % 3;
   }
}
#endif // kv

vector<bool> query(vector<pair<int, int>> q) {
   if (q.empty()) return vector<bool>();
#ifdef kv
   vector<bool> ans;
   for (auto p : q) ans.emplace_back(gen[p.first] == gen[p.second]);
   return ans;
#else
   cout << "Q " << q.size() << " ";
   for (auto p : q) {
      cout << p.first + 1 << " " << p.second + 1 << " ";
   }
   cout << "\n" << flush;
   string str;
   cin >> str;
   vector<bool> ans;
   for (int i = 0; i < int(str.size()); ++i) ans.emplace_back(str[i] == '1');
   return ans;
#endif // kv
}

void answer(vector<int> ans) {
   int N = ans.size();
#ifdef kv
   vector<int> l(3, -1), r(3, -1);
   bool good = true;
   for (int i = 0; i < N; ++i) {
      if (l[gen[i]] == -1 && r[ans[i]] == -1) {
         l[gen[i]] = ans[i];
         r[ans[i]] = gen[i];
      }
      good &= (l[gen[i]] == ans[i]);
      good &= (r[ans[i]] == gen[i]);
   }
   if (!good) {
      cerr << "WRONG\n";
      for (int v : gen) cerr << v << " "; cerr << "\n";
      for (int v : ans) cerr << v << " "; cerr << "\n";
   }
   cerr << "CORRECT " << N << " ";
   for (int v : gen) cout << v << " "; cout << "\n";
#else
   vector<int> ps[3];
   for (int i = 0; i < N; ++i) ps[ans[i]].emplace_back(i);
   cout << "A " << ps[0].size() << " " << ps[1].size() << " " << ps[2].size() << "\n";
   for (int z = 0; z < 3; ++z) {
      for (int p : ps[z]) cout << p + 1 << " ";
      cout << "\n";
   }
   cout << flush;
#endif // kv
}

int main() {
   ios_base::sync_with_stdio(false); // cin.tie(nullptr);
   int T;
   cin >> T;
   while (T--) {
      int N;
      cin >> N;
   #ifdef kv
      init(N);
   #endif // kv
      cerr << "start phase 1\n";
      vector<bool> nxt(N - 1);
      for (int z = 0; z < 2; ++z) {
         vector<pair<int, int>> q;
         for (int i = z; i + 1 < N; i += 2) {
            q.emplace_back(i, i + 1);
         }         auto ans = query(q);
         for (int i = z, j = 0; i + 1 < N; i += 2) {
            nxt[i] = ans[j++];
         }
      }
      vector<pair<int, int>> ranges;
      int l = 0;
      while (l < N) {
         int r = l;
         while (r < N && nxt[r]) r++;
         ranges.emplace_back(l, r);
         l = r + 1;
      }
      int M = ranges.size();
      vector<bool> prv2(M);
      cerr << "start phase 2\n";
      for (int z = 0; z < 2; ++z) {
         vector<pair<int, int>> q;
         for (int i = 2; i < M; ++i) {
            if ((i / 2) % 2 == z) q.emplace_back(ranges[i - 2].first, ranges[i].first);
         }
         auto ans = query(q);
         for (int i = 2, j = 0; i < M; ++i) {
            if ((i / 2) % 2 == z) prv2[i] = ans[j++];
         }
      }
      vector<int> ans(M);
      for (int i = 0; i < M; ++i) {
         if (i < 2) ans[i] = i;
         else if (prv2[i]) ans[i] = ans[i - 2];
         else ans[i] = 3 - ans[i - 1] - ans[i - 2];
      }
      vector<int> realAns(N);
      for (int i = 0; i < M; ++i) {
         for (int j = ranges[i].first; j <= ranges[i].second; ++j) realAns[j] = ans[i];
      }
      answer(realAns);
   }
}