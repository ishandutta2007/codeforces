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
int vo[5][5];
inline int f() {
  return abs(vo[1][2]-vo[3][4])+abs(vo[1][3]-vo[2][4])+abs(vo[1][4]-vo[2][3]);
}
int &o(int x, int y) {
  if (x>y) swap(x,y);
  return vo[x][y];
}
void fail() {
  printf("-1\n"); exit(0);
}
int ve[5];
int vt[5];
const int mn=5e5+4;
char vans[5][mn];
int vansi[5];
void addc(int t, char c) {
  //printf("t:%d c:%c\n",t,c);
  vans[t][vansi[t]++]=c;
}
int no[1<<4][5][5];

bool cmp(pii x, pii y) {
  int a=x.fst,b=x.snd,c=y.fst,d=y.snd;
  ll diff=a*(ll)d-b*(ll)c;
  if (diff==0) {
    return b<d;
  }
  return diff<0;
}
int vco[5][5];
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  vector<pair<int,pii> > v; v.reserve(6);
  for (int x=1;x<=4;x++) {
    for (int y=x+1;y<=4;y++) {
      cin>>vo[x][y]; vco[x][y]=vo[x][y];
    }
  }
  for (int z=1;z<(1<<4);z++) {
    for (int x=1;x<=4;x++) {
      if (z&(1<<(x-1))) {
        for (int y=1;y<=4;y++) {
          if (x==y) continue;
          no[z][min(x,y)][max(x,y)]++;
        }
      }
    }
  }
  int ie=f();
  while(ie>0) {
    pii best=MP(-1,1);
    int bz=-1;
    for (int z=1;z<(1<<4);z++) {
      bool ok=1;
      for (int x=1;x<=4;x++) {
        for (int y=x+1;y<=4;y++) {
          if (x==y) continue;
          if (o(x,y)<no[z][x][y]) {ok=0; break;}
        }
      }
      if (ok) {
        for (int x=1;x<=4;x++) {
          for (int y=x+1;y<=4;y++) {
            if (x==y) continue;
            o(x,y)-=no[z][x][y];
          }
        }
        int nie=f();
        pii goodness=MP(ie-nie,__builtin_popcount(z));
        if (ie-nie>0) {
          if (cmp(best,goodness)) {
            best=goodness;
            bz=z;
          }
        }
        for (int x=1;x<=4;x++) {
          for (int y=x+1;y<=4;y++) {
            if (x==y) continue;
            o(x,y)+=no[z][x][y];
          }
        }
      }
    }
    if (bz==-1) break;
    {
      int z=bz;
      for (int x=1;x<=4;x++) {
        if (z&(1<<(x-1))) ++ve[x];
      }
      for (int x=1;x<=4;x++) {
        for (int y=x+1;y<=4;y++) {
          if (x==y) continue;
          o(x,y)-=no[z][x][y];
        }
      }
      ie=f();
    }
  }
  if (ie!=0) fail();
    //for (int x=1;x<=4;x++) for (int y=x+1;y<=4;y++)
    //printf("x:%d y:%d o:%d\n",x,y,o(x,y));
  int S=o(1,2)+o(1,3)+o(1,4);
  if (S&1) fail();
  S/=2;
  for (int y=2;y<=4;y++) {
    //printf("y:%d S:%d o:%d",y,S,o(1,y));
    vt[y] = S - o(1, y);
  }
  for (int x=1;x<=4;x++) {
    //printf("x:%d ve[x]:%d\n",x,ve[x]);
    for (int i=0;i<ve[x];i++) {
      addc(x,'a');
      for (int y=1;y<=4;y++) {
        if (x!=y) addc(y,'b');
      }
    }
  }
  for (int x=2;x<=4;x++) {
    for (int i=0;i<vt[x];i++) {
      addc(1,'a');
      addc(x,'a');
      for (int y=2;y<=4;y++) {
        if (x!=y) addc(y,'b');
      }
    }
  }
    int k=vansi[1];
  for (int x=1;x<=4;x++) {
    for (int y=x+1;y<=4;y++) {
      int got=0;
      for (int i=0;i<k;i++) if (vans[x][i]!=vans[y][i]) got++;
      //printf("got:%d o:%d\n",got,o(x,y));
      if (got!=vco[x][y]) fail();
    }
  }
  printf("%d\n",vansi[1]);
  for (int x=1;x<=4;x++) {
    addc(x,'\0');
    printf("%s\n",vans[x]);
  }
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