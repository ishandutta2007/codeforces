#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000009LL
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
set<int> pq;
const int mn=1e5+4;
vector<int> vparent[mn];
vector<int> vchild[mn];
void er(vector<int> &vec, int id) {
  vec.erase(std::remove(vec.begin(), vec.end(), id), vec.end());
}
int px[mn],py[mn];
typedef pair<int,int> pii;
map<pii,int> h;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m=readInt();
  for (int i=0;i<m;i++) {
    int x=readInt(),y=readInt();
    h[MP(x,y)]=i;
    px[i]=x;
    py[i]=y;
  }
  for (int i=0;i<m;i++) {
    int y=py[i];
    int x=px[i];
    if (y>0) {
      int ny=y-1;
      pii parent;
      for (int nx=x-1;nx<=x+1;nx++) {
        auto it=h.find(MP(nx,ny));
        if (it!=h.end()) {
          int parent=it->snd;
          int child=i;
          vparent[child].PB(parent);
          vchild[parent].PB(child);
        }
      }
    }
  }
  for (int i=0;i<m;i++) {
    bool crit=0;
    for (auto &child:vchild[i]) {
      if (vparent[child].size()==1) {
        crit=1;
      }
    }
    if (!crit) pq.insert(i);
  }
  ll ans=0;
  int who=0;
  while(!pq.empty()) {
    int id;
    if (who==0) id=*(pq.rbegin());
    else id=*(pq.begin());
    ans=((ans*m)+id)%MOD;
    pq.erase(id);
    for (auto &parent:vparent[id]) {
      er(vchild[parent],id);
      bool crit=0;
      for (auto &child:vchild[parent]) {
        if (vparent[child].size()==1) {
          crit=1;
        }
      }
      if (!crit) pq.insert(parent);
      else pq.erase(parent);
    }
    for (auto &child:vchild[id]) {
      er(vparent[child],id);
      if (vparent[child].size()==1) {
        int parent=vparent[child][0];
        pq.erase(parent);
      }
    }
    who^=1;
  }
  printf("%lld\n",ans);
}