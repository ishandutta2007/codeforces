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
const ll INF=1e9+18;
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
const int mn=124;
const int mp=5+1;
int a[mn][mp];
int cnt[mp];
int ps[mp];
int ptwo[30];
int score(int i) {
  int ans=0;
  for (int p=0;p<5;p++) {
    if (a[i][p]!=-1) {
      int m=a[i][p];
      int s=ps[p];
      int maxp=500*(s+1);
      int deduct=2*(s+1);
      int now=maxp-deduct*m;
      ans+=now;
    }
  }
  return ans;
}
int lo(int s, int y) {
  if (s==5) return 0;
  int d=ptwo[s+1];
  int ans=(y/d)+1;
  //assert(y<ans*d);
  //assert(!(y<(ans-1)*d));
  return ans;
}
int hi(int s, int y) {
  int d=ptwo[s];
  return y/d;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int i=0;i<n;i++) {
    for (int p=0;p<5;p++) a[i][p]=readInt();
  }
  for (int i=0;i<n;i++) for (int p=0;p<5;p++) if (a[i][p]!=-1) cnt[p]++;
  int zlim=1;
  for (int i=0;i<5;i++) zlim*=6;
  ptwo[0]=1;
  for (int i=1;i<30;i++) ptwo[i]=2*ptwo[i-1];
  int final=INF;
  for (int z=0;z<zlim;z++) {
    int tmp=z;
    for (int p=0;p<5;p++) {ps[p]=tmp%6; tmp/=6;}
    if (score(0)<=score(1)) continue;
    int ylim=33*120;
    for (int y=n;y<=ylim;y++) {
      bool ok=true;
      for (int p=0;p<5;p++) {
        int s=ps[p];
        int l=lo(s,y);
        int h=hi(s,y);
        if (l>h) {ok=false; break;}
        if (a[0][p]==-1) {
          int c=cnt[p];
          if (!(l<=c&&c<=h)) {
            ok=false; break;
          }
        }
        else {
          int canadd=y-n;
          int needadd=max(0,l-cnt[p]);
          int c=min(needadd,canadd)+cnt[p];
          if (!(l<=c&&c<=h)) {
            ok=false; break;
          }
        }
      }
      if (ok) {
        chkmin(final,y-n);
        break;
      }
    }
  }
  if (final==INF) printf("-1\n");
  else printf("%d\n",final);
}