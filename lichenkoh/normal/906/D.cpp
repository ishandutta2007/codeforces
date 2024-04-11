#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
//#include <quadmath>
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
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();

class Factor {
  static const int MAXN=1e5+4;
  static const int MAXP=MAXN;
public:
  bool sieve_array[MAXP+1];
  int ap[MAXP+1];
  vector<int> gpv;

  void sieve() {
    for (int i = 0; i <= MAXP; i++) {
      sieve_array[i] = true;
      ap[i]=1<<30;
    }
    sieve_array[0] = false; sieve_array[1] = false;
    int lim = (int)(ceil(sqrt(MAXP)))+2;
    for (int i = 2; i <= lim; i++) {
      if(sieve_array[i]) {
        for (int j = i*i; j <= MAXP; j+=i) {
          sieve_array[j] = false;
          ap[j]=i;
        }
      }
    }
    for (int i = 2; i <= MAXP; i++) {
      if(sieve_array[i]) {
        gpv.PB(i);
        ap[i]=i;
      }
    }
  }

  pair<int,int> factorize_dest[500];
  int factorize_tmp[500];
  int factorize(int x) {
    const int power=1;
    int tsz=0;
    while(x>=MAXP) {
      bool found=false;
      for (auto &p:gpv) {
        if (p*(ll)p>x) break;
        while ((x%p)==0) {
          //printf("x:%lld p:%d\n",x,p);
          x/=p;
          factorize_tmp[tsz++]=p;
          found=true;
        }
      }
      if (x<MAXP) break;
      if (!found) break;
    }
    if (x<MAXP) {
      while(x>1) {
        int p=ap[x];
        x/=p;
        factorize_tmp[tsz++]=p;
      }
    }
    if (x>1) factorize_tmp[tsz++]=x;
    sort(factorize_tmp,factorize_tmp+tsz);
    int didx=0;
    for (int tidx=0;tidx<tsz;tidx++) {
      int p=factorize_tmp[tidx];
      if (tidx==0||p!=factorize_tmp[tidx-1]) {
        factorize_dest[didx++]=MP(p,power);
      }
      else factorize_dest[didx-1].snd+=power;
    }
    return didx;
  }
  map<int,int> factorize_map(int x) {
    int fsz=factorize(x);
    map<int,int> hans;
    for (int i=0;i<fsz;i++) {
      hans[factorize_dest[i].fst]=factorize_dest[i].snd;
    }
    return hans;
  }
  int tot(int x, int facsz=-1) {
    if (x==1) return 1;
    if (facsz==-1) facsz=factorize(x);
    int ans=1;
    for (int i=0;i<facsz;i++) {
      auto got=factorize_dest[i];
      int p=got.fst,k=got.snd;
      if (k>0) {
        for (int i=0;i<k-1;i++) {
          ans*=p;
        }
        ans*=(p-1);
      }
    }
    return ans;
  }
};

Factor ff;

int mod_pow(int a, int n, int mod) {int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
inline int ovfmul(int x, int y) {
  int dest;
  if (__builtin_smul_overflow(x,y,&dest)) return INF;
  return dest;
}
int int_pow(int a, int n) {
  int ret = 1; ll p = a;
  while (n) {
    if (n & 1) {
      ret = ovfmul(ret,p);
    }
    p = ovfmul(p,p);
    n >>= 1;
  }
  return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

int garner(vector<pii> mr, int mod){
  mr.emplace_back(mod, 0);

  vector<int> coffs(mr.size(), 1);
  vector<int> constants(mr.size(), 0);
  for (int i=0;i<mr.size();i++){
    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first)
    int v = ((mr[i].second - constants[i]) * (ll)mod_inv<int>(coffs[i], mr[i].first)) % mr[i].first;
    if (v < 0) v += mr[i].first;

    for (int j = i + 1; j < mr.size(); j++) {
      constants[j]= (constants[j]+coffs[j] * (ll)v) % mr[j].first;
      coffs[j]=(coffs[j]*(ll)mr[i].first)%mr[j].first;
    }
  }

  return constants[mr.size() - 1];
}

const int mn=100002;
int inp[mn];
int a[mn];
int o2n[mn];
vector<pair<int,vector<pair<int,pii> > > > vmod;

int vdumb[256];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  ff.sieve();
  int n=rint(); int mod=rint();
  for (int i=1;i<=n;i++) inp[i]=rint();
  int asz=1;
  {
    for (int i=1;i<=n;i++) {
      int x=inp[i];
      if (x==1&&a[asz-1]==1) {
        o2n[i]=asz-1;
      }
      else {
        a[asz]=x;
        o2n[i]=asz;
        asz++;
      }
    }
  }
  --asz;
  int omod=mod;
  while(mod!=1) {
    int fsz=ff.factorize(mod);
    vector<pair<int,pii> > vp;
    for (int i=0;i<fsz;i++) {
      int ppow=1,p=ff.factorize_dest[i].fst,pe=ff.factorize_dest[i].snd;
      for (int j=0;j<pe;j++) {
        ppow*=p;
      }
      vp.PB(MP(p,MP(pe,ppow)));
    }
    vmod.PB(MP(mod,vp));
    dbg("mod:%d\n",mod);
    mod=ff.tot(mod,fsz);
  }
  int q=rint();
  int vmsz=vmod.size();
  for (int i=0;i<q;i++) {
    int oldl=rint(),oldr=rint();
    if (omod==1) {
      printf("0\n"); continue;
    }
    int l=o2n[oldl],r=o2n[oldr];
    int origdiff=r-l;
    {
      int dumbdiff=min(origdiff, vmsz+9);
      int dumb=a[l+dumbdiff];
      vdumb[dumbdiff]=dumb;
      for (int x=dumbdiff-1;x>=0;x--) {
        dumb=int_pow(a[l+x],dumb);
        vdumb[x]=dumb;
      }
    }

    int diff=min(origdiff,vmsz-1);
    int ans=a[l+diff]%vmod[diff].fst;
    //dbg("ans:%d  %d%%%d\n",ans,a[l+diff],vmod[diff]);
    for (int x=diff-1;x>=0;x--) {
      int prevans=ans;
      if (vdumb[x+1]<INF) {
        ans=mod_pow(a[l+x],vdumb[x+1],vmod[x].fst);
      }
      else {
        vector<pii> mr;
        auto &vp=vmod[x].snd;
        for (auto ppe:vp) {
          int base=a[l+x];
          int p=ppe.fst,modpe=ppe.snd.fst,modppow=ppe.snd.snd;
          int residue;
          if (base%p) {
            residue=mod_pow(base,prevans,modppow);
          }
          else {
            residue=0;
          }
          mr.PB(MP(modppow, residue));
        }
        int nextgot=garner(mr, vmod[x].fst);
        ans=nextgot;
      }
      //dbg("ans:%d  %d^%d%%%d\n",ans,a[l+x],vdumb[x+1],vmod[x]);
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