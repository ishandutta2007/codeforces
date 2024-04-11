#pragma GCC optimize "tree-vectorize"
#pragma GCC target "movbe,mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,avx,avx2,aes,pclmul,fsgsbase,rdrnd,fma,bmi,bmi2,f16c,rdseed,clflushopt,xsavec,xsaves,adx,prfchw,lzcnt,abm"
#include <iostream>

using namespace std;

bool online_judge =
                    #ifdef ONLINE_JUDGE
                    1;
                    #else
                    0;
                    #endif
struct { using X = int; template <typename T = X> T operator()() { T t; cin >> t; return t; } operator X() { return operator()(); } template <typename T> operator T() { return operator()<T>(); } } $;
template <typename T, typename S> bool mini(T& a, const S& b) { return b < a? a = b, 1: 0; }

struct Node {
  int a, c, ab, bc, ans;

  void combine(int i, int ll);
};

constexpr int S = 1 << 17;
Node t[2 * S];

void Node::combine(int i, int ll) {
  auto& l = t[2 * i], & r = t[2 * i + 1];
  a = l.a + r.a;
  c = l.c + r.c;
  int lb = ll - l.a - l.c;
  ab = max(l.ab, r.ab + lb - l.a);
  bc = max(l.bc, r.bc + l.c - lb);
  ans = min(lb - l.ab + r.c - r.bc, min(l.ans + r.c, r.ans + l.a));
}

void modify(char val, int p) {
  int ll = 1, i = p + S;
  t[i] = {val == 'a', val == 'c', val == 'b', val == 'c'};
  while (i /= 2) {
    t[i].combine(i, ll);
    ll *= 2;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(!online_judge);
  ios::sync_with_stdio(0);
  int n = $, q = $;
  for (int i = 0; i < n; ++i) {
    char c = $;
    t[i + S] = {c == 'a', c == 'c', c == 'b', c == 'c'};
  }
  for (int i = S; --i; ) {
    t[i].combine(i, 1 << __builtin_clz(i) - 15);
  }
  while (q--) {
    modify($, $ - 1);
    cout << t[1].ans << '\n';
  }
}