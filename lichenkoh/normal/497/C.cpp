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
const int mn=1e5+4;
int vk[mn];
int vd[mn];
int vans[mn];
vector<pair<pair<int,int>,int> > vp;
map<int,vector<int> > hactor;
map<int,queue<int> > h;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  for (int part_id=1;part_id<=n;part_id++) {
    int a=readInt(),b=readInt();
    vp.PB(MP(MP(a,b),part_id));
  }
  sort(vp.begin(),vp.end());
  int m=readInt();
  for (int actid=1;actid<=m;actid++) {
    int c=readInt();vd[actid]=readInt(),vk[actid]=readInt();
    hactor[c].PB(actid);
  }
  auto hait=hactor.begin();
  for (auto &p:vp) {
    int a=p.fst.fst,b=p.fst.snd,partid=p.snd;
    while(hait!=hactor.end()&&hait->fst<=a) {
      for (auto &actid:hait->snd) {
        int d=vd[actid];
        h[d].push(actid);
      }
      ++hait;
    }
    auto it=h.lower_bound(b);
    if (it==h.end()||it->snd.empty()) {
      printf("NO\n"); return 0;
    }
    int actid=it->snd.front();
    vans[partid]=actid;
    vk[actid]--;
    if (vk[actid]==0) {
      it->snd.pop();
      if (it->snd.empty()) {
        h.erase(it);
      }
    }
  }
  printf("YES\n");
  for (int partid=1;partid<=n;partid++) {
    printf("%d ",vans[partid]);
  }
  printf("\n");
}