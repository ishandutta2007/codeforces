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
const int INF=1<<30;
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

const int MAXN=1e6+2;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int sp[MAXP+1];
void sieve() {
  for (int i = 0; i <= MAXP; i++) {
    sieve_array[i] = true;
    sp[i]=INF;
  }
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = sqrt(MAXP)+1;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= MAXP; j+=i) {
        sieve_array[j] = false;
        chkmin(sp[j],i);
      }
    }
  }
  for (int i = 2; i <= MAXP; i++) {
    if(sieve_array[i]) {
      sp[i]=i;
    }
  }
}
const int mn=5002;
int a[mn];
int n,k;
const int mx=1e6+2;
int target[5000];
int getfac(int x) {
  int sz=1;
  target[0]=1;
  while(x>1) {
    int p=sp[x];
    x/=p; int elim=1;
    while(0==x%p) {
      x/=p; elim++;
    }
    int pp=1;
    int psz=sz;
    for (int e=1;e<=elim;e++) {
      pp*=p;
      for (int i=0;i<psz;i++) {
        target[sz++]=target[i]*pp;
      }
    }
  }
  return sz;
}

/*void check(int x) {
  set<int> s;
  int slim=min(x,(int)(sqrt(x)+2));
  for (int y=1;y<=slim;y++) {
    if ((x%y)==0) {s.insert(y); s.insert(x/y);}
  }
  int sz=getfac(x);
  assert(sz<(5000-5));
  set<int> got; for (int i=0;i<sz;i++) got.insert(target[i]);
  if(got!=s) {
    printf("x:%d\n",x);
  }
}*/
const int MK=10; // Edges in K5
const int OVF=1<<30;
typedef int LST;
typedef struct LimitedSetStruct {
  LST a[MK];
  int sz;
  void ins(LST val) {
    if (sz>=MK) {sz=OVF; return;}
    else {
      for (int i=0;i<sz;i++) {
        if (a[i]==val) return;
      }
      a[sz++]=val;
    }
  }
  bool ovf() {
    return sz==OVF;
  }
  void setovf() {
    sz=OVF;
  }
} LimitedSet;
typedef struct LimitedVecStruct {
  LST a[MK];
  int sz;
  void ins(LST val) {
    if (sz>=MK) {sz=OVF; return;}
    else {
      a[sz++]=val;
    }
  }
  bool ovf() {
    return sz==OVF;
  }
  void setovf() {
    sz=OVF;
  }
} LimitedVec;
int ufParent[mx];
int ufSize[mx]; // Size
void ufreset(int x) {
  ufParent[x]=x;
  ufSize[x]=1;  
}
void ufinit(int n) {
  for (int x=0;x<n;x++) {
    ufParent[x]=x;
    ufSize[x]=1;
  }
}
int uffind(int x) {
  if (ufParent[x] != x) {
    ufParent[x] = uffind(ufParent[x]);
  }
  return ufParent[x];
}
void ufunion(int x, int y) {
  if (rand()&1) swap(x,y); 
  int xr = uffind(x);
  int yr = uffind(y);
  if (xr==yr) return;
  ufParent[xr] = yr;
  ufSize[yr]+=ufSize[xr];
}

LimitedSet cand[mx];
LimitedVec tmp[mx];
int seen[mx];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve();
  /*for (int x=1;x<=1000000;x++) {
    check(x);
  }
  return 0;*/
  //getfac(48);
  //auto blah=getfac(48);
  //for (auto &w:blah) printf("%d ",w);
  //printf("\n");
  //return 0;
  n=rint(),k=rint();
  for (int i=0;i<n;i++) a[i]=rint();
  for (int x=0;x<n;x++) {
    for (int y=0;y<x;y++) {
      int diff=abs(a[x]-a[y]);
      if(diff){
        tmp[diff].ins((x<<16)|y);
      }
    }
  }
  for (int diff=1;diff<mx;diff++) {
    if (tmp[diff].sz) {
      int sz=getfac(diff);
      for (int i=0;i<sz;i++) {
        int t=target[i];
        if (tmp[diff].ovf()) cand[t].setovf();
        else {
          for (int q=0;q<tmp[diff].sz;q++) {
            cand[t].ins(tmp[diff].a[q]);
          }
        }
      }
    }
  }
  ufinit(mx);
  for (int id=1;id<mx;id++) {
    if (cand[id].ovf()) continue;
    for (int q=0;q<cand[id].sz;q++) {
      auto edge=cand[id].a[q];
      int x=edge>>16,y=edge&0xffff;
      //printf("id:%d x:%d y:%d\n",id,x,y);
      ufunion(x,y);
    }
    int need=0;
    for (int q=0;q<cand[id].sz;q++) {
      auto edge=cand[id].a[q];
      int x=edge>>16,y=edge&0xffff;
      if (ufParent[x]==x) {
        need+=ufSize[x]-1;
        ufSize[x]=1;
        //printf("x:%d need:%d\n",x,need);
      }
      if (ufParent[y]==y) {
        need+=ufSize[y]-1;
        ufSize[y]=1;
        //printf("y:%d need:%d\n",y,need);
      }
    }
    if (need<=k) {
      printf("%d\n",id);
      return 0;
    }
    for (int q=0;q<cand[id].sz;q++) {
      auto edge=cand[id].a[q];
      int x=edge>>16,y=edge&0xffff;
      ufParent[x]=x; ufSize[x]=1;
      ufParent[y]=y; ufSize[y]=1;
    }

  }
}