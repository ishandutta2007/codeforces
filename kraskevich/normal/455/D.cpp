#include <bits/stdc++.h>

using namespace std;


const int B = 400;
const int N = 300 * B;

int a[N];

struct Block {
  deque<int> vals;
  vector<int> cnt;
  int ll;
  int rr;

  Block() {}

  Block(int l, int r) {
    ll = l;
    rr = r;
    cnt.assign(N + 1, 0);
    for (int i = l; i <= r; i++) {
      vals.push_back(a[i]);
      cnt[a[i]]++;
    }
  }

  int get_cnt(int l, int r, int x) {
    if (l <= ll && rr <= r)
      return cnt[x];
    int res = 0;
    for (int i = max(l, ll); i <= min(r, rr); i++)
      if (vals[i - ll] == x)
        res++;
    return res;
  }

  int move_all(int nval) {
    int res = vals.back();
    vals.pop_back();
    vals.push_front(nval);
    cnt[res]--;
    cnt[nval]++;
    return res;
  }

  int move_suf(int st, int nval) {
    int res = vals.back();
    for (int i = rr; i >= st + 1; i--)
      vals[i - ll] = vals[i - 1 - ll];
    vals[st - ll] = nval;
    cnt[nval]++;
    cnt[res]--;
    return res;
  }

  void move_pref(int fin, int nval) {
    cnt[nval]++;
    cnt[vals[fin - ll]]--;
    for (int i = fin; i >= ll + 1; i--)
      vals[i - ll] = vals[i - 1 - ll];
    vals[0] = nval;
  }

  void move_segm(int l, int r) {
    int t = vals[r - ll];
    for (int i = r; i >= l + 1; i--)
      vals[i - ll] = vals[i - 1 - ll];
    vals[l - ll] = t;
  }
};

Block b[N / B];

int get_cnt(int l, int r, int x) {
  int res = 0;
  for (int bl = l / B; bl <= r / B; bl++)
    res += b[bl].get_cnt(l, r, x);
  return res;
}

void rot(int l, int r) {
  int f = l / B;
  int e = r / B;
  if (f == e) {
    b[f].move_segm(l, r);
    return;
  }
  int last = b[e].vals[r - b[e].ll];
  last = b[f].move_suf(l, last);
  for (int i = f + 1; i < e; i++)
    last = b[i].move_all(last);
  b[e].move_pref(r, last);
}

/*void print() {
  for (int i = 0; i < N / B; i++)
    for (int x : b[i].vals)
      cout << x << " ";
  cout << endl;
}*/

int n;

int apply(int x, int lans) {
  x = x + lans - 1;
  x %= n;
  return x + 1;
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int l = 0, r = B - 1, i = 0; l < N; l += B, r += B, i++)
    b[i] = Block(l, r);
  int q;
  cin >> q;
  int lans = 0;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int l, r;
      cin >> l >> r;
      l = apply(l, lans) - 1;
      r = apply(r, lans) - 1;
      if (l > r)
        swap(l, r);
      rot(l, r);
    } else {
      int l, r, k;
      cin >> l >> r >> k;
      l = apply(l, lans) - 1;
      r = apply(r, lans) - 1;
      if (l > r)
        swap(l, r);
      k = apply(k, lans);
      lans = get_cnt(l, r, k);
      cout << lans << "\n";
    }
    //print();
  }

  return 0;
}