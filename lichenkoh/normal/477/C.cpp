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
const int UNDEF = -1;
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

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

int readInt()
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
const int mp=502,mc=26;
int fail[mp];
int memo[mp][mc];
char p[mp];
// Walk the KMP DFA from state j with letter x
int dfa(int oldk, char x) {
  int dpval=memo[oldk][x-'a'];
  if (dpval!=-1) return dpval;
  int k=oldk;
  int ans;
  if (p[k]==x) {
    ans=k+1;
  }
  else if (k==0) ans=0;
  else {
    ans=dfa(fail[k-1],x);
  }
  return memo[oldk][x-'a']=ans;
}
// Build KMP failure table
void buildfail(int m) {
  memset(memo,-1,sizeof memo);
  int k = 0;
  for (int i = 1; i < m; i++) {
    while (k > 0 && p[k] != p[i])
      k = fail[k - 1];
    if (p[k] == p[i])
      ++k;
    fail[i] = k;
    //printf("fail:%d %d\n",i,k);
  }
}

const int MAXSEG=2002;
int t[MAXSEG*2];
int segn;
void modify(int l, int r, int value) {
  int n=segn;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmax(t[l++], value);
    if (r&1) chkmax(t[--r], value);
  }
}

int query(int p) {
  int n=segn;
  int res = 0;
  for (p += n; p > 0; p >>= 1) chkmax(res, t[p]);
  return res;
}

void push() {
  int n=segn;
  for (int i = 1; i < n; ++i) {
    chkmax(t[i<<1], t[i]);
    chkmax(t[i<<1|1], t[i]);
    //t[i] = 0;
  }
}

const int ms=2002;
char s[ms];
int flo[2][mp][ms];
int fhi[2][mp][ms];
int vans[ms];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%s\n%s\n",s,p);
  int m=strlen(p);
  buildfail(m);
  int n=strlen(s);
  int maxocc=n/m;
  int cur=1,nxt=0;
  for (int state=0;state<m;state++) {
    for (int occ=0;occ<=maxocc;occ++) {
      flo[nxt][state][occ]=INF;
      fhi[nxt][state][occ]=-INF;
    }
  }
  flo[nxt][0][0]=0;
  fhi[nxt][0][0]=0;
  swap(cur,nxt);
  for (int x=0;x<n;x++) {
    for (int state=0;state<m;state++) {
      for (int occ=0;occ<=maxocc;occ++) {
        flo[nxt][state][occ]=flo[cur][state][occ];
        fhi[nxt][state][occ]=fhi[cur][state][occ];
      }
    }
    for (int state=0;state<m;state++) {
      int newstate=dfa(state,s[x]);
      int addocc=0;
      if (newstate==m) {addocc=1; newstate=0;}
      //printf("state:%d c:%c newstate:%d addocc:%d\n",state,s[x],newstate,addocc);
      for (int occ=0;occ<=maxocc;occ++) {
        if (flo[cur][state][occ]==INF) continue;
        //printf("x:%d state:%d occ:%d lo:%d hi:%d\n",x,state,occ,flo[cur][state][occ],fhi[cur][state][occ]);
        chkmin(flo[nxt][newstate][occ+addocc], flo[cur][state][occ]+1);
        chkmax(fhi[nxt][newstate][occ+addocc], fhi[cur][state][occ]+1);
      }
    }
    swap(cur,nxt);
  }
  segn=n+1;
  for (int state=0;state<m;state++) {
    for (int occ=1;occ<=maxocc;occ++) {
      int l=flo[cur][state][occ],r=fhi[cur][state][occ];
      if (l<=r) modify(l,r,occ);
    }
  }
  push();
  for (int r=0;r<=n;r++) {
    printf("%d ",t[segn+n-r]);
  }
  printf("\n");
}