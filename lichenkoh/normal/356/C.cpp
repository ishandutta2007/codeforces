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
const int mn=40;
typedef struct SS {
  int a[5];
} S;
int dist[mn][mn][mn][mn];
inline int getdist(S s) {
  return dist[s.a[1]][s.a[2]][s.a[3]][s.a[4]];
}
inline void chdist(S s, int val) {
  dist[s.a[1]][s.a[2]][s.a[3]][s.a[4]]=val;
}
inline bool valid(S s) {
  for (int c=1;c<=4;c++) {
    int x=s.a[c];
    if (!(0<=x&&x<mn)) return false;
  }
  return true;
}

void bf(S inps, int addi) {
  memset(dist,-1,sizeof dist);
  queue<S> q;
  chdist(inps,0);
  q.push(inps);
  while(!q.empty()) {
    auto got=q.front(); q.pop();
    int nd=getdist(got);
    if (got.a[1]+got.a[2]==0) {
      printf("%d\n",nd+addi);
      exit(0);
    }
    ++nd;
    for (int s=1;s<=4;s++) {
      for (int t=0;t<=3;t++) {
        S ngot=got;
        ngot.a[s]--; ngot.a[s-1]++;
        ngot.a[t]--; ngot.a[t+1]++;
        if (!valid(ngot)) continue;
        int od=getdist(ngot);
        if (od==-1||nd<od) {
          chdist(ngot,nd);
          assert(getdist(ngot)==nd);
          q.push(ngot);
        }
      }
    }
  }
  printf("-1\n");
  exit(0);
}
void cvalid(S &state) {
  for (int c=0;c<=4;c++) {
    int x=state.a[c];
    assert(x>=0);
  }
}
bool done(S &state) {
  return state.a[1]+state.a[2]==0;
}
int addi=0;
void trans(S &state, int s, int t, int cnt) {
  //printf("s:%d t:%d cnt:%d\n",s,t,cnt);
  addi+=cnt;
  assert(s>=1&&t<=3);
  state.a[s]-=cnt; state.a[s-1]+=cnt;
  state.a[t]-=cnt; state.a[t+1]+=cnt;
  cvalid(state);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=rint();
  S inps; for (int c=0;c<5;c++) inps.a[c]=0;
  int nonz=0;
  for (int i=0;i<n;i++) {
    int x=rint();
    inps.a[x]++;
    if (x!=0) nonz++;
  }
  //for (int c=1;c<=4;c++) printf("%d, ",inps.a[c]); printf("\n");
  if (nonz<mn) {bf(inps,0); return 0;}
  trans(inps, 1,2,min(inps.a[1],inps.a[2]));
  if (inps.a[2]) {
    assert(inps.a[1]==0);
    int take=inps.a[2]/3;
    trans(inps,2,2,take);
    trans(inps,1,2,take);
  }
  else if (inps.a[1]) {
    int take=inps.a[1]/3;
    trans(inps,1,1,take);
    trans(inps,1,2,take);
  }
  assert(inps.a[1]<=(mn-1)/4);
  assert(inps.a[2]<=(mn-1)/4);
  chkmin(inps.a[3],(mn-1)/4);
  chkmin(inps.a[4],(mn-1)/4);
  //for (int c=1;c<=4;c++) printf("%d ",inps.a[c]); printf("\n");
  bf(inps, addi);
}