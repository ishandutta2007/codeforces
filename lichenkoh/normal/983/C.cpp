#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
const int mn=2001;
const int ml=9;
const int md=10;
const int EMP=md-1;
const int mz=715;
int vd[mz];
int f[2][ml][mz];
int vs[mn],vt[mn];

int id2vec[mz][4];
int vec2id[md][md][md][md];
int tmp[4];

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int gid=0;
  for (int a=0;a<md;a++) for (int b=a;b<md;b++) for (int c=b;c<md;c++) for (int d=c;d<md;d++) {
    id2vec[gid][0]=a;
    id2vec[gid][1]=b;
    id2vec[gid][2]=c;
    id2vec[gid][3]=d;
    vec2id[a][b][c][d]=gid;
    ++gid;
  }
  //printf("gid:%d\n",gid); return 0;
  for (int a=0;a<md;a++) for (int b=0;b<md;b++) for (int c=0;c<md;c++) for (int d=0;d<md;d++) {
    tmp[0]=a;
    tmp[1]=b;
    tmp[2]=c;
    tmp[3]=d;
    sort(tmp,tmp+4);
    vec2id[a][b][c][d]=vec2id[tmp[0]][tmp[1]][tmp[2]][tmp[3]];
  }

  int n=rint();
  for (int i=0;i<n;i++) {vs[i]=rint()-1;vt[i]=rint()-1;}
  int cur=0,nxt=1;
  memset(f[cur],-1,sizeof f[0]);
  f[cur][0][mz-1]=0;
  for (int t=0;;++t) {
    memset(f[nxt],-1,sizeof f[0]);
    for (int l=0;l<ml;l++) {
      if (f[cur][l][mz-1]==n) {
        printf("%d\n",t); exit(0);
      }
    }
    for (int l=0;l<ml;l++) {
      for (int z=0;z<mz;z++) {
        int now=f[cur][l][z]; if (now==-1) continue;
        for (int x=0;x<4;x++) { // Exit
          if (id2vec[z][x]==l) {
            memcpy(tmp,id2vec[z],sizeof tmp);
            tmp[x]=EMP;
            int id=vec2id[tmp[0]][tmp[1]][tmp[2]][tmp[3]];
            chkmax(f[nxt][l][id],now);
          }
        }
        if (now<n&&vs[now]==l) for (int x=0;x<4;x++) { // Enter
          if (id2vec[z][x]==EMP) {
            memcpy(tmp,id2vec[z],sizeof tmp);
            tmp[x]=vt[now];
            int id=vec2id[tmp[0]][tmp[1]][tmp[2]][tmp[3]];
            chkmax(f[nxt][l][id],now+1);
          }
        }
        if (l+1<ml) chkmax(f[nxt][l+1][z],now); // Up
        if (l-1>=0) chkmax(f[nxt][l-1][z],now); // Down
      }
    }
    swap(cur,nxt);
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