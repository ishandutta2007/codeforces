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
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define DEBUG_CAT
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
/*int mex(vector<int> &v) {
  sort(v.begin(),v.end());
  int ans=1;
  for (auto &w:v) {
    if (w==ans)ans++;
  }
  return ans;
}
int dp[102];
int nim(int n) {
  if (n==0) return 0;
  if (dp[n]!=-1) return dp[n];
  vector<int> cand;
  for (int l=0;l<=n;l++) {
    for (int r=0;r<=n;r++) {
      if (l+r<n) {
        int got=nim(l)^nim(r);
        //printf("n:%d l:%d r:%d got:%d\n",n,l,r,got);
        cand.PB(got);
      }
    }
  }
  int ans=mex(cand);
  //printf("ans:%d\n",ans);
  return dp[n]=ans;
}*/
int nim(int x) {
  return x;
}
map<int, map<int,int> > g[2];
map<int, vector<pii> > z[2];
int lim[2];
map<int, pii> h;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  lim[0]=rint(),lim[1]=rint(); int k=rint();
  for (int i=0;i<k;i++) {
    int xb=rint(),yb=rint(),xe=rint(),ye=rint();
    if (xb==xe) {
      if (yb>ye) swap(yb,ye);
      g[0][xb][yb]++;
      g[0][xb][ye]--;
    }
    else {
      if (xb>xe) swap(xb,xe);
      g[1][yb][xb]++;
      g[1][yb][xe]--;
    }
  }
  int nimber=0;
  for (int t=0;t<2;t++) for (auto &o:g[t]) {
    int cnt=0;
    int last=0;
    int sumlen=0;
    for (auto &w:o.snd) {
      int oldcnt=cnt;
      int pos=w.fst;
      cnt+=w.snd;
      if (oldcnt==0&&cnt>0) {
        int len=pos-last;
        if (len) {
          //printf("t:%d o.fst:%d pos:%d last:%d len:%d\n",t,o.fst,pos,last,len);
          z[t][o.fst].PB(MP(last,pos));
          sumlen+=len;
        }
      }
      if (oldcnt>0&&cnt==0) {
        last=pos;
      }
    }
    {
      int pos=lim[t^1];
      int len=pos-last;
      if (len) {
        //printf("t:%d o.fst:%d pos:%d last:%d len:%d\n",t,o.fst,pos,last,len);
          z[t][o.fst].PB(MP(last,pos));
          sumlen+=len;
      }
    }
    h[sumlen]=MP(t,o.fst);
    nimber^=sumlen;
  }
  for (int t=0;t<2;t++) {
    int unseen=lim[t]-1-g[t].size();
    int num=lim[t^1];
    //printf("t:%d unseen:%d num:%d\n",t,unseen,num);
    if (unseen&1) nimber^=num;
    if (unseen>0) {
      int have=-1;
      int want=1;
      for (auto &w:g[t]) {
        if (want!=w.fst) {
          have=want;
          break;
        }
        want++;
      }
      if (have==-1) have=lim[t]-1;
      assert(g[t].count(have)==0);
      h[num]=MP(t,have);
      z[t][have].PB(MP(0,lim[t^1]));
    }
  }
  //printf("nimber:%d\n",nimber);
  if (nimber==0) {
    printf("SECOND\n");
  }
  else {
    printf("FIRST\n");
    for (auto w:h) {
      int len=w.fst;
      int go=len^nimber;
      if (go>len) continue;
      int rm=len-go;
      int t=w.snd.fst;
      int o=w.snd.snd;
      int solution=-1;
      for (auto &q:z[t][o]) {
        int start=q.fst,end=q.snd;
        if (rm<=end-start) {solution=start+rm; break;}
        else rm-=end-start;
      }
      assert(solution!=-1);
      if (t==0) {
        printf("%d %d %d %d\n",o,0,o,solution);
      }
      else {
        printf("%d %d %d %d\n",0,o,solution,o);
      }
      return 0;
    }
  }
}