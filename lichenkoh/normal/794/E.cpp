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
//const int INF=1e18;
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
const int mn=3e5+6;

int t[2][mn*2];
int segn;
void modify(int *t, int l, int r, int value) {
  int n=segn;
  r++;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) chkmax(t[l++],value);
    if (r&1) chkmax(t[--r],value);
  }
}
void push(int *t) {
  int n=segn;
  for (int i = 1; i < n; ++i) {
    chkmax(t[i<<1], t[i]);
    chkmax(t[i<<1|1], t[i]);
    //t[i] = 0;
  }
}

int p[mn];
int pl[mn],pr[mn];
int ffind(int x) {
  if (p[x] != x) {
    p[x] = ffind(p[x]);
  }
  return p[x];
}
void funion(int x, int y) {
  if (rand()&1) swap(x,y); 
  int xr = ffind(x);
  int yr = ffind(y);
  // Merge xr into yr
  p[xr] = yr;
  chkmin(pl[yr],pl[xr]);
  chkmax(pr[yr],pr[xr]);
}
bitset<mn> tick;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  vector<pair<int,int> > v;
  int big=0;
  for (int x=1;x<=n;x++) {
    int val=readInt();
    v.PB(MP(-val,x));
    chkmax(big,val);
  }
  sort(v.begin(),v.end());
  for (int x=0;x<=n+1;x++) {
    p[x]=pl[x]=pr[x]=x;
  }
  segn=(n/2)+2;
  for (auto &w:v) {
    int val=-w.fst,x=w.snd;
    tick[x]=true;
    if (tick[x-1]) funion(x-1,x);
    if (tick[x+1]) funion(x,x+1);
    int vl[2],vr[2];
    vl[0]=pl[ffind(x)];
    vl[1]=pl[ffind(vl[0]-1)];
    vr[0]=pr[ffind(x)];
    vr[1]=pr[ffind(vr[0]+1)];
    for (int ls=0;ls<2;ls++) for (int rs=0;rs<2;rs++) {
      if (ls+rs<=1) {
        int L=vl[ls],R=vr[rs];
        if (R-L+1<3&&ls+rs>0) continue;
        int min_need=(ls+rs==0)?1:3;
        for (int need=min_need;need<=min_need+1;need++) {
          vector<int> vl;
          vl.PB(L);
          vl.PB(R-need+1);
          vl.PB((n-need)/2 - 1);
          vl.PB((n-need)/2);
          vl.PB((n-need)/2 + 1);
          for (auto &l: vl) {
            int r=l+need-1;
            if (!(L<=l&&l<=r&&r<=R)) continue;
            int lspace=l-1,rspace=n-r;
            int rm_small=n-(2*min(lspace,rspace)+r-l+1)-1;
            chkmax(rm_small,0);
            int rm_large=n-(r-l+1)-1;
            chkmax(rm_large,0);
            int mod=rm_large%2;
            if (rm_small%2!=mod) rm_small++;
            //printf("val:%d l:%d r:%d lspace:%d rspace:%d rm_small:%d rm_large:%d\n",val,l,r,lspace,rspace,rm_small,rm_large);
            if (rm_small<=rm_large) {
              modify(t[mod],rm_small/2,rm_large/2,val);
            }
          }
        }
        //chkmax(vans[rm],val);
      }
    }
  }
  push(t[0]);push(t[1]);
  for (int rm=0;rm<n-1;rm++) printf("%d ",t[rm%2][segn+rm/2]);
  printf("%d\n",big);
}