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
const ll INF=1e9;
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
const int mn=1e5+2;
int a[mn];
typedef vector<int> vi;
vector<int> getodd(vi &L, vi &R) {
  map<int,int> h;
  for (auto &w:L) h[w]++;
  for (auto &w:R) h[w]++;
  vector<int> vodd;
  for (auto &w:h) if (w.snd%2!=0) vodd.PB(w.fst);
  return vodd;
}

int help(vi &L, vi &R) {
  int lsz=L.size();
  assert(lsz==R.size());
  //for (auto &w:L) printf("%d ",w); printf(" L\n");
  //for (auto &w:R) printf("%d ",w); printf(" R\n");
  map<int,int> h;
  for (auto &w:L) h[w]++;
  for (auto &w:R) h[w]--;
  int excess=0;
  for (auto &w:h) {
    if (abs(w.snd)%2!=0) return INF;
    if (w.snd>0) excess+=w.snd;
  }
  if (excess<=0) {
    //printf("help:%d\n",0);
    return 0;
  }
  for (int i=0;i<lsz;i++) {
    int x=L[i];
    if (h[x]>=2) {
      h[x]-=2;
      excess-=2;
    }
    if (excess<=0) {
      //printf("help:%d\n",i+1);
      return i+1;
    }
  }
  //printf("inf\n");
  return INF;
}

int solve(vi &L, vi &R, int mid) {
  int final=help(L,R);
  if (final>0&&mid!=-1) final++;
  int lsz=L.size();
  if (mid!=-1) {
    vi vodd=getodd(L,R);
    if (vodd.size()==2&&(vodd[0]==mid||vodd[1]==mid)) {
      int other=-1;
      for (auto &w:vodd) if (w!=mid) other=w;
      for (int k=0;k<3;k++) {
        vi cL=L,cR=R;
        int minidx=-1;
        if (k==0) {
          for (int i=0;i<lsz;i++) if (cL[i]==other) {cL[i]=mid;minidx=i;break;}
        }
        else if (k==1) {
          for (int i=lsz-1;lsz>=0;lsz--) if (cL[i]==other) {cL[i]=mid;minidx=i;break;}
        }
        else {
          for (auto &w:cR) if (w==other) {w=mid;break;}
        }
        chkmin(final,max(minidx+1,help(cL,cR))+1);
      }
    }
  }
  return final;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=1;i<=n;i++) a[i]=readInt();
  int l=-1,r=-1;
  int l2=-1,r2=-1;
  for (int i=1;i<=n;i++) {
    if (i<n+1-i) {
      if (a[i]!=a[n+1-i]) {
        l=i;r=n+1-i; break;
      }
    }
  }
  int ml2;
  for (int i=1;i<=n;i++) {
    if (i<n+1-i) {
      if (a[i]!=a[n+1-i]) {
        l2=i;r2=n+1-i;
      }
      ml2=i;
    }
  }
  if (l==-1) {
    printf("%lld\n", ((ll)n*(ll)(n+1LL))/2);
    return 0;
  }
  int whole=0;
  ll final=0;
  {
    bool ok=1;
    map<int,int> h;
    for (int x=l;x<=l2;x++) h[a[x]]++;
    for (int x=r2;x<=r;x++) h[a[x]]--;
    for (auto &w:h) if (w.snd!=0) ok=0;
    //printf("%d %d %d. %d\n",l,l2,ml2,ok);
    if (ok) {
      //printf("adding 2\n");
      final+=2LL*(ml2-l2+1)*l;
    }
  }
  for (int t=0;t<2;t++) {
    vector<int> L,R;
    int midx=-1;
    if (n%2==1) {
      int mid=(n+1)/2;
      for (int x=mid-1;x>=l;x--) L.PB(a[x]);
      for (int x=mid+1;x<=r;x++) R.PB(a[x]);
      midx=a[mid];
    }
    else {
      for (int x=n/2;x>=l;x--) L.PB(a[x]);
      for (int x=(n/2)+1;x<=r;x++) R.PB(a[x]);
    }
    int needleft=max(1,solve(L,R,midx));
    //printf("nl:%d\n",needleft);
    if (needleft<INF) {
      whole=1;
      int choices=L.size()-needleft + ((midx!=-1)?1:0);
      final+=1LL*(ll)choices*(ll)(l);
      //printf("add:%lld\n",(ll)choices*(ll)(l));
    }
    reverse(a+1,a+n+1);
  }
  if (whole) {
    final+=1LL*(ll)(l)*(ll)(l);
  }
  printf("%lld\n",final);
}