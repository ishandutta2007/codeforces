#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

#define TRACE(x) cerr << #x <<  " = " << x << endl
#define _ << " " <<
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> P;
typedef long long ll;

const int MAX = 1<<19;

ll ccw(P a, P b, P c) {
  return (ll) a.X * (b.Y - c.Y) + (ll) b.X * (c.Y - a.Y) + (ll) c.X * (a.Y - b.Y);
}

vector<P> convex_hull(vector<P> pts) {
  sort(pts.begin(), pts.end());
  vector<P> H;

  REP(step, 2) {
    auto start = H.size();
    for (P P : pts) {
      while (H.size() >= start+2 && ccw(H[H.size()-2], H[H.size()-1], P) <= 0)
        H.pop_back();
      H.push_back(P);
    }

    H.pop_back();
    reverse(pts.begin(), pts.end());
  }
  return H;
}

void yes() {
  printf("YES\n");
  exit(0);
}

void no() {
  printf("NO\n");
  exit(0);
}

vector <P> H[2];

struct str {
  ll len1, len2, pov;
};

ll sq(int x) { return (ll) x * x; }
ll dist(P a, P b) {
  return sq(a.X - b.X) + sq(a.Y - b.Y);
}

bool operator == (str a, str b) {
  return a.len1 == b.len1 && a.len2 == b.len2 && a.pov == b.pov;
}

vector <str> V[2];
int z[MAX];

void z_algorithm(vector <str> T, int N, int *z) {
  z[0] = N;
  int L = -1, R = -1;

  FOR(i, 1, N) {
    z[i] = i >= R ? 0 : min(R-i, z[i-L]);
    while (i+z[i] < N && T[i+z[i]] == T[z[i]]) ++z[i];
    if (i+z[i] > R) L = i, R = i+z[i];
  }
}

int main()
{
  int n[2];
  scanf("%d%d", &n[0], &n[1]);

  REP(i, 2) {
    REP(j, n[i]) {
      int x, y;
      scanf("%d%d", &x, &y);
      H[i].push_back(P(x, y));
    }
    H[i] = convex_hull(H[i]);
  }

  if (H[0].size() != H[1].size()) no();

  int m = (int) H[0].size();
  if (m == 1)
    yes();

  if (m == 2) {
    if (dist(H[0][0], H[0][1]) == dist(H[1][0], H[1][1])) yes();
    else no();
  }

  REP(i, 2) {
    REP(j, m) {
      P pros = H[i][(m+j-1)%m], ja = H[i][j], slj = H[i][(j+1)%m];
      V[i].push_back({dist(pros, ja), dist(ja, slj), ccw(pros, ja, slj)});
    }
  }

  vector <str> Z;
  REP(j, m) Z.push_back(V[0][j]);
  REP(i, 2)
    REP(j, m)
    Z.push_back(V[1][j]);

  z_algorithm(Z, (int) Z.size(), z);

  FOR(i, m, (int) Z.size())
    if (z[i] == m) yes();
  no();
    
  return 0;
}