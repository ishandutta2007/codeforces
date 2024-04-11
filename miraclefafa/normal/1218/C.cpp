#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#ifdef iq
  mt19937 rnd(228);
#else
  mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
 
  
/** Interface */
 
inline int readChar();
template <class T = int> inline T readInt(); 
template <class T> inline void writeInt( T x, char end = 0 );
inline void writeChar( int x ); 
inline void writeWord( const char *s );
 
/** Read */
 
static const int buf_size = 4096;
 
inline int getChar() {
	static char buf[buf_size];
	static int len = 0, pos = 0;
	if (pos == len)
		pos = 0, len = fread(buf, 1, buf_size, stdin);
	if (pos == len)
		return -1;
	return buf[pos++];
}
 
inline int readChar() {
	int c = getChar();
	while (c <= 32)
		c = getChar();
	return c;
}
 
template <class T>
inline T readInt() {
	int s = 1, c = readChar();
	T x = 0;
	if (c == '-')
		s = -1, c = getChar();
	while ('0' <= c && c <= '9')
		x = x * 10 + c - '0', c = getChar();
	return s == 1 ? x : -x;
}
 
/** Write */
 
static int write_pos = 0;
static char write_buf[buf_size];
 
inline void writeChar( int x ) {
	if (write_pos == buf_size)
		fwrite(write_buf, 1, buf_size, stdout), write_pos = 0;
	write_buf[write_pos++] = x;
}
 
template <class T> 
inline void writeInt( T x, char end ) {
	if (x < 0)
		writeChar('-'), x = -x;
 
	char s[24];
	int n = 0;
	while (x || !n)
		s[n++] = '0' + x % 10, x /= 10;
	while (n--)
		writeChar(s[n]);
	if (end)
		writeChar(end);
}
 
inline void writeWord( const char *s ) {
	while (*s)
		writeChar(*s++);
}
 
struct Flusher {
	~Flusher() {
		if (write_pos)
			fwrite(write_buf, 1, write_pos, stdout), write_pos = 0;
	}
} flusher;
 
/** Example */
 
vector <pair <int, int> > f_r[500][500], f_c[500][500];
 
ll dp[500][500];
ll delta_r[500][500];
ll delta_c[500][500];
//ll rdelta[500][500][500];
ll cdelta[500][500];
 
const ll inf = 1e18;
 
const int T = 5e5 + 7;
 
int vis[T];
 
int tt = 0;
 
struct triple {
  int i, j, cost;
};
 
vector <triple> f[500];
vector <triple> g[500];
 
ll fenw[500][500];

void inc(int id, int x, int y) {
  for (; x < 500; x = (x | (x + 1))) {
    fenw[id][x] += y;
  }
}

ll get(int id, int x) {
  ll s =0 ;
  for (; x >= 0; x = (x & (x + 1)) - 1) {
    s += fenw[id][x];
  }
  return s;
}
 
struct orz {
  int j, l, r, cost;
};
 
bool operator < (const orz &a, const orz &b) {
  return a.l < b.l;
}
 
vector <orz> sus;
 
int main() {
#ifdef iq
  freopen("a.in", "r", stdin);
#endif
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  int n = readInt(), m = readInt(), k = readInt();
  //cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x = readInt(), y = readInt(), d = readInt(), t = readInt(), e = readInt();
    vector <pair <int, int> > v;
    v.emplace_back(0, 0);
    v.emplace_back(d, -d);
    v.emplace_back(d, 0);
    v.emplace_back(0, d);
    int ind = i;
    int cnt = 0;
    vector <pair <int, int> > cells;
    for (int i = 0; i < 4; i++) {
      int a = x + v[i].first, b = y + v[i].second;
      if ((a + b - t) % 4 == i && a + b >= t) {
        cnt++;
        cells.push_back({a, b});
      }
    }
    if (cells.empty()) continue;
    if ((int) cells.size() == 1) {
      for (auto c : cells) {
        delta_r[c.first][c.second] += e;
        delta_c[c.first][c.second] += e;
      }
    } else {
      if (cells[0].first != cells[1].first) {
        for (auto c : cells) {
          delta_r[c.first][c.second] += e;
          delta_c[c.first][c.second] += e;
        }
        if (cells[0].second == cells[1].second)
          sus.push_back({cells[0].second, min(cells[0].first, cells[1].first), max(cells[0].first, cells[1].first), -e});
        /*
        for (auto c : cells) {
          f_r[c.first][c.second].push_back({i, e});
        }
        */
      } else {
        for (auto c : cells) {
          delta_r[c.first][c.second] += e;
          delta_c[c.first][c.second] += e;
        }
        g[cells[0].first].push_back({min(cells[0].second, cells[1].second), max(cells[0].second, cells[1].second), -e});
        //cdelta[cells[0].first][min(cells[0].second, cells[1].second)][max(cells[0].second, cells[1].second)] -= e;
      }
    }
  }
  sort(sus.begin(), sus.end());
  /*
   for (int i = 0; i < n; i++) {
     for (int j = m - 1; j >= 0; j--) {
      for (int k = j; k < m; k++) {
        if (j + 1 <= k) {
          cdelta[i][j][k] += cdelta[i][j + 1][k];
          cdelta[i][j][k] += cdelta[i][j][k - 1];
        }
        if (j + 2 <= k) {
          cdelta[i][j][k] -= cdelta[i][j + 1][k - 1];
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = n - 1; j >= 0; j--) {
      for (int k = j; k < n; k++) {
        if (j + 1 <= k) {
          rdelta[i][j][k] += rdelta[i][j + 1][k];
          rdelta[i][j][k] += rdelta[i][j][k - 1];
        }
        if (j + 2 <= k) {
          rdelta[i][j][k] -= rdelta[i][j + 1][k - 1];
        }
      }
    }
  }
  */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = delta_r[0][0];
  for (auto c : sus) {
    inc(c.j, c.r, c.cost);
  }
  int ptr = -1;
  vector <triple> ok;
  for (int i = 0; i < n; i++) {
    while (ptr + 1 < (int) sus.size() && sus[ptr + 1].l < i) {
      ptr++;
      inc(sus[ptr].j, sus[ptr].r, -sus[ptr].cost);
    }
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < m; k++) {
        cdelta[j][k] = 0;
      }
    }
    for (auto t : g[i]) {
      cdelta[t.i][t.j] += t.cost;
    }
    for (int j = m - 1; j >= 0; j--) {
      for (int k = j; k < m; k++) {
        if (j + 1 <= k) {
          cdelta[j][k] += cdelta[j + 1][k];
          cdelta[j][k] += cdelta[j][k - 1];
        }
        if (j +2 <= k) {
          cdelta[j][k] -= cdelta[j + 1][k - 1];
        }
      }
    }
    for (int j = 0; j < m; j++) {
      //cout << i << ' ' << j << ' ' << dp[i][j] << endl;
      tt++;
      ll cost = 0;
      for (int k = j; k < m; k++) {
        if (k > j)
          cost += delta_c[i][k];
        /*
        ll orz = 0;
        for (auto t : g[i]) {
          if (j <= t.i && t.j <= k) {
            orz += t.cost;
          }
        }
        */
        dp[i][k] = min(dp[i][k], dp[i][j] + cost + cdelta[j][k]);
      }
      tt++;
      cost = 0;
      for (int k = i; k < n; k++) {
        if (k > i)
          cost += delta_r[k][j];
        ll orz = get(j, k);
        //cost += rdelta[j][i][k];
        dp[k][j] = min(dp[k][j], dp[i][j] + cost + orz);
      }
    }
  }
  cout << dp[n - 1][m - 1] << '\n';
}