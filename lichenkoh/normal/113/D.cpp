#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

typedef vector<ld> vd;
typedef vector<vd> vvd;
class MatrixInverse {
public:
  // square matrix
  // returns null if no inverse
  bool zero(ld x) {
    return fabs(x)<1e-9;
  }
  bool inv(vvd &M) { // Inverse is returned in M[0..n][n..2*n-1];
    int N = M.size();
    for (int i=0;i<N;i++) M[i].resize(2*N);
    for (int i = 0; i < N; i++) {
      M[i][i + N] = 1;
    }
    for (int r = 0; r < N; r++) {
      int k = r;
      while (zero(M[k][r])) {
        k++;
        if (k == N)
          return false; // no inverse
      }
      swap(M[r],M[k]);

      double lv = M[r][r];
      for (int j = 0; j < 2 * N; j++)
        M[r][j] /= lv;

      for (int i = 0; i < N; i++) {
        if (i != r) {
          lv = M[i][r];
          for (int j = 0; j < 2 * N; j++)
            M[i][j] -= lv * M[r][j];
        }
      }
    }
    return true;
  }
  vd solution(vvd &M, vd &inp) {//O(n^2)
    int n=M.size();
    vd sol(n);
    for (int r=0;r<n;r++) {
      for (int c=0;c<n;c++) {
        sol[r]+=M[r][c+n]*inp[c];
      }
    }
    return sol;
  }
};


const int mn=22;
vi g[mn];
ld vp[mn];
int gn;
vvd M;
void ad(int sx, int sy, int tx, int ty, ld val) {
  int n=gn;
  M[sx*n+sy][tx*n+ty]+=val;
}
ld vans[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m,a,b; cin>>n>>m>>a>>b; --a; --b;
  gn=n;
  if (n==1) {
    printf("1\n");
    exit(0);
  }
  for (int i=0;i<m;i++) {
    int x,y; cin>>x>>y; --x; --y;
    g[x].PB(y); g[y].PB(x);
  }
  for (int i=0;i<n;i++) cin>>vp[i];
  M; M.resize(n*n); for (int i=0;i<n*n;i++) M[i].resize(n*n);
  for (int sx=0;sx<n;sx++) {
    for (int sy=0;sy<n;sy++) {
      if (sx==sy) {
        ad(sx,sy,sx,sy,1);
        continue;
      }
      ad(sx,sy,sx,sy,vp[sx]*vp[sy]-1);
       {
        ld prob=(1-vp[sx])*(vp[sy])/(g[sx].size());
        for (auto &tx:g[sx]) {
          ad(sx,sy,tx,sy,prob);
        }
      }  
      {
        ld prob=(vp[sx])*(1-vp[sy])/(g[sy].size());
        for (auto &ty:g[sy]) {
          ad(sx,sy,sx,ty,prob);
        }
      }
      {
        ld prob=(1-vp[sx])*(1-vp[sy])/(g[sx].size()*g[sy].size());
        for (auto &tx:g[sx]) {
          for (auto &ty:g[sy]) {
            ad(sx,sy,tx,ty,prob);
          }
        }
      }
    }
  }
  /*for (int sx=0;sx<n;sx++) {
    for (int sy=0;sy<n;sy++) {
      for (int tx=0;tx<n;tx++) {
        for (int ty=0;ty<n;ty++) {
          printf("%d %d -> %d %d: %.f\n",sx,sy,tx,ty,M[sx*n+sy][tx*n+ty]);
        }
      }
    }
  }*/
  MatrixInverse matinv;
  matinv.inv(M);
  for (int r=0;r<n;r++) {
    vd v(n*n); v[r*n+r]=1;
    vd ans=matinv.solution(M,v);
    //ld ans=M[a*n+b][n*n+r*n+r];
    printf("%.10f ",ans[a*n+b]);
  }
  printf("\n");
}




static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof (stdinBuffer);
static const char* stdinPos = stdinDataEnd;

void readAhead(size_t amount)
{
    size_t remaining = stdinDataEnd - stdinPos;
    if (remaining < amount) {
       memmove(stdinBuffer, stdinPos, remaining);
       size_t sz = fread(stdinBuffer + remaining, 1, sizeof (stdinBuffer) - remaining, stdin);
       stdinPos = stdinBuffer;
       stdinDataEnd = stdinBuffer + remaining + sz;
       if (stdinDataEnd != stdinBuffer + sizeof (stdinBuffer))
         *stdinDataEnd = 0;
    }
}

int rint()
{
    readAhead(16);

    int x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}
char rch()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
long long rlong()
{
    readAhead(32);

    long long x = 0;
    bool neg = false;
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    if (*stdinPos == '-') {
       ++stdinPos;
       neg = true;
    }

    while (*stdinPos >= '0' && *stdinPos <= '9') {
       x *= 10;
       x += *stdinPos - '0';
       ++stdinPos;
    }

    return neg ? -x : x;
}