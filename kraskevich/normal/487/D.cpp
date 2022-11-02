#include <bits/stdc++.h>

using namespace std;

int n, m, q;

struct Node {
  vector<pair<int, int>> go;
  int low;
  int high;
  
  Node(int L, int R, string s) {
    low = L;
    high = R;
    go.resize(m);
    for (int i = 0; i < m; i++) {
      int cur = i;
      bool done = false;
      for (int rep = 0; rep < 20; rep++) {
    if (cur < 0 || cur >= m) {
      done = true;
      go[i] = make_pair(L, cur);
      break;
    }
    if (s[cur] == '^') {
      done = true;
      go[i] = make_pair(L - 1, cur);
      break;
    }
    if (s[cur] == '<')
      cur--;
    else
      cur++;
      }
      if (!done)
    go[i] = make_pair(L, i);
    }
    /*cerr << s << endl;
    cerr << low << " " << high << endl;
    for (int i = 0; i < m; i++)
      cerr << go[i].first << " " << go[i].second << endl;
    cerr << endl;*/
  }
  
  Node(int L, int R) {
    low = L;
    high = R;
    go.resize(m);
  }
  
  Node() {}
};

Node unite(Node L, Node R) {
  if (L.low == -1)
    return R;
  if (R.low == -1)
    return L;
  Node res(L.low, R.high);
  for (int i = 0; i < m; i++) 
    if (R.go[i].first >= R.low)
      res.go[i] = R.go[i];
    else {
      //cerr << R.go[i].second << endl;
      res.go[i] = L.go[R.go[i].second];
    }
  /*cerr << "unite\n";
  for (int i = 0;  i < m; i++)
    cerr << L.go[i].first << " " << L.go[i].second << endl;
  cerr << "f " << L.low << " " << L.high << endl;
  for (int i = 0;  i < m; i++)
    cerr << R.go[i].first << " " << R.go[i].second << endl;
  cerr << "f " << R.low << " " << R.high << endl;
  for (int i = 0;  i < m; i++)
    cerr << res.go[i].first << " " << res.go[i].second << endl;
  cerr << "f " << res.low << " " << res.high << endl;*/
  return res;
}
    
const int N = (int)1e6;

string s[N];
Node tree[N];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = Node(l, l, s[l]);
    return;
  }
  int m = (l + r) / 2;
  build(2 * i + 1, l, m);
  build(2 * i + 2, m + 1, r);
  tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

void upd(int i, int l, int r, int pos) {
  if (l == r) {
    tree[i] = Node(l, l, s[l]);
    return;
  }
  int m = (l + r) / 2;
  if (pos <= m)
    upd(2 * i + 1, l, m, pos);
  else
    upd(2 * i + 2, m + 1, r, pos);
  tree[i] = unite(tree[2 * i + 1], tree[2 * i + 2]);
}

Node calc(int i, int tl, int tr, int l, int r) {
  if (l == tl && r == tr)
    return tree[i];
  int m = (tl + tr) / 2;
  Node nl(-1, -1);
  Node nr(-1, -1);
  if (l <= m)
    nl = calc(2 * i + 1, tl, m, l, min(m, r));
  if (r > m)
    nr = calc(2 * i + 2, m + 1, tr, max(m + 1, l), r);
  return unite(nl, nr);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++)
    cin >> s[i];
  build(0, 0, n - 1);
  //cerr << tree[0].go[0].first << " " << tree[0].go[0].second << endl;
  for (int i = 0; i < q; i++) {
    string t;
    cin >> t;
    if (t == "C") {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      char c;
      cin >> c;
      s[x][y] = c;
      upd(0, 0, n - 1, x);
    } else {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      Node res = calc(0, 0, n - 1, 0, x);
      int ri = res.go[y].first;
      int rj = res.go[y].second;
      //cerr << ri << " " << rj << endl;
      if (ri == -1 || rj == -1 || rj == m) 
    cout << ri + 1 << " " << rj + 1 << "\n";
      else
    cout << "-1 -1\n";
    }
  }
  return 0;
}