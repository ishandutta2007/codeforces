#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <cassert>

using namespace std;

struct ball {
  ball() : xc(0), yc(0), r(0) {}
  ball(long long xc, long long yc, long long r) : xc(xc), yc(yc), r(r) {}
  long long xc, yc, r;
};

pair<long long, long long> X[100000];
pair<long long, long long> Z[100];

long long dist(ball bl, pair<long long, long long> x) {
  return min(llabs(bl.xc - x.first), llabs(bl.yc - x.second));
}

void calcradius(ball& bl, int M) {
  bl.r = 0;
  for(int i = 0; i < M; i++) {
    bl.r = max(bl.r, dist(bl, Z[i]));
  }
}

vector<ball> solve(int M) {
  if(M == 0) {
    return vector<ball>(1);
  }

  vector<ball> res;
  for(int i = 0; i < M; i++) {
    for(int j = i; j < M; j++) {
      for(int a = 0; a < M; a++) {
        for(int b = a; b < M; b++) {
          ball bb((Z[i].first + Z[j].first) / 2,
                  (Z[a].second + Z[b].second) / 2, 0);
          calcradius(bb, M);
          if(res.empty() || bb.r == res[0].r) {
            res.push_back(bb);
          } else if(bb.r < res[0].r) {
            res.resize(1);
            res[0] = bb;
          }
        }
      }
    }
  }
  return res;
}

vector<ball> welzl(int N, int y) {
  vector<ball> bl = solve(y);
  //assert(y <= 4);

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < bl.size(); j++) {
      if(dist(bl[j], X[i]) > bl[j].r) {
        bl[j--] = bl.back();
        bl.resize(bl.size() - 1);
      }
    }
    if(bl.empty()) {
      Z[y] = X[i];
      bl = welzl(i, y + 1);
      swap(X[i], X[i / 2]);
    }
  }

  return bl;
}

int main() {
  int N; cin >> N;
  for(int i = 0; i < N; i++) {
    long long x, y;
    cin >> x >> y;
    X[i].first = 2 * (x - y);
    X[i].second = 2 * (x + y);
  }

  srand(555);
  random_shuffle(X, X + N);

  ball bl = welzl(N, 0)[0];

  for(int i = 0; i < N; i++) {
    if(dist(bl, X[i]) > bl.r) {
      cerr << "PROB" << endl;
    }
  }

  cout << bl.r / 2 << "." << (bl.r % 2 ? "5" : "0") << endl;
  return 0;
}