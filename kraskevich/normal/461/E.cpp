#include <bits/stdc++.h>

using namespace std;

const int INF32 = (int)1e9;
const long long INF64 = (long long)1e18;

struct Automaton
{
    vector<int> len;
    vector<int> suf;
    vector<map<char, int> > go;
    int p;
    int sz;

    void clear()
    {
        go.clear();
        len.clear();
        suf.clear();
    }

    void build(string s)
    {
        int n = s.length() * 2 + 1;
        len.assign(n, 0);
        suf.assign(n, -1);
        go.resize(n);
        for (int i = 0; i < n; i++)
            go[i].clear();
        p = 0;
        sz = 1;
        for (int i = 0; i < s.length(); i++)
            add(s[i]);
    }

    void add(char c)
    {
        int v = sz++;
        len[v] = len[p] + 1;
        for (; p >= 0 && !go[p].count(c); p = suf[p])
            go[p][c] = v;
        if (p < 0)
        {
            suf[v] = 0;
        }
        else
        {
            int to = go[p][c];
            if (len[to] == len[p] + 1)
            {
                suf[v] = to;
            }
            else
            {
                int cl = sz++;
                go[cl] = go[to];
                len[cl] = len[p] + 1;
                suf[cl] = suf[to];
                for (; p >= 0 && go[p][c] == to; p = suf[p])
                    go[p][c] = cl;
                suf[to] = suf[v] = cl;
            }
        }
        p = v;
    }
};

Automaton a;

struct Matrix {
  vector<vector<long long>> f;
  
  Matrix() {
    f.assign(4, vector<long long>(4, INF64));
  }
  
  Matrix merge(const Matrix& rhs) const {
    Matrix res;
    for (int l = 0; l < 4; l++)
      for (int mid = 0; mid < 4; mid++)
        for (int r = 0; r < 4; r++)
          res.f[l][r] = min(res.f[l][r], f[l][mid] + rhs.f[mid][r]);
    return res;
  }
  
  long long get_min() {
    long long res = INF64;
    for (auto row : f)
      res = min(res, *min_element(row.begin(), row.end()));
    return res;
  }
};

Matrix dp0;

Matrix calc(long long n) {
  if (n == 0) {
    Matrix res;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        res.f[i][j] = 0;
    return res;
  }
  if (n == 1)
    return dp0;
  Matrix sub = calc(n / 2);
  Matrix res = sub.merge(sub);
  if (n & 1)  
    res = res.merge(dp0);
  return res;
}

void update(char st) {
  vector<int> dist(a.sz, INF32);
  int v = a.go[0][st];
  dist[v] = 0;
  queue<int> q;
  q.push(v);
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (char to = 'A'; to <= 'D'; to++)
      if (a.go[v].find(to) == a.go[v].end()) {
        dp0.f[st - 'A'][to - 'A'] = min(dp0.f[st - 'A'][to - 'A'], dist[v] + 1ll);
      } else if (dist[a.go[v][to]] > dist[v] + 1) {
        dist[a.go[v][to]] = dist[v] + 1;
        q.push(a.go[v][to]);
      }
  }
}
          


int main() {
  ios_base::sync_with_stdio(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  a.build(s);
  for (char c = 'A'; c <= 'D'; c++)
    update(c);
  long long low = 0;
  long long high = n;
  /*for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++)
      cerr << dp0.f[i][j] << " ";
    cerr << endl;
  }*/
  while (low < high) {
    long long mid = (low + high + 1) / 2;
    Matrix cur = calc(mid);
    if (cur.get_min() <= n - 1)
      low = mid;
    else
      high = mid - 1;
  }
  cout << min(n * 1ll, low + 1) << endl;
  
  return 0;
}