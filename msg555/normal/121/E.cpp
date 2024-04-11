#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

struct node {
  int laz;
  int minv;
  int mini;
  int minc;

  node() : laz(0), minv(1000000000), mini(-2), minc(0) {
  }

  node& operator|=(const node& x) {
    if(minv == x.minv) minc += x.minc;
    else minc = minv < x.minv ? minc : x.minc;
    mini = minv < x.minv ? mini : x.mini;
    minv = min(minv, x.minv);
    return *this;
  }
};

int B[1 << 17];
node AR[2 << 17];

void sub(int x, int lo, int hi, int A, int B, int v) {
  if(hi <= A || B <= lo) return;

  if(lo <= A && B <= hi) {
    if(AR[x].minv == 1000000000) { /* init */
      AR[x].minv = 0;
      AR[x].minc = 1;
      AR[x].mini = A;
    }
    AR[x].laz += v;
    AR[x].minv -= v;
  } else {
    int x1 = 2 * x;
    int x2 = x1 + 1;
    int m = (A + B) / 2;
    int lz = AR[x].laz;
    if(lz) {
      AR[x1].laz += lz;
      AR[x2].laz += lz;
      AR[x1].minv -= lz;
      AR[x2].minv -= lz;
    }
    sub(x1, lo, hi, A, m, v);
    sub(x2, lo, hi, m, B, v);

    AR[x] = AR[x1];
    AR[x] |= AR[x2];
    AR[x].laz = 0;
  }
}

node query(int x, int lo, int hi, int A, int B) {
  if(hi <= A || B <= lo) return node();

  if(lo <= A && B <= hi) {
    return AR[x];
  } else {
    int x1 = 2 * x;
    int x2 = x1 + 1;
    int m = (A + B) / 2;
    int lz = AR[x].laz;
    if(lz) {
      AR[x1].laz += lz;
      AR[x2].laz += lz;
      AR[x1].minv -= lz;
      AR[x2].minv -= lz;
      AR[x].laz = 0;
    }
    node result = query(x1, lo, hi, A, m);
    result |= query(x2, lo, hi, m, B);
    return result;
  }
}

void qsub(int lo, int hi, int v) {
  sub(1, lo, hi, 0, 1 << 17, v);
}

node qquery(int lo, int hi) {
  return query(1, lo, hi, 0, 1 << 17);
}

int main() {
  vector<long long> v;
  for(int i = 1; i <= 5; i++) {
    for(int j = 0; j < 1 << i; j++) {
      int x = 0;
      for(int k = 0; k < i; k++) {
        x *= 10;
        x += (j & 1 << k) ? 7 : 4;
      }
      v.push_back(x);
    }
  }
  sort(v.begin(), v.end());

  int N, M;
  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> B[i];
    int pos = lower_bound(v.begin(), v.end(), B[i]) - v.begin();
    qsub(i, i + 1, B[i] - v[pos]);
    B[i] = pos;
  }

  for(int i = 0; i < M; i++) {
    string cmd; int lo, hi;
    cin >> cmd >> lo >> hi; lo--;

    node res = qquery(lo, hi);
    while(res.minv < 0) {
      int pos = B[res.mini];
      int delta = v[pos + 1] - v[pos];
      B[res.mini]++;
      qsub(res.mini, res.mini + 1, -delta);
      res = qquery(lo, hi);
    }

    if(cmd == "count") {
      cout << (res.minv == 0 ? res.minc : 0) << endl;
    } else {
      int dv; cin >> dv;
      qsub(lo, hi, dv);

/*
node rres = qquery(0, 1);
cout << "*" << rres.minv << endl;
*/
    }
  }
  
}