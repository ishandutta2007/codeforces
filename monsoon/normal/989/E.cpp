#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T>
inline void maximize(T& a, const T& b) { if (b > a) a = b; }

const int N = 210;
int n,x[N],y[N],q,m;
vector<int> line[N*N];
vector<int> mylines[N];
int goline[N][N];
double sums[N];

bool online(int i, int j, int k) {
  return (x[j]-x[i])*(y[k]-y[i]) - (y[j]-y[i])*(x[k]-x[i]) == 0;
}

struct vec_t {
  double v[N];
};

struct mat_t {
  double v[N][N];
};

vec_t vecmatmul(const vec_t& v, const mat_t& A) {
  vec_t u;
  REP(i,n) u.v[i] = 0;
  REP(i,n) REP(j,n) u.v[i] += v.v[j] * A.v[j][i];
  return u;
}

mat_t matmul(const mat_t& A, const mat_t& B) {
  mat_t C;
  REP(i,n) REP(j,n) C.v[i][j] = 0;
  REP(i,n) REP(k,n) REP(j,n) C.v[i][j] += A.v[i][k] * B.v[k][j];
  return C;
}

mat_t matpow(mat_t A, int k) {
  mat_t W;
  REP(i,n) REP(j,n) W.v[i][j] = i==j;
  while (k) {
    if (k&1) W = matmul(W, A);
    A = matmul(A, A);
    k /= 2;
  }
  return W;
}

int main() {
  scanf("%d",&n);
  REP(i,n) { scanf("%d%d",&x[i],&y[i]); }
  REP(i,n) REP(j,n) goline[i][j] = -1;

  REP(i,n) REP(j,i) if (goline[i][j] == -1) {
    REP(k,n) if (online(i,j,k)) { line[m].push_back(k); }
    FORE(_i,line[m]) FORE(_j,line[m]) if (*_i != *_j) { goline[*_i][*_j] = m; }
    FORE(_i,line[m]) mylines[*_i].push_back(m);
    m++;
  }

  mat_t Mat;
  REP(i,n) REP(j,n) if (goline[i][j] != -1) {
    Mat.v[i][j] = 1. / mylines[j].size() / line[goline[i][j]].size();
  }
  REP(i,n) FORE(j,mylines[i]) {
    Mat.v[i][i] += 1. / mylines[i].size() / line[*j].size();
  }

  const int MAXM_LOG = 14;
  mat_t pows_Mat[MAXM_LOG];
  pows_Mat[0] = Mat;
  REP(i,MAXM_LOG-1) {
    pows_Mat[i+1] = matmul(pows_Mat[i], pows_Mat[i]);
  }

  scanf("%d",&q);
  REP(i,q) {
    int ti,mi; scanf("%d%d",&ti,&mi); --ti; --mi;

    vec_t v;
    REP(i,n) v.v[i] = i==ti;
    int pw = 0;
    while (mi) {
      if (mi&1) v = vecmatmul(v, pows_Mat[pw]);
      mi/=2;
      pw++;
    }

    double ans = 0;
    REP(j,m) {
      double pr = 0;
      FORE(k,line[j]) pr += v.v[*k];
      ans = max(ans, pr / line[j].size());
    }
    printf("%.9lf\n", ans);
  }
}