#include <bits/stdc++.h>

using namespace std;

template <int MOD_> struct modnum {
   static constexpr int MOD = MOD_;
   static_assert(MOD_ > 0, "MOD must be positive");
 
private:
   using ll = long long;
 
   int v;
 
   static int minv(int a, int m) {
      a %= m;
      assert(a);
      return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
   }
 
public:
 
   modnum() : v(0) {}
   modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
   explicit operator int() const { return v; }
   friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
   friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
   friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
   friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
   modnum inv() const {
      modnum res;
      res.v = minv(v, MOD);
      return res;
   }
   friend modnum inv(const modnum& m) { return m.inv(); }
   modnum neg() const {
      modnum res;
      res.v = v ? MOD-v : 0;
      return res;
   }
   friend modnum neg(const modnum& m) { return m.neg(); }
 
   modnum operator- () const {
      return neg();
   }
   modnum operator+ () const {
      return modnum(*this);
   }
 
   modnum& operator ++ () {
      v ++;
      if (v == MOD) v = 0;
      return *this;
   }
   modnum& operator -- () {
      if (v == 0) v = MOD;
      v --;
      return *this;
   }
   modnum& operator += (const modnum& o) {
      v -= MOD-o.v;
      v = (v < 0) ? v + MOD : v;
      return *this;
   }
   modnum& operator -= (const modnum& o) {
      v -= o.v;
      v = (v < 0) ? v + MOD : v;
      return *this;
   }
   modnum& operator *= (const modnum& o) {
      v = int(ll(v) * ll(o.v) % MOD);
      return *this;
   }
   modnum& operator /= (const modnum& o) {
      return *this *= o.inv();
   }
 
   friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
   friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
   friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
   friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
   friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
   friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
 
using num = modnum<998244353>;

int main() {
   ios_base::sync_with_stdio(false); cin.tie(nullptr);

   vector<num> p2{1};

   auto get_pow = [&](int v) {
      while (p2.size() <= v) p2.push_back(p2.back() * 2);
      return p2[v];
   };

   int N, M, Q; cin >> N >> M >> Q;
   vector<tuple<int, int, int>> queries;
   for (int q = 0; q < Q; ++q) {
      int x, y, t; cin >> x >> y >> t;
      queries.emplace_back(x - 1, y - 1, t);
   }

   vector<num> ans(Q);
   { // row
      map<int, map<int, int>> mp;
      vector<multiset<int>> st(M);
      int free = M;
      int bad = 0;
      for (int q = 0; q < Q; ++q) {
         auto [x, y, t] = queries[q];
         {
            free -= bool(st[y].empty());
            bad -= bool(!st[y].empty() && (*st[y].begin() < *(--st[y].end())));
         }
         if (mp[x].count(y)) {
            int v = mp[x][y] ^ (x & 1);
            st[y].erase(st[y].find(v));
            mp[x].erase(y);
         }
         if (t != -1) {
            mp[x][y] = t;
            int v = mp[x][y] ^ (x & 1);
            st[y].insert(v) ;
         }
         {
            free += bool(st[y].empty());
            bad += bool(!st[y].empty() && (*st[y].begin() < *(--st[y].end())));
         }
         num ways;
         if (bad) ways = 0;
         else ways = get_pow(free);
         ans[q] += ways;
      }  
   }

   { // column
      map<int, map<int, int>> mp;
      vector<multiset<int>> st(N);
      int free = N;
      int bad = 0;
      for (int q = 0; q < Q; ++q) {
         auto [x, y, t] = queries[q];
         {
            free -= bool(st[x].empty());
            bad -= bool(!st[x].empty() && (*st[x].begin() < *(--st[x].end())));
         }
         if (mp[x].count(y)) {
            int v = mp[x][y] ^ (y & 1);
            st[x].erase(st[x].find(v));
            mp[x].erase(y);
         }
         if (t != -1) {
            mp[x][y] = t;
            int v = mp[x][y] ^ (y & 1);
            st[x].insert(v); 
         }
         {
            free += bool(st[x].empty());
            bad += bool(!st[x].empty() && (*st[x].begin() < *(--st[x].end())));
         }
         num ways;
         if (bad) ways = 0;
         else ways = get_pow(free);
         ans[q] += ways;
      }  
   }

   { // chess
      multiset<int> st;
      map<int, map<int, int>> mp;
      for (int q = 0; q < Q; ++q) {
         auto [x, y, t] = queries[q];
         if (mp[x].count(y)) {
            int v = mp[x][y] ^ (x & 1) ^ (y & 1);
            st.erase(st.find(v));
            mp[x].erase(y);
         }
         if (t != -1) {
            mp[x][y] = t;
            int v = mp[x][y] ^ (x & 1) ^ (y & 1);
            st.insert(v);
         }
         num ways;
         if (st.empty()) ways = 2;
         else if (*st.begin() == *(--st.end())) ways = 1;
         else ways = 0;
         ans[q] -= ways;
      }
   }
   for (int q = 0; q < Q; ++q) {
      cout << ans[q] << '\n';
   }
}