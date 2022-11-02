#include <bits/stdc++.h>

using namespace std;

const int INF = (int)1e9 + 10;
const int N = (int)1e5 + 20;

vector<int> cand[N];
vector<int> at[N];

int cnt[4 * N];
int sum[4 * N];

void upd(int i, int pos, int tl, int tr, int delta) {
  if (tl == pos && tr == pos) {
    cnt[i] += delta;
    sum[i] = cnt[i] * pos;
    return;
  }
  int m = (tl + tr)  / 2;
  if (pos <= m)
    upd(2 * i + 1, pos, tl, m, delta);
  else
    upd(2 * i + 2, pos, m + 1, tr, delta);
  cnt[i] = cnt[2 * i + 1] + cnt[2 * i + 2];
  sum[i] = sum[2 * i + 1] + sum[2 * i + 2];
}

int get_min(int i, int tl, int tr, int k) {
  if (tl == tr)
    return k * tl;
  int m = (tl + tr) / 2;
  int sl = 0;
  int sr = 0;
  int cl = cnt[2 * i + 1];
  if (cl >= k)
    sl = get_min(2 * i + 1, tl, m, k);
  else {
    sl = sum[2 * i + 1];
    k -= cl;
    sr = get_min(2 * i + 2, m + 1, tr, k);
  }
  return sl + sr;
}

int main() {
  //freopen("input.txt", "r", stdin);
  ios_base::sync_with_stdio(0);

  int n;
  cin >> n;
  int have = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (!a) {
      have++;
      continue;
    }
    cand[a].push_back(b);
  }
  for (int i = 1; i < N; i++) {
    sort(cand[i].rbegin(), cand[i].rend());
    for (int j = 1; j <= cand[i].size(); j++) {
      at[j].push_back(cand[i][j - 1]);
      upd(0, cand[i][j - 1], 0, N - 1, 1);
    }
  }
  /* for (int i = 1; i < 3; i++) {
    for (int x : cand[i])
      cerr << x << " ";
    cerr << endl;
  }
  cerr << "===\n";
  for (int i = 1; i <= n; i++) {
    for (int x : at[i])
      cerr << x << " ";
    cerr << endl;
  }
  cerr << "===\n";*/
  int res = INF;
  int must = 0;
  int add = 0;
  for (int score = n; score >= 1; score--) {
    for (int x : at[score]) {
      must += x;
      add++;
      upd(0, x, 0, N - 1, -1);
    }
    int to_go = score - have - add;
    //cerr << must << " " << add << " " << to_go << endl;
    if (to_go < 0)
      continue;
    res = min(res, must + get_min(0, 0, N - 1, to_go));
  }
  cout << res;

  return 0;
}