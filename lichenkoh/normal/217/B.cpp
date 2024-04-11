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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int INF=1e9;
const int mn=1e6+4;
bool ok;
vector<pair<char,int> > vans;
char last;
void init() {
  ok=0;
  vans.clear();
  last='B';
}
int getrep() {
  char last=' ';
  int have=0;
  int rep=0;
  for (auto &w:vans) {
    if (w.fst==last) {
      have+=w.snd;
    }
    else {
      rep+=max(have-1,0);
      have=w.snd;
    }
    last=w.fst;
  }
  rep+=max(have-1,0);
  return rep;
}
void f(int t, int b, int n) {
  if (n<0) return;
  if (n==0) {
    if (t==1&&b==1) {
      vans.PB(MP('T',1));
      ok=1;
    }
    return;
  }
  if (t<1||b<1) return;
  if (t>b) {
    int toadd=(t-1)/b;
    if (toadd==0) return;
    vans.PB(MP('T',toadd));
    f(t-b*toadd,b,n-toadd);
  }
  else {
    int toadd=(b-1)/t;
    if (toadd==0) return;
    vans.PB(MP('B',toadd));
    f(t,b-t*toadd,n-toadd);
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n,want; cin>>n>>want;
  vector<pair<char,int> > final;
  int best=INF;
  for (int t=1;t<=want;t++) {
    init();
    f(t,want,n-1);
    int rep=getrep();
    if (ok&&rep<best) {
      best=rep; final=vans;
    }
    init();
    f(want,t,n-1);
    rep=getrep();
    if (ok&&rep<best) {
      best=rep; final=vans;
    }
  }
  if (best==INF) {
    printf("IMPOSSIBLE\n");
  }
  else {
    printf("%d\n",best);
    for (auto it=final.rbegin();it!=final.rend();++it) {
      for (int i=0;i<it->snd;i++) {
        printf("%c",it->fst);
      }
    }
  }
}