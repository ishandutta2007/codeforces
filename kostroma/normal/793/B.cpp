#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

int main() {
#ifdef AIM
    freopen("/home/alexandero/ClionProjects/ACM/input.txt", "r", stdin);
    //freopen("/home/alexandero/ClionProjects/ACM/output.txt", "w", stdout);
    //freopen("out.txt", "w", stdout);
#else
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
    cout.sync_with_stdio(0);
    cin.tie(0);
    precalc();
    cout.precision(10);
    cout << fixed;
    //cin >> t;
    int testNum = 1;
    while (t--) {
        //cerr << testNum << endl;
        //cout << "Case #" << testNum++ << ": ";
        solve(true);
        ++testNumber;
        //++timer;
    }
#ifdef AIM1
    while (true) {
        solve(false);
    }
#endif

#ifdef AIM
    cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
    if (!w)
        return 1 % mod;
    if (w & 1)
        return q * 1LL * binpow(q, w - 1, mod) % mod;
    return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
    while (w) {
        q %= w;
        swap(q, w);
    }
    return q;
}
template<typename T>
T lcm(T q, T w) {
    return q / gcd(q, w) * w;
}

void precalc() {

}

//#define int li
//const int mod = 1000000007;

vector<string> s;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int have[1010][1010][4][3];

struct State {
  pair<int, int> cur;
  int dir, turns;

};

void solve(bool read) {
  int n, m;
  cin >> n >> m;
  s.resize(n);
  pair<int, int> start, finish;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'S') {
        start = {i, j};
      }
      if (s[i][j] == 'T') {
        finish = {i, j};
      }
    }
  }

  queue<State> q;
  for (int dir = 0; dir < 4; ++dir) {
    have[start.first][start.second][dir][0] = 1;
    q.push({start, dir, 0});
  }

  while (!q.empty()) {
    auto cur_state = q.front();
    q.pop();
    for (int dir = 0; dir < 4; ++dir) {
      int x = cur_state.cur.first + dx[dir], y = cur_state.cur.second + dy[dir];
      if (x < 0 || y < 0 || x >= n || y >= m || s[x][y] == '*') {
        continue;
      }
      State nex = {{x, y}, dir, cur_state.turns + (cur_state.dir != dir)};
      if (nex.turns <= 2 && !have[x][y][dir][nex.turns]) {
        have[x][y][dir][nex.turns] = 1;
        q.push(nex);
      }
    }
  }

  for (int dir = 0; dir < 4; ++dir) {
    for (int turns = 0; turns <= 2; ++turns) {
      if (have[finish.first][finish.second][dir][turns]) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";


}