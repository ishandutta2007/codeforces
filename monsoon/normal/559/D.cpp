#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
typedef long long ll;

struct pt {
  int x, y;
  pt() : x(0), y(0) { }
  pt(int x, int y) : x(x), y(y) { }
};

pt operator-(const pt& p, const pt& q) { return pt(p.x - q.x, p.y - q.y); }
ll operator^(const pt& p, const pt& q) { return ll(p.x)*q.y - ll(p.y)*q.x; }

const int N = 110000, LIMIT = 60;
int n;
pt p[2*N];
ll totar;
double fld[LIMIT];

int edge(int i, int j) {
  pt v = p[i] - p[j];
  return __gcd(abs(v.x), abs(v.y));
}

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d%d",&p[i].x,&p[i].y); }
  REP(i,n) { p[n+i] = p[i]; }

  REP(i,n) {
    totar += p[i] ^ p[i+1];
    totar -= edge(i, i+1);
  }
  totar = totar/2+1;

  REP(i,n) {
    ll ar = 0;
    ar -= edge(i, i+1);
    for(int j=i+1; j < i + min(n-2, LIMIT); ++j) {
      ar += p[j]-p[i] ^ p[j+1]-p[i];
      ar -= edge(j, j+1);

      fld[j-i] += (ar + edge(i, j+1))/2;
    }
  }

  double ans = totar;
  REP(i,LIMIT) {
    // prob = (pow(2,n-i-2) - 1) / (pow(2,n) - (n*n+n+2)/2)
    double prob = (1 - pow(2,-(n-i-2))) / (pow(2,i+2) - (n*n+n+2) * pow(2,-(n-i-2)-1));
    ans -= fld[i] * prob;
  }

  printf("%.10lf\n", ans);
}