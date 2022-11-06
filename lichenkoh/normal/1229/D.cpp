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
int rdig();int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
const int MAXK=5;
const int MAX_SUBGROUP = 156;
const int MAX_NPERM = 120;
struct perm {
  int p[5];
};
int k;
perm mul(perm const & a, perm const & b) {
  perm c;
  for (int i=0;i<k;i++) {
    c.p[i]=b.p[a.p[i]];
  }
  return c;
}


int perm2t(perm const & p) {
  int ans=0;
  unsigned b=(1U<<k)-1;
  for (int i=0;i<(k-1);i++) {
    int x=p.p[i];
    int add=(x==0)?0:__builtin_popcount(b&((1U<<x)-1));
    ans+=add;
    b&=~(1U<<x);
    ans*=(k-i-1);
  }
  return ans;
}
perm t2perm[MAX_SUBGROUP];
int nperm=0;
void init_t2perm() {
  vector<int> v(k);
  for (int i=0;i<k;i++) v[i]=i;
  do {
    for (int i=0;i<k;i++) t2perm[nperm].p[i] = v[i];
    /*int testgot=perm2t(t2perm[nperm]);
    if(nperm!=testgot) {
      printf("Failed. Expected nperm=%d, got %d\n",nperm,testgot);
      for (int i=0;i<k;i++) printf("%d ",t2perm[nperm].p[i]);
      printf("\n");
      exit(0);
    }*/
    nperm++;
  } while(next_permutation(v.begin(),v.end()));
  //printf("passed t2pmerm check\n");
}

int multable[MAX_NPERM][MAX_NPERM];

void init_multable() {
  init_t2perm();
  for (int x=0;x<MAX_NPERM;x++) for (int y=0;y<MAX_NPERM;y++) {
    multable[x][y]=perm2t(mul(t2perm[x],t2perm[y]));
    //printf("%d x %d = %d\n",x,y,multable[x][y]);
  }
}

using subgroup_t = bitset<MAX_NPERM>;

vector<subgroup_t> subgroups;

int complete_dp[MAX_SUBGROUP][MAX_NPERM];

pair<int,bool> complete(int si, int newperm) {
  int dpval=complete_dp[si][newperm];
  if (dpval!=-1) {
    return MP(dpval,false);
  }
  subgroup_t s=subgroups[si];
  // BFS
  queue<int> q;
  {
    int z=newperm;
    {
      int tmp=z;
      while(!s[tmp]) {
        q.push(tmp);
        s[tmp]=true;
        tmp=multable[tmp][z];
      }
    }
  }
  while(!q.empty()) {
    int x=q.front(); q.pop();
    for(int y=s._Find_first(); y<nperm; y= s._Find_next(y)) {
      {
        int z=multable[x][y];
        {
          int tmp=z;
          while(!s[tmp]) {
            q.push(tmp);
            s[tmp]=true;
            tmp=multable[tmp][z];
          }
        }
      }
      {
        int z=multable[y][x];
        {
          int tmp=z;
          while(!s[tmp]) {
            q.push(tmp);
            s[tmp]=true;
            tmp=multable[tmp][z];
          }
        }
      }
    }
  }
  for (int other=0;other<subgroups.size();other++) {
    if (s==subgroups[other]) {
      int ans=other;
      complete_dp[si][newperm]=ans;
      return MP(ans,false);
    }
  }
  int ans=subgroups.size();
  subgroups.PB(s);
  complete_dp[si][newperm]=ans;
  return MP(ans,true);
}

vpii si2perm[MAX_SUBGROUP];
int si2sz[MAX_SUBGROUP];
void gen() {
  memset(complete_dp,-1,sizeof complete_dp);
  init_multable();
  subgroups.reserve(MAX_SUBGROUP);
  subgroup_t s; s.reset(); s[0] = true;
  subgroups.PB(s);
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int si=q.front(); q.pop();
    for (int pi=0;pi<nperm;pi++) {
      // Try to add to subgroup
      pii res=complete(si,pi);
      if (res.snd) {
        q.push(res.fst);
      }
    }
  }
  for (int si=0;si<subgroups.size();si++) {
    si2sz[si]=subgroups[si].count();
    for (int pi=0;pi<nperm;pi++) {
      int ci=complete_dp[si][pi];
      if (ci!=si) {
        si2perm[si].PB(MP(pi,ci));
      }
    }
  }
}
const int mn=(2e5)+4;
int inp[mn];
int qpi2nxt[mn][MAX_NPERM];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=rint(); k=rdig();
  gen();
  for (int q=1;q<=n;q++) {
    perm p;
    for (int i=0;i<k;i++) p.p[i]=rdig()-1;
    int pi=perm2t(p);
    inp[q]=pi;
  }
  for (int pi=0;pi<nperm;pi++) qpi2nxt[n][pi]=n+1;
  for (int q=n;q>=1;q--) {
    memcpy(qpi2nxt[q-1],qpi2nxt[q],sizeof qpi2nxt[0]);
    qpi2nxt[q-1][inp[q]]=q;
  }
  ll final=0;
  for (int l=1;l<=n;l++) {
    int si=complete_dp[0][inp[l]];
    /*if (si==-1) {
      printf("l:%d inpl:%d\n",l,inp[l]); exit(0);
    }*/
    int r=l;
    while(1) {
      pii nxt=MP(n+1,-1);
      for (auto &w:si2perm[si]) {
        int pi=w.fst,ci=w.snd;
        chkmin(nxt,MP(qpi2nxt[r][pi],ci));
      }
      int len=nxt.fst-r;
      final+=len*si2sz[si];
      if (nxt.fst==n+1) break;
      r=nxt.fst;
      si=nxt.snd;
    }
  }

  //printf("%d\n",(int)subgroups.size());
  printf("%lld\n",final);
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
    char ch=*stdinPos;
    ++stdinPos;
    return ch;
}

int rdig() {
  return rch()-'0';
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