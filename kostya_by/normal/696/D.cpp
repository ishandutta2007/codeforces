#include <bits/stdc++.h>

using namespace std;

const int MAX_K = 50;
const int MAX_N = 202;
const int MAX_H = 202;

const long long INF = (long long) 1e18;

struct Node {
  int go[26];
  int link;
  int prev;
  int c;

  int f;
  int g;

  Node() {
    memset(go, -1, sizeof(go));
    link = -1;
    prev = -1;
    c = -1;

    f = 0;
    g = -1;
  }
};

int h = 1;
Node trie[MAX_H];
int a[MAX_N];

int go(int, int);

int get_link(int v) {
  if (trie[v].link != -1) {
    return trie[v].link;
  }

  if (v == 0 || trie[v].prev == 0) {
    return trie[v].link = 0;
  }

  return trie[v].link = go(get_link(trie[v].prev), trie[v].c);
}

int go(int v, int c) {
  if (trie[v].go[c] != -1) {
    return trie[v].go[c];
  }

  if (v == 0) {
    return trie[v].go[c] = 0;
  }

  return trie[v].go[c] = go(get_link(v), c);
}

int gun(int v) {
  if (trie[v].g != -1) {
    return trie[v].g;
  }

  if (v == 0) {
    return trie[v].g = 0;
  }

  return trie[v].g = gun(get_link(v)) + trie[v].f;
}

void fill(int h, long long f[][MAX_H], long long value) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < h; j++) {
      f[i][j] = value;
    }
  }
}

void move(int h, long long f1[][MAX_H], long long f2[][MAX_H]) {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < h; j++) {
      f2[i][j] = f1[i][j];
    }
  }
}

void combine(int h, long long f1[][MAX_H], long long f2[][MAX_H], long long f3[][MAX_H]) {
  for (int u = 0; u < h; u++) {
    for (int v = 0; v < h; v++) {
      long long value = -INF;

      for (int w = 0; w < h; w++) {
        if (f1[u][w] == -INF || f2[w][v] == -INF) {
          continue;
        }

        value = max(value, f1[u][w] + f2[w][v]);
      }

      f3[u][v] = value;
    }
  }
}

long long f[2][MAX_H][MAX_H];
long long g[2][MAX_H][MAX_H];

void solve() {
  int n;
  long long l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    string s; cin >> s;

    int v = 0;
    for (char c : s) {
      if (trie[v].go[c - 'a'] == -1) {
        trie[v].go[c - 'a'] = h;

        trie[h].prev = v;
        trie[h].c = c - 'a';

        h += 1;
      }

      v = trie[v].go[c - 'a'];
    }

    trie[v].f += a[i];
  }

  fill(h, f[0], -INF);
  fill(h, f[1], -INF);
  fill(h, g[0], -INF);
  fill(h, g[1], -INF);

  g[0][0][0] = 0;
  for (int u = 0; u < h; u++) {
    for (int c = 0; c < 26; c++) {
      int v = go(u, c);

      long long value = gun(v);
      f[0][u][v] = max(f[0][u][v], value);
    }
  }

  for (int k = 0; k < MAX_K; k++) {
    long long bit = 1ll;
    bit <<= (long long) k;

    if (l & bit) {
      combine(h, g[0], f[0], g[1]);
      move(h, g[1], g[0]);
    }

    combine(h, f[0], f[0], f[1]);
    move(h, f[1], f[0]);
  }

  long long answer = -INF;
  for (int u = 0; u < h; u++) {
    answer = max(answer, g[0][0][u]);
  }

  cout << answer << "\n";
}

int main() {
  solve();

  return 0;
}