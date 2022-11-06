#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef __float128 ld;
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


const int maxn=1e5+2;
typedef pair<int,int> pii;
pii bestassign[maxn];
vector<pii> vadd[maxn];
vector<pii> vmul;
ll a[maxn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int k=readInt(),n=readInt(),m=readInt();
  for (int i=0;i<k;i++) {
    a[i]=readInt();
  }
  for (int i=1;i<=n;i++) {
    int t=readInt();
    int skill=readInt()-1;
    int b=readInt();
    if (t==1) {
      chkmax(bestassign[skill], MP(b,-i));
    }
    else if (t==2) vadd[skill].PB(MP(b,i));
    else {
      if (b>1) vmul.PB(MP(b,i));
    }
  }
  for (int skill=0;skill<k;skill++) {
    int gain=bestassign[skill].fst - a[skill];
    if (gain>0) {
      vadd[skill].PB(MP(gain, bestassign[skill].snd));
    }
  }
  sort(vmul.begin(),vmul.end(),greater<pii>());
  vector<pair<ld, int> > valladd;
  for (int skill=0;skill<k;skill++) {
    sort(vadd[skill].begin(),vadd[skill].end(),greater<pii>());
    int sz=vadd[skill].size();
    for (auto &w: vadd[skill]) {
      int add=w.fst,id=w.snd;
      ll numer=a[skill]+add;
      ll denom=a[skill];
      ld frac=((ld)denom)/((ld)numer);
      valladd.PB(MP(frac,id));
      a[skill]+=add;
    }
  }
  sort(valladd.begin(),valladd.end());
  int finaladdsteps=min(m,(int)(valladd.size()));
  {
    int addsteps=finaladdsteps;
    int prevmulsteps=min((int)(vmul.size()), m-addsteps);
    --addsteps;
    for (;addsteps>=0;addsteps--) {
      int mulsteps=min((int)(vmul.size()), m-addsteps);
      ld frac=valladd[addsteps].fst;
      //printf("va:%f\n",(double)valladd[addsteps].fst);
      if (mulsteps!=prevmulsteps) {
        frac=frac*vmul[mulsteps-1].fst;
        //printf("vm:%d\n",vmul[mulsteps-1].fst);
      }
      //printf("addsteps:%d mulsteps:%d frac:%f\n",addsteps,mulsteps,(double)frac);
      if (frac>=1) {
        finaladdsteps=addsteps;
      }
      prevmulsteps=mulsteps;
    }
  }
  {
    int addsteps=finaladdsteps;
    int mulsteps=min((int)(vmul.size()), m-addsteps);
    //printf("%d %d\n",addsteps,mulsteps);
    printf("%d\n",addsteps+mulsteps);
    vector<int> finalorder;
    for (int i=0;i<addsteps;i++) {
      finalorder.PB(valladd[i].snd);
    }
    sort(finalorder.begin(),finalorder.end());
    for (auto &w:finalorder) {
      printf("%d ",abs(w));
    }
    for (int i=0;i<mulsteps;i++) {
      printf("%d ",vmul[i].snd);
    }
    printf("\n");
  }
}