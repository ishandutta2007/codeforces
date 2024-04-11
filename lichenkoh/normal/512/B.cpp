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
      if (((ll)p)*p>x) break;
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
const int maxn=302;
set<int> ps[maxn];
const int maxz=1<<10;
int f[maxz];
int l[maxn],c[maxn];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  sieve();
  int n=readInt();
  for (int i=0;i<n;i++) l[i]=readInt();
  for (int i=0;i<n;i++) c[i]=readInt();
  for (int x=0;x<n;x++) {
    auto fac=factorize(l[x]);
    for (auto &w:fac) ps[x].insert(w.fst);
  }
  int final=INF;
  for (int x=0;x<n;x++) {
    int zlim=1<<ps[x].size();
    fill(f,f+zlim,INF);
    f[0]=0;
    for (int y=0;y<n;y++) {
      if (y==x) continue;
      int sig=0;
      int pi=0;
      for (auto &p:ps[x]) {
        if (ps[y].find(p)==ps[y].end()) sig|=(1<<pi);
        ++pi;
      }
      for (int z=0;z<zlim;z++) {
        if (f[z]>=INF) continue;
        chkmin(f[z|sig],f[z]+c[y]);
      }
    }
    chkmin(final,f[zlim-1]+c[x]);
  }
  if (final>=INF) final=-1;
  printf("%d\n",final);
}