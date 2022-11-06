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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int mn=300000+2;
set<int> r2b[mn],b2r[mn];
int q2r[mn],r2q[mn];

set<int> & q2b(int q) {
  return r2b[q2r[q]];
}

int q2c[mn];
bitset<mn> inp;
pair<int,pii> cqForBWant[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int bn; int qn; cin>>bn>>qn;
  {
    string sinp; cin>>sinp;
    for (int i=0;i<bn;i++) inp[i]=(sinp[i]=='1');
  }
  for (int q=0;q<qn;q++) {
    int r=q;
    int nb; cin>>nb;
    for (int i=0;i<nb;i++) {
      int b; cin>>b; --b;
      r2b[r].insert(b);
      b2r[b].insert(r);
    }
    q2r[q]=r; r2q[r]=q;
    q2c[q]=1;
  }
  int ans=0;
  for (int bWant=0;bWant<bn;bWant++) {
    bool needChange=!inp[bWant];
    int tidx=0;
    for (auto & r: b2r[bWant]) {
      int q=r2q[r];
      cqForBWant[tidx] = MP(q2c[q],MP(q2b(q).size(),q));
      ++tidx;
    }
    int sz=b2r[bWant].size();
    sort(cqForBWant,cqForBWant+sz);
    if (sz) {
      int cFirst=cqForBWant[0].fst,qFirst=cqForBWant[0].snd.snd;
      if (needChange) {
        ans+=cFirst;
        for (auto &bOfFirst:q2b(qFirst)) {
          inp[bOfFirst]=(!inp[bOfFirst]);
        }
      }
      assert(sz<=2);
      for (int idx=1;idx<sz;idx++) {
        int cDest=cqForBWant[idx].fst,qDest=cqForBWant[idx].snd.snd;
        int cFinal;
        if (needChange) {
          cFinal=cDest-cFirst;
        } else {
          cFinal=cDest+cFirst;
        }
        q2c[qDest]=cFinal;
        bool exch=(q2b(qDest).size() < q2b(qFirst).size());
        if (exch) swap(qFirst,qDest);

          for (auto &bFirst:q2b(qFirst)) {
            auto it=q2b(qDest).find(bFirst);
            if (it==q2b(qDest).end()) {
              q2b(qDest).insert(bFirst);
              b2r[bFirst].insert(q2r[qDest]);
            } else {
              q2b(qDest).erase(it);
              b2r[bFirst].erase(q2r[qDest]);
            }
          }

        if (exch) {
          swap(qFirst,qDest);
          int rFirst=q2r[qFirst],rDest=q2r[qDest];
          q2r[qFirst]=rDest;
          q2r[qDest]=rFirst;
          r2q[rFirst]=qDest;
          r2q[rDest]=qFirst;
        }
      } /*for*/
      for (auto &bOfFirst:q2b(qFirst)) {
        b2r[bOfFirst].erase(q2r[qFirst]);
      }
    } else {
      assert(!needChange);
    }
    printf("%d\n",ans);
  }
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