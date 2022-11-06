#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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


typedef struct _trie {
  ll val;
  struct _trie *ch[2];
} trie;

trie *newnode() {
  trie *r = new trie;
  r->val=0;
  r->ch[0]=NULL;
  r->ch[1]=NULL;
  return r;
}

void ins(trie *r, ll x, int k) {
  r->val++;
  if (k==-1) return;
  ll b=(x>>k)&1;
  if (r->ch[b]==NULL) {
    r->ch[b]=newnode();
  }
  ins(r->ch[b],x,k-1);
}
void rm(trie *r, ll x, int k) {
  r->val--;
  if (k==-1) return;
  ll b=(x>>k)&1;
  //if (r->ch[b]==NULL) {
  //  r->ch[b]=newnode();
  //}
  rm(r->ch[b],x,k-1);
}
pair<bool,ll> query(trie *r, ll Xor, int k, int forcek1) {
  if (k==-1) {
    if (r->val>0) {
      return MP(true,0);
    }
    return MP(false,-1);
  }
  int b;
  int Xorbit=(Xor>>k)&1;
  if (k==forcek1) b=1;
  else if (k>forcek1&&Xorbit==1) {b=0;}
  else b=Xorbit;
  /*printf("k:%d prefers b:%d. val[0]:%d val[1]:%d\n",k,b,
    r->ch[0]==NULL?0:(r->ch[0]->val>0),
    r->ch[1]==NULL?0:(r->ch[1]->val>0)
    );*/
  if (r->ch[b]!=NULL&&(r->ch[b]->val>0)) {
    //printf("k:%d b:%d\n",k,b);
    auto got=query(r->ch[b],Xor,k-1,forcek1);
    got.snd|=(((ll)b)<<k);
    return got;
  }
  else if (r->ch[b^1]!=NULL&&(r->ch[b^1]->val>0)) {
    //printf("k:%d b:%d\n",k,b);
    auto got=query(r->ch[b^1],Xor,k-1,forcek1);
    got.snd|=(((ll)(b^1))<<k);
    return got;
  }
  else return MP(false,-1);
}
pair<bool,ll> query2(trie *r, ll Xor, int k) {
  ll ans=LLONG_MAX;
  for (int forcek1=0;forcek1<=k;forcek1++) {
    if (0==((Xor>>forcek1)&1)) {
      auto got=query(r,Xor,k,forcek1);
      if (got.fst) {
        //printf("forcek1:%d got:%lld\n",forcek1,got.snd);
        if (Xor < (Xor ^ got.snd)) {
          rm(r,got.snd,k);
          return MP(true,got.snd);
          //chkmin(ans,got.snd);
        }
      }
    }
  }
  return MP(false,-1);
  /*if (ans==LLONG_MAX) return MP(false,-1);
  rm(r,ans,k);
  return MP(true,ans);*/
}
const int mk=59;
const int mn=1e5+4;
bitset<mn> used;
int a[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  trie *r=newnode();
  int n=rint();
  for (int i=0;i<n;i++) ins(r,rlong(),mk);
  ll now=0;
  vector<ll> vans;
  for (int s=0;s<n;s++) {
    //printf("s:%d\n",s);
    auto pgot=query2(r,now,mk);
    if (!pgot.fst) {
      printf("No\n"); exit(0);
    }
    ll got=pgot.snd;
    ll newnow=got^now;
    //printf("got:%lld now:%lld newnow:%lld\n",got,now,newnow);
    if (!(now<newnow)) {
      printf("No\n"); exit(0);
    }
    vans.PB(got);
    now=newnow;
  }
  printf("Yes\n");
  for (auto &w:vans) {
    printf("%lld ",w);
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