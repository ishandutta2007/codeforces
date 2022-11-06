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
char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}
const int mn=2e5+4;
int a[mn];
map<int,int> h;
inline void add(int x) {
  //printf("Add %d\n",x);
  auto it=h.find(x);
  if (it==h.end()) h[x]=1;
  else if (it->snd==-1) h.erase(it);
  else it->snd++;
}
inline void rm(int x) {
  //printf("Rm %d\n",x);
  auto it=h.find(x);
  if (it==h.end()) h[x]=-1;
  else if (it->snd==1) h.erase(it);
  else it->snd--;
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),p=readInt();
  for (int i=0;i<n;i++) a[i]=readInt();
  for (int i=0;i<m;i++) {
    h[readInt()]++;
  }
  //map<int,int> oh=h;
  vector<int> final;
  for (int pmod=0;pmod<p;pmod++) {
    //printf("pmod:%d\n",pmod);
    int q;
    for (q=pmod;q<n;q+=p) {
      //printf("q:%d\n",q);
      rm(a[q]);
      ll last=q-p*(ll)m;
      if (last>=0) add(a[last]);
      if (h.size()==0) final.PB(last+p);
    }
    //for (auto &w:h) printf("%d:%d\n",w.fst,w.snd);
    for (int i=0;i<m;i++) {
      q-=p;
      if (q<0) break;
      //printf("Rq:%d\n",q);
      add(a[q]);
    }
    //assert(h==oh);
  }
  sort(final.begin(),final.end());
  printf("%d\n",(int)final.size());
  for (auto &w:final) printf("%d ",w+1);
  printf("\n");
}