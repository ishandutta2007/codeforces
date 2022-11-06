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
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const bool DBF=0;
const int mn=1002;
int a[mn];
int gn,gc,gm;
void out(int p, int val) {
  assert(1<=p&&p<=gn);
  a[p]=val;
  printf("%d\n",p); fflush(stdout);
  if (DBF) {
    printf("%d\n",p); fflush(stdout); for (int x=1;x<=gn;x++) printf("%d ",a[x]==-1?0:a[x]); printf(" end arr\n");
  }
}

int get() {
  int val;
  scanf("%d",&val);
  //val=(rand()%gc)+1; if (DBF) printf("get:%d\n",val);
  return val;
}

bool isdone(int n) {
  for (int x=1;x<=n;x++) {
    if (a[x]==-1) return false;
  }
  for (int x=2;x<=n;x++) {
    if (a[x-1]>a[x]) return false;
  }
  return true;
}

pair<bool,int> decide(int n, int val) {
  int l,r;
  for (int p=1;p<=n;p++) {
    if (a[p]==-1) {l=p; break;}
    if (a[p]>val) return MP(0,p);
  }
  for (int p=n;p>=1;p--) {
    if (a[p]==-1) {r=p; break;}
    if (a[p]<val) return MP(1,p);
  }
  int sum=1+gc;
  int val2=2*val;
  if (val2<sum) return MP(0,l);
  else return MP(1,r);
}
ll gseed;
void play(int n,int m,int c) {
  gn=n;gc=c;gm=m;
  memset(a,-1,sizeof a);
  a[0]=1; a[n+1]=c;
  for (int r=0;r<m;r++) {
    int val=get();
    pair<bool,int> bp=decide(n,val);
    if (bp.fst) a[0]=val-1;
    else a[n+1]=val+1;
    out(bp.snd,val);
    if (isdone(n)) return;
  }
  printf("Failure seed:%lld\n",gseed); exit(-1);
}

void go() {
  for (int k=0;k<500000;k++) {
    ll seed=clock();
    //if (DBF) seed=2329;
    gseed=seed;
    srand(seed);
    int n=rand()%10+1;
    int c=rand()%10+1;
    int m=n*((c+1)/2);
    if (DBF) printf("seed:%lld n:%d m:%d c:%d\n",seed,n,m,c);
    play(n,m,c);
    //if (0==(k&0xff)) {printf("%d\n",k); fflush(stdout);}
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //go(); return 0;
  int n,m,c; scanf("%d%d%d",&n,&m,&c);
  play(n,m,c);
}