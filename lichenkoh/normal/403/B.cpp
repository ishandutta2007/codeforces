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
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
//#define DEBUG_CAT
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


const int MAXN=1e6+4;
const int MAXP=MAXN;
bool sieve_array[MAXP+1];
int sp[MAXP+1];
vector<int> gpv;

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
      gpv.PB(i);
      chkmin(sp[i],i);
    }
  }
}
map<int,int> factorize(int x) {
  map<int,int> h;
  while(x>=MAXP) {
    bool found=false;
    for (auto &p:gpv) {
      if ((int)p*(int)p>x) break;
      int cnt=0;
      while ((x%p)==0) {
        x/=p;
        cnt++;
      }
      if (cnt>0) {
        h[p]+=cnt;
        found=true;
      }
    }
    if (x<MAXP) break;
    if (!found) break;
  }
  if (x<MAXP) {
    while(x>1) {
    int p=sp[x];
    x/=p;
    h[p]++;
    }
  }
  if (x>1) h[x]++;
  return h;
}
const int mp=5005;
const int mn=5005;
vector<int> i2p;
int i2s[mn];
map<int,int> p2i;
int a[mn];
int vc[mp][mn];
map<int,int> h[mn];
int t[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();  
  int n=readInt(),m=readInt();
  for (int i=0;i<n;i++) a[i]=readInt();
  set<int> b;
  for (int i=0;i<m;i++) b.insert(readInt());
  for (int i=0;i<n;i++) {
    h[i]=factorize(a[i]);
  }
  {int idx=0;
  for (auto &w:h[0]) {
    int p=w.fst,c=w.snd;
    {
      i2p.PB(p);
      p2i[p]=idx;
      if (b.count(p)) i2s[idx]=-1;
      else i2s[idx]=1;
      idx++;
    }
  }}
  int ans=0;
  for (int i=0;i<n;i++) {
    for (auto &w:h[i]) {
      int p=w.fst,c=w.snd;
      auto it=p2i.find(p);
      if (it!=p2i.end()) {
        vc[i][it->snd]=c;
      }
      if (b.count(p)) {
        dbg("p:%d c:%d\n",p,-c);
        ans-=c;
      }
      else {
        dbg("p:%d c:%d\n",p,c);
        ans+=c;
      }
    }
  }
  int h0s=h[0].size();
  for (int x=n-1;x>=0;x--) {
    for (int z=0;z<h0s;z++) t[z]=vc[0][z];
    for (int y=1;y<=x;y++) {
      for (int z=0;z<h0s;z++) chkmin(t[z],vc[y][z]);
    }
    int d=0;
    for (int z=0;z<h0s;z++) d-=t[z]*i2s[z];
    d*=(x+1);
    dbg("x:%d d:%d\n",x,d);
    if (d>0) {
      ans+=d;
      for (int y=0;y<=x;y++) {
        for (int z=0;z<h0s;z++) {
          vc[y][z]-=t[z];
        }
      }
    }
  }
  printf("%d\n",ans);
}