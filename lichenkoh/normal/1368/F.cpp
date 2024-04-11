#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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

const int mn=1008;
int n;
bitset<mn> a;
int comm(vi const & v) {
  int k=v.size();
  printf("%d",k);
  for (auto &w:v) printf(" %d", w+1);
  printf("\n");
  fflush(stdout);
  int r; scanf("%d",&r);
  if (r==-1) {
    assert(0); // Invalid move or exceeded
  }
  r--;
  return r;
}

int gcnt=0;

void sset(int x) {
  if (!a[x]) {
    a[x]=true;
    gcnt++;
  }
}
void reset(int x) {
  if (a[x]) {
    a[x]=false;
    gcnt--;
  }
}
const bool DBG=0;
int ask(vi const & v) {
  int k=v.size();
  if (k==0) return -1;
  for (auto &w:v) sset(w);

  if (DBG) {
    for (int x=0;x<n;x++) {
      printf("%d ",a[x]?1:0);
    }
    printf("end v after set\n");
  }

  int r=comm(v);
  for (int i=0;i<k;i++) {
    reset((r+i)%n);
  }
  return r;
}

pii getk() {
  pii best=MP(-1,-1);
  for (int k=2;k<=(n+1)/2;k++) {
    int quo=n/k,rem=n%k;
    int res=(k-1)*(quo-1) + max(rem-1,0);
    chkmax(best,MP(res,k));
  }
  return best;
}
int modk[mn];
int main() 
{
  scanf("%d",&n);
  pii best=getk();
  int k=best.snd;
  for (int x=0;x<n;x++) modk[x]=x%k;
  int want=best.fst;
  int groups=(n+k-1)/k;
  if(DBG) printf("k:%d want:%d\n",k,want);
  for (int q=1;q<k;q++) {
    for (int g=0;g<groups;g++) {
      vi v;
      if (DBG) {
        for (int x=0;x<n;x++) {
          printf("%d ",a[x]?1:0);
        }
        printf("end v q:%d\n",q);
      }
      for (int x=0;x<n;x++) {
        if ((!a[x]) && modk[x]!=0 && modk[x]<=q) {
          v.PB(x);
          if (v.size() == k) break;
        }
      }
      if (v.size()) {
        ask(v);
      }
    }
  }
  printf("0\n");
  fflush(stdout);
}