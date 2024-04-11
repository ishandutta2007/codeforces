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
const ll INF=1e18;
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
const int MAXN=101;
ld inp[MAXN];
const ll MAXC=(MAXN*(MAXN-1))/2;
ld EPS = 1e-12;
ld x[MAXN];
ld y[MAXN];
ld p[MAXN];
ld s[MAXC];
pair<ld,ll> z[MAXN];
ld intersect(ld a,ld b,ld c,ld d) {
  if (fabs(a-c)<EPS) return a;
  return (d-b)/(a-c);
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  bool has1=0;
  for (int i=0;i<n;i++) {cin>>inp[i]; if (inp[i]==1) has1=1;}
  if (has1) {printf("1\n"); return 0;}
  for (ll i=0;i<n;i++) {
    ld m=inp[i];
    x[i]=m/(1-m);
    p[i]=(1-m);
    y[i]=log(p[i]);
  }
  ll sn=0;
  for (ll i=0;i<n;i++) {
    for (ll j=i+1;j<n;j++) {
      s[sn]=(intersect(y[i],x[i],y[j],x[j]));
      sn++;
    }
  }
  s[sn]=-INF; sn++;
  s[sn]=INF; sn++;
  s[sn]=0; sn++;
  sort(s,s+sn);
  ld ans=0;
  for (ll i=0;i<sn-1;i++) {
    ld r = (s[i]+s[i+1])/2;
    //printf("%f %f: %f\n",s[i],s[i+1],r);
    for (ll k=0;k<n;k++) {
      z[k]=MP(-(x[k]+r*y[k]),k);
    }
    sort(z,z+n);
    ld prob=1;
    ld sum=0;
    for (ll num=0;num<n;num++) {
      ll k=z[num].second;
      prob *= p[k];
      sum += x[k];
      //printf("prob:%f sum:%f")
      chkmax(ans,sum*prob);
    }
  }
  printf("%.12f\n",(double)ans);
}