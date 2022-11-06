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
const ll INF=(1LL<<31)-2;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<pii> vpii;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

vi _hidden;
int _hiddenk;


pii ask(vi const & v) {
  /*vpii sub;
  for (auto &p:v) {
    sub.PB(MP(_hidden[p],p));
  }
  sort(sub.begin(),sub.end());
  pii got=sub[_hiddenk];
  //for (auto &p:v) printf("%d ",p);
  //pr/intf(" val:%d pos:%d\n",got.fst,got.snd);
  return got;
  */
  printf("?");
  for (auto &w:v) printf(" %d", w+1);
  printf("\n"); fflush(stdout);
  int pos,val;
  scanf("%d%d",&pos,&val);
  return MP(val,pos-1);
  
}

void done(int ans) {
  /*if (ans!=_hiddenk) {
    printf("Failed guessed_ans:%d _hiddenk:%d _hidden:\n",ans, _hiddenk);
    for (auto &w:_hidden) {
      printf("%d ",w);
    }
    printf("\n");
    exit(1);
  }*/
  
  printf("! %d\n",ans+1);
  fflush(stdout);
  
}

int go(int n, int k) {
  if (k==1) {
    return 0;
  }
  vector<int> hidden(n,-1);
  vector<pair<vi,pii> > history;
  while(1) {
    vi query;
    for (int p=0;p<n && query.size()<k;p++) {
      if (hidden[p]==-1) query.PB(p);
    }
    if (query.size() < k) {break;}
    else {
      pii got=ask(query); // queries = knownvp.size()
      int val=got.fst,pos=got.snd;
      history.PB(MP(query,MP(val,pos)));
      hidden[pos]=val;
    }
  }
  vpii knownvp; vi unknownp;
  for (int p=0;p<n;p++) {
    if (hidden[p]!=-1) knownvp.PB(MP(hidden[p],p));
    else unknownp.PB(p);
  }
  sort(knownvp.begin(),knownvp.end());
  vi base=history.back().fst;
  int basep=history.back().snd.snd;
  int otherp=history.front().snd.snd;
  int same=0,diff=0;
  for (int bi=0;bi<base.size();bi++) {
    if (base[bi]!=basep) {
      vi query=base;
      query[bi]=otherp;
      pii got=ask(query);
      if (got.snd==basep) {
        same++;
      } else {
        diff++;
      }
    }
  }
  if (history.front().snd.fst < history.back().snd.fst) {
    return same;
  } else {
    return diff;
  }
}

void bf() {
  int n=rand()%30+2;
  int k=rand()%(n-1)+1;
  _hidden.clear();
  for (int i=0;i<n;i++) _hidden.PB(i*10);
  random_shuffle(_hidden.begin(),_hidden.end());
  _hiddenk=rand()%k;
  int ans=go(n,k);
  done(ans);
}

int main() 
{
  //for (int i=0;i<10000;i++) bf();
  //printf("Ok\n");
  //return 0;
  int n,k; scanf("%d%d",&n,&k);
  done(go(n,k));
}