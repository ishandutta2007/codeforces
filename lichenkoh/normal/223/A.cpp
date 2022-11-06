#include "bits/stdc++.h"
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
int rint();char rch();long long rlong();

const int mn=1e5+2;
char inv[256];
int lo[mn];
int hi[mn];
int pre[mn];
int query(int l, int r) {
  return pre[r+1]-pre[l];
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  inv[']']='[';
  inv[')']='(';
  string a; cin>>a;
  int n=a.length();
  for (int i=1;i<=n;i++) pre[i]=pre[i-1]+((a[i-1]=='[')?1:0);
  stack<char> S;
  for (int i=0;i<=n;i++) {lo[i]=INT_MAX; hi[i]=-1;}
  pair<int,pii> best=MP(0,MP(-0,-1));
  for (int i=0;i<=n;i++) {
    int len=S.size();
    lo[len+1]=INT_MAX;
    hi[len+1]=-1;
    chkmin(lo[len],i);
    chkmax(hi[len],i-1);
    if (lo[len]<=hi[len]) {
      auto cand=MP(query(lo[len],hi[len]),MP(-lo[len],hi[len]));
      //printf("i:%d len:%d %d %d %d\n",i,len,cand.fst,cand.snd.fst,cand.snd.snd);
      chkmax(best,cand);
    }
    if (i==n) break;
    char c=a[i];
    if (c=='('||c=='[') {
      S.push(c);
    }
    else {
      if ((!S.empty())&&S.top()==inv[c]) {
        S.pop();
      }
      else {
        S.push(c);
      }
    }
  }


  printf("%d\n",best.fst);
  for (int x=-best.snd.fst;x<=best.snd.snd;x++) printf("%c",a[x]);
  printf("\n");
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