#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200200;
using ll = long long;
using ld = double;

int N, K;
pair<ll, ll> ps[MAXN];

vector<pair<ll, ll>> ans;

void solve(pair<ll, ll> center) {
   int ptr = N - 1;
   int add = 0;
   for (int i = 0; i < N; ++i) {
      pair<ll, ll> p = ps[i];
      pair<ll, ll> q(center.first * 2 - p.first, center.second * 2 - p.second);
      while (ptr >= 0 && ps[ptr] > q) {
         --ptr;
      }
      if (!(ptr >= 0 && ps[ptr] == q)) {
         ++add;
      }
   }
   if (add <= K) {
      ans.emplace_back(center);
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin >> N >> K;
   if (N <= K) {
      cout << "-1\n";
      return 0;
   }
   for (int i = 0; i < N; ++i) {
      cin >> ps[i].first >> ps[i].second;
      ps[i].first *= 2;
      ps[i].second *= 2;
   }
   sort(ps, ps + N);
   for (int i = 0; i <= K; ++i) {
      for (int j = 0; i + j <= K; ++j) {
         solve(make_pair((ps[i].first + ps[N - 1 - j].first) / 2, (ps[i].second + ps[N - 1 - j].second) / 2));
      }
   }
   sort(ans.begin(), ans.end());
   ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
   cout << int(ans.size()) << "\n";
   for (auto p : ans) {
      cout << fixed << setprecision(6) << ld(p.first) * 0.5 << " " << ld(p.second) * 0.5 << "\n";
   }
;}