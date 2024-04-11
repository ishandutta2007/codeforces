// ac_zdj in my hands becomes wa_zdj
// hkoi training moment

#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define int long long
const int mxN = 2e5 + 5, alpha = 26;
int n, tot, dep[mxN], link[mxN], nxt[alpha][mxN], trie[alpha][mxN], lazy[mxN], wao[mxN], cnt[mxN];
std::string s[mxN];
int ins(int x) {
  cnt[tot] = 0;
  dep[tot] = (!tot ? tot : dep[x] + 1);
  link[tot] = lazy[tot] = wao[tot] = -1;
  for (int i = 0; i < alpha; i++) {
    nxt[i][tot] = 0;
    trie[i][tot] = -1;
  }
  return tot++;
}
void build() {
  tot = 0;
  ins(0);
  for (int i = 0; i < n; i++) {
    int ptr = 0;
    for (int j = 0; j < s[i].length(); j++) {
      int x = s[i][j] - 'a';
      if (trie[x][ptr] == -1) trie[x][ptr] = nxt[x][ptr] = ins(ptr);
      ptr = trie[x][ptr];
    }
    lazy[ptr] = i;
    cnt[ptr]++;
  }
  std::queue<int> bfs;
  link[0] = 0;
  bfs.push(0);
  while (bfs.size()) {
    auto x = bfs.front();
    bfs.pop();
    for (int i = 0; i < alpha; i++) {
      if (trie[i][x] != -1){
        link[trie[i][x]] = (!x ? x : nxt[i][link[x]]);
        wao[trie[i][x]] = (lazy[link[trie[i][x]]] != -1 ? link[trie[i][x]] : wao[link[trie[i][x]]]);
        cnt[trie[i][x]] += cnt[link[trie[i][x]]];
        for (int j = 0; j < alpha; j++) {
          if(trie[j][trie[i][x]] == -1) nxt[j][trie[i][x]] = nxt[j][link[trie[i][x]]];
        }
        bfs.push(trie[i][x]);
      }
    }
  }
}
int32_t main() {
  std::string wa;
  std::cin >> wa >> n;
  for (int i = 0; i < n; i++) std::cin >> s[i];
  build();
  int x = wa.length(), z = 0, oo[x], pp[x];
  for (int i = 0; i < x; i++) {
    z = nxt[wa[i] - 'a'][z];
    pp[i] = cnt[z];
  }
  std::reverse(wa.begin(), wa.end());
  for (int i = 0; i < n; i++) std::reverse(s[i].begin(), s[i].end());
  build();
  z = 0;
  for (int i = 0; i < x; i++) {
    z = nxt[wa[i] - 'a'][z];
    oo[i] = cnt[z];
  }
  std::reverse(oo, oo + x);
  int ans = 0;
  for (int i = 0; i < x - 1; i++) ans += oo[i + 1] * pp[i];
  std::cout << ans << "\n";
}