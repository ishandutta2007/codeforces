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
int rint();char rch();long long rlong();
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}

const int MAXN=1e5+4;
bitset<MAXN+1> sieve_array;
vector<int> bp, sp;
int sqrtn;

void sieve(int n) {
  sieve_array.set();
  sieve_array[0] = false; sieve_array[1] = false;
  int lim = (int)(ceil(sqrt(n)))+2;
  for (int i = 2; i <= lim; i++) {
    if(sieve_array[i]) {
      for (int j = i*i; j <= n; j+=i) {
        sieve_array[j] = false;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if(sieve_array[i]) {
      ll x=i;
      while(x <= n) {
        if (x <= sqrtn) {
          sp.PB(x);
        } else {
          bp.PB(x);
        }
        x*=i;
      }
    }
  }
  sort(bp.begin(),bp.end());
  sort(sp.begin(),sp.end()); reverse(sp.begin(),sp.end());
}

bitset<MAXN> a;
int ga;

void markfalse(int x) {
  if (a[x]) {
    a[x]=false;
    ga--;
  }
}

int aska(int x) {
  printf("A %d\n",x); fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

int dob(int x) {
  printf("B %d\n",x); fflush(stdout);
  int ans; scanf("%d",&ans);
  return ans;
}

ll lcm(ll x, ll y) {
  return (x*y)/__gcd(x,y);
}

int main() 
{
  int n;
  scanf("%d",&n);
  sqrtn=round(floor(sqrt((ld)n)));
  sieve(n);
  a.set();
  ga=n;
  int r=((int)(bp.size())) - 1;

  ll final=1;
  while(r>=0) {
    int mid=r/2;
    for (int x=mid;x<=r;x++) {
      int p=bp[x];
      dob(p);
      for (int y=p;y<=n;y+=p) markfalse(y);
    }
    int got1=aska(1);
    assert(got1 >= ga);
    if (got1 > ga) {
      for (int x=mid;x<=r;x++) {
        int p=bp[x];
        int gotp=aska(p);
        assert(0<=gotp);
        assert(gotp<=1);
        if (gotp) {
          final=lcm(final,p);
          break;
        }
      }
    }
    assert(final>=1);
    if (final>1) break;
    r=mid-1;
  }
  for (auto p: sp) {
    if (final%p != 0 && lcm(final,p) <= n) {
      dob(p);
      if (aska(p)) {
        final=lcm(final,p);
      }
    }
  }
  printf("C %lld\n",final);
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