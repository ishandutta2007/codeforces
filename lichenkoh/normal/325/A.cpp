#include "bits/stdc++.h"
#include <assert.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef
tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else
#define dbg(...)   /****nothing****/
#endif
//int rint();char rch();long long rlong();

int v[5][2][2];
int ex[2][2];
int diff[2];
set<int> s[2];
map<int,int> v2i[2],i2v[2];
bool solve() {
  int n; cin>>n;
  for (int c=0;c<2;c++) ex[c][0]=1e9;
  for (int i=0;i<n;i++) {
    for (int h=0;h<2;h++) {
      for (int c=0;c<2;c++) {
        int got; cin>>got;
        got*=2;
        //printf("%d ",got);
        v[i][c][h]=got;
        chkmin(ex[c][0],got);
        chkmax(ex[c][1],got);
        s[c].insert(got);
      }
    }
   // printf("\n");
    for (int c=0;c<2;c++) {
      assert(v[i][c][1]>=v[i][c][0]);
    }
  }
  for (int c=0;c<2;c++) {
    diff[c]=ex[c][1]-ex[c][0];
    assert(diff[c]>=0);
  }
  //printf("%d %d\n",diff[0],diff[1]);
  if (diff[0]!=diff[1]) return false;
  for (auto &xx:s[0]) {
    for (auto &yy:s[1]) {
      for (int x=xx-1;x<=xx+1;x++) {
        for (int y=yy-1;y<=yy+1;y++) {
          if (ex[0][0]<=x&&x<=ex[0][1]) {
            if (ex[1][0]<=y&&y<=ex[1][1]) {
              bool ok=0;
              for (int i=0;i<n;i++) {
                if (v[i][0][0]<=x&&x<=v[i][0][1]) {
                  if (v[i][1][0]<=y&&y<=v[i][1][1]) {
                    ok=1;
                    break;
                  }
                }
              }
              //printf("x:%d y:%d\n",x,y);
              if (!ok) return false;
            }
          }
        }
      }
    }
  }
  return true;
}
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  bool ans=solve();
  if (ans) printf("YES\n");
  else printf("NO\n");
}




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