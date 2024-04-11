#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
#define snd second
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

class GaussianElimination {
public:
  const bool UNIQUE=true; // Need a unique basis. We do this by eliminating the upper triagle in
  // addition to the lower triangle
  const bool NEEDSOL=true; // Need a linear combination that sums to the solution
  int **a;
  int **lincomb;
  int sgn=1;
  int xlim,ylim,mod;
  int *y2x;
  inline int mull(int x, int y) {return (x*(ll)y)%mod;}
  int gauss(int _xlim, int _ylim, int **inp, int _mod) {
    a=inp;
    // Returns the rank
    int rank=0;
    xlim=_xlim,ylim=_ylim,mod=_mod;
    y2x=new int[ylim];
    memset(y2x,-1,sizeof(y2x[0])*ylim);
    if (NEEDSOL) {
      lincomb = new int*[xlim];
      for (int x=0;x<xlim;x++) {
        lincomb[x] = new int [xlim];
        memset(lincomb[x], 0, sizeof(lincomb[0])*xlim);
        lincomb[x][x]=1;
      }
    }
    int xlo=0;
    for (int yelim=0;yelim<ylim;yelim++) {
      for (int xs=xlo;xs<xlim;xs++) {
        if (a[xs][yelim]!=0) {
          if (xs!=xlo) {
            sgn=-sgn;
            for (int y=0;y<ylim;y++) swap(a[xs][y], a[xlo][y]);
            if (NEEDSOL) for (int z=0;z<xlim;z++) swap(lincomb[xs][z], lincomb[xlo][z]);
          }
          int inv=mod_pow(a[xlo][yelim], mod-2, mod);
          for (int y=yelim;y<ylim;y++) {
            a[xlo][y]=mull(a[xlo][y], inv);
          }
          if (NEEDSOL) for (int z=0;z<xlim;z++) lincomb[xlo][z]=mull(lincomb[xlo][z], inv);
          for (int x=UNIQUE?0:xlo+1;x<xlim;x++) {
            if (x==xlo) continue;
            int sub=a[x][yelim];
            if (sub) {
              for (int y=yelim;y<ylim;y++) {
                a[x][y]=(a[x][y]-sub*a[xlo][y])%mod;
                if (a[x][y]<0) a[x][y]+=mod;
              }
              if (NEEDSOL) {
                for (int z=0;z<xlim;z++) {
                  lincomb[x][z]=(lincomb[x][z]-sub*lincomb[xlo][z])%mod;
                  if (lincomb[x][z]<0) lincomb[x][z]+=mod;
                }
              }
            }
          }
          y2x[yelim]=xlo;
          xlo++; rank++;
          break;
        }
      }
    }
    /*for (int x=0;x<xlim;x++) {
      for (int y=0;y<ylim;y++) {
        printf("%d ",a[x][y]);
      }
      printf("\n");
    } printf("\n");
    for (int x=0;x<xlim;x++) {
      for (int y=0;y<xlim;y++) {
        printf("%d ",lincomb[x][y]);
      }
      printf("\n");
    } printf("\n");*/
    return rank;
  }
  int getdet() {
    assert(xlim==ylim);
    int det=1;
    for (int x=0;x<xlim;x++) {
      det=mull(det,a[x][x]);
    }
    return sgn*det;
  }
  bool getsol(int *vec, int *sol) {
    // vec is going to be mutated.
    if (NEEDSOL) memset(sol,0,sizeof(sol[0])*xlim);
    for (int yelim=0;yelim<ylim;yelim++) {
      if (vec[yelim]) {
        int xlo=y2x[yelim];
        if (xlo==-1) return false;
        int sub=vec[yelim];
        for (int y=yelim;y<ylim;y++) {
          vec[y]=(vec[y]+(mod-sub)*(ll)a[xlo][y])%mod;
        }
        if (NEEDSOL) {
          for (int z=0;z<xlim;z++) {
            sol[z]=(sol[z]+sub*(ll)lincomb[xlo][z])%mod;
          }
        }
      }
    }
    return true;
  }
};
int **a;
char inp[504][504];
char targ[504];
int *tar;
int *sol;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n,m; scanf("%d %d\n",&n,&m);
  for (int x=0;x<n;x++) {
    scanf("%s\n",inp[x]);
  }
  a=new int*[n];
  for (int x=0;x<n;x++) {
    a[x]=new int[m];
    for (int y=0;y<m;y++) a[x][y]=inp[x][y]-'a';
  }
  GaussianElimination g;
  int rank=g.gauss(n,m,a,5);
  int ans=mod_pow(5,n-rank,MOD);
  int q; scanf("%d\n", &q);
  tar=new int[m];
  sol=new int[n];
  for (int i=0;i<q;i++) {
    scanf("%s\n",targ);
    for (int y=0;y<m;y++) tar[y]=targ[y]-'a';
    bool hassol=g.getsol(tar,sol);
    if (hassol) {
      for (int y=0;y<m;y++) tar[y]=0;
      for (int x=0;x<n;x++) {
        if (sol[x]) {
          for (int y=0;y<m;y++) tar[y]=(tar[y]+sol[x]*(ll)(inp[x][y]-'a'))%5;
        }
      }
      for (int y=0;y<m;y++) {
        assert(tar[y]==targ[y]-'a');
      }
      printf("%d\n",ans);
    }
    else printf("0\n");
  }
}