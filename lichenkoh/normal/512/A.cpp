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
const int mc=26;
bitset<mc> g[mc];
string s[101];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n;
  cin>>n;
  for (int i=0;i<n;i++) cin>>s[i];
  bool fok=1;
  for (int x=0;x<n;x++) for (int y=x+1;y<n;y++) {
    int plim=min(s[x].length(),s[y].length());
    bool same=1;
    for (int p=0;p<plim;p++) {
      int a=s[x][p]-'a',b=s[y][p]-'a';
      if (a!=b) {
        g[b][a]=1;
        same=0;
        break;
      }
    }
    if (same) {
      if (s[x].length()>s[y].length()) {
        fok=false;
      }
    }
  }
  for (int x=0;x<mc;x++) g[x][x]=1;
  for (int z=0;z<mc;z++) for (int x=0;x<mc;x++) for (int y=0;y<mc;y++) {
    if (g[x][z]&&g[z][y]) g[x][y]=1;
  }
  vector<char> vans;
  bitset<mc> left; left.set();
  for (int cnt=0;cnt<mc;cnt++) {
    bool found=0;
    for (int x=0;x<mc;x++) {
      if (left[x]==1&&(g[x]&left).count()==1) {
        left[x]=0;
        vans.PB(x+'a');
        //printf("cnt:%d x:%c\n",cnt,(char)(x+'a'));
        found=1;
        break;
      }
    }
    if (!found) {
      //for (int x=0;x<mc;x++) {
      //  if (left[x]==1) printf("%c\n",(char)(x+'a'));
      //}
      fok=0;
      break;
    }
  }
  if (!fok) printf("Impossible\n");
  else {
    for (auto &w:vans) printf("%c",w); printf("\n");
  }
}