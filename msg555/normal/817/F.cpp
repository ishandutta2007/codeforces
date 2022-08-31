#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN (1LL << 18)

typedef unsigned char uint8;

struct tnode {
  tnode() : cntf(2), laz(0), c(NULL) {
  }

  void alloc_children() {
    if (!c) {
      c = new tnode[2];
    }
  }

  void reset_count(long long sz) {
    if (laz == 1) {
      cntf = 1;
    } else if (laz == 2) {
      cntf = 2;
    } else {
      cntf = c ? c[0].cntf | c[1].cntf : 2;
      if (laz == 3) {
        cntf = ((cntf & 1) << 1) | ((cntf & 2) >> 1);
      }
    }
  }

  void push(long long A, long long B) {
    long long M = (A + B) / 2;
    if (laz != 0) {
      alloc_children();
      c[0].update(A, M, A, M, laz);
      c[1].update(M, B, M, B, laz);
      laz = 0;
    }
  }

  void update(long long A, long long B, long long a, long long b,
              int op) {
    if (a <= A && B <= b) {
      if (op != 3) {
        laz = op;
      } else {
        laz ^= 3;
      }
      reset_count(B - A);
      return;
    }

    alloc_children();
    push(A, B);

    long long M = (A + B) / 2;
    if (a < M) {
      c[0].update(A, M, a, b, op);
    }
    if (M < b) {
      c[1].update(M, B, a, b, op);
    }
    reset_count(B - A);
  }

  long long mex(long long A, long long B) {
    if (cntf == 2) {
      return A;
    }

    push(A, B);

    long long M = (A + B) / 2;
    if (!c) {
      return A;
    }
    if (c[0].cntf != 1) {
      return c[0].mex(A, M);
    }
    return c[1].mex(M, B);
  }

  uint8 cntf;
  uint8 laz;
  tnode* c;
};

int main() {
  ios_base::sync_with_stdio(false);

  int Q; 
  cin >> Q;

  tnode root;
  vector<long long> qs;
  qs.push_back(0);
  qs.push_back(MAXN);

  vector<pair<int, pair<long long, long long> > > queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].first >>
           queries[i].second.first >> queries[i].second.second;
    queries[i].second.first--;
    qs.push_back(queries[i].second.first);
    qs.push_back(queries[i].second.second);
  }
  sort(qs.begin(), qs.end());
  qs.resize(unique(qs.begin(), qs.end()) - qs.begin());

  for (auto q : queries) {
    long long a = lower_bound(qs.begin(), qs.end(), q.second.first) - qs.begin();
    long long b = lower_bound(qs.begin(), qs.end(), q.second.second) - qs.begin();

    root.update(0, MAXN, a, b, q.first);
    cout << qs[root.mex(0, MAXN)] + 1 << '\n';
  }
  return 0;
}