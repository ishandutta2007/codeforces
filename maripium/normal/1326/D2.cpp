#include <bits/stdc++.h>

using namespace std;

using State = array<int, 2>;
const int MAXN = 1000100;
const State bases = {233, 1007};
const State mods = {998244353, 1000000007};
using ll = long long;

int addmod(int x, int y, int mod) {
   x += y;
   if (x >= mod) x -= mod;
   return x;
}

int submod(int x, int y, int mod) {
   return addmod(x, mod - y, mod);
}

int mulmod(int x, int y, int mod) {
   return (long long) x * y % mod;
}

State operator + (const State &l, const State &r) {
   return {addmod(l[0], r[0], mods[0]), addmod(l[1], r[1], mods[1])};
}

State operator - (const State &l, const State &r) {
   return {submod(l[0], r[0], mods[0]), submod(l[1], r[1], mods[1])};
}
State operator * (const State &l, const State &r) {
   return {mulmod(l[0], r[0], mods[0]), mulmod(l[1], r[1], mods[1])};
}

State pws[MAXN];

void init() {
   pws[0] = {1, 1};
   for (int i = 1; i < MAXN; ++i) {
      pws[i] = pws[i - 1] * bases;
   }
}
int main() {
   ios_base::sync_with_stdio(false);
   int T;
   cin >> T;
   init();
   while (T--) {
      string S;
      cin >> S;
      int N = S.size();
      int l = 0, r = S.size() - 1;
      while (l < r && S[l] == S[r]) {
         l++;
         r--;
      }
      if (l >= r) {
         cout << S << "\n";
         continue;
      }
      int m = l;
      State forw = {0, 0};
      State backw = {0, 0};
      string lv;
      for (int i = l; i <= r; ++i) {
         State cur = {S[i] - 'a' + 5, S[i] - 'a' + 5};
         forw = forw * bases + cur;
         backw = backw + cur * pws[i - l];
         if (forw == backw) {
            m = i;
         }
      }
      lv = S.substr(0, m + 1) + S.substr(r + 1);
      m = r;
      forw = {0, 0};
      backw = {0, 0};
      for (int i = r; i >= l; --i) {
         State cur = {S[i] - 'a' + 5, S[i] - 'a' + 5};
         forw = forw + cur * pws[r - i];
         backw = backw * bases + cur;
         if (forw == backw) m = i;
      }
      string rv = S.substr(0, l) + S.substr(m);
      if (lv.size() < rv.size()) lv = rv;
      cout << lv << "\n";
   }
}