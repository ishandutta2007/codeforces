#include <bits/stdc++.h>
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
const ll INF=1e18;
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
const ll mn=1e5+2;
const ll maxd=62;
vector<ll> urg;
vector<ll> a;
vector<bitset<mn> > b;
ll gauss() {
  //O(alen * sizeof(int)) Binary gaussian elimination.
  //Returns the size of the basis.
  //Set maxd = sizeof(int)
  ll alen=a.size();
  ll st=0;
  for (ll di=0;di<urg.size();di++) {
    ll d=urg[di];
    ll msk=1LL<<d;
    for (ll x=st;x<alen;x++) {
      if (a[x]&msk) {
        if (x!=st) {
          swap(a[x],a[st]);
          swap(b[x],b[st]);
        }
        for (ll y=st+1;y<alen;y++) if (a[y]&msk) {
          //printf("a[y]:%lld a[st]:%lld\n",a[y],a[st]);
          a[y]^=a[st];
          b[y]^=b[st];
        }
        st++;
        break;
      }
    }
  }
  return st;
}

ll getleft(ll x) {
  for (auto &y:a) {
    ll msk;
    for (auto &d:urg) {
      msk=1LL<<d;
      if (msk&y) break;
    }
    //printf("bit:%d msk:%lld x:%lld y:%lld\n",bit,msk,x,y);
    if (msk&x) {
      x^=y;
    }
  }
  return x;
}

bool inbasis(ll x) {
  for (auto &y:a) {
    ll msk;
    for (auto &d:urg) {
      msk=1LL<<d;
      if (msk&y) break;
    }
    if (msk&x) {
      x^=y;
    }
  }
  return x==0;
}

bitset<mn> vans;
void getbasis(ll x) {
  ll alen=a.size();
  for (ll i=0;i<alen;i++) {
    ll y=a[i];
    ll msk;
    for (auto &d:urg) {
      msk=1LL<<d;
      if (msk&y) break;
    }
    if (msk&x) {
      x^=y;
      vans^=b[i];
    }
  }
}

ll inp[mn];
ll vcnt[mn];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n=rint();
  for (ll i=0;i<n;i++) inp[i]=rlong();
  for (ll d=0;d<maxd;d++) {
    ll cnt=0;
    ll msk=1LL<<d;
    for (ll i=0;i<n;i++) {
      if (inp[i]&msk) cnt++;
    }
    vcnt[d]=cnt;
  }
  for (ll d=maxd-1;d>=0;d--) {
    ll cnt=vcnt[d];
    if (cnt==0) continue;
    if (0==(cnt%2)) {
      //printf("d0:%d\n",d);
      urg.PB(d);
    }
  }
  for (ll d=maxd-1;d>=0;d--) {
    ll cnt=vcnt[d];
    if (cnt==0) continue;
    if (1==(cnt%2)) {
      //printf("d1:%d\n",d);
      urg.PB(d);
    }
  }
  ll xorall=0;
  for (ll i=0;i<n;i++) xorall^=inp[i];
  for (ll i=0;i<n;i++) {
    ll x=inp[i];
    if (inbasis(x)) continue;
    a.PB(x);
    ll bsz=b.size();
    b.resize(bsz+1);
    b[bsz][i]=true;
    gauss();
  }
  //for (auto &w:a) {
  //  printf("%lld\n",w);
  //}
  ll her=0;
  ll care=0;
  for (auto &w:urg) {
    ll d=w;
    ll msk=1LL<<d;
    care|=msk;
    ll lft=getleft(her|msk);
    //printf("lft:%lld care:%lld d:%d her:%lld msk:%lld\n",lft,care,d,her,msk);
    if (0==(lft&care)) {
      her|=msk;
    }
  }
  her=getleft(her)|her;
  ll my=xorall^her;
  //printf("my:%lld her:%lld\n",my,her);
  assert(my<=her);
  assert(inbasis(her));
  getbasis(her);
  ll gother=0;
  for (ll i=0;i<n;i++) {
    if (vans[i]) {
      printf("2 ");
      gother^=inp[i];
    }
    else {
      printf("1 ");
    }
  }
  assert(gother==her);
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