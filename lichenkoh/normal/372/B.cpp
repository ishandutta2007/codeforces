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
const int mn=40;
bool a[mn][mn];
bool b[mn][mn][mn];
int c[mn][mn][mn][mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),q=readInt();
  for (int x=0;x<n;x++) {
    for (int y=0;y<m;y++) {
      a[x][y]=readCh()-'0';
      //printf("%d",a[x][y]);
    }
    //printf("\n");
  }
  for (int x=0;x<n;x++) for (int ylo=0;ylo<m;ylo++) {
    for (int y=ylo;y<m;y++) {
      if (a[x][y]==1) break;
      b[x][ylo][y]=1;
      //printf("b. %d %d %d\n",x,ylo,y);
    }    
  }
  for (int ylo=0;ylo<m;ylo++) {
    for (int yhi=ylo;yhi<m;yhi++) {
      for (int xlo=0;xlo<n;xlo++) {
        for (int xhi=xlo;xhi<n;xhi++) {
          if (b[xhi][ylo][yhi]) {
            //printf("%d %d %d %d\n",xlo,xhi,ylo,yhi);
            c[xlo][xhi][ylo][yhi]=1;
          }
          else break;
        }
      }
    }
  }
  for (int xlo=0;xlo<n;xlo++) {
    for (int xhi=xlo;xhi<n;xhi++) {
      for (int ylo=0;ylo<m;ylo++) {
        for (int yhi=ylo+1;yhi<m;yhi++) {
          c[xlo][xhi][ylo][yhi]+=c[xlo][xhi][ylo][yhi-1];
        }
      }
    }
  }
  for (int xlo=0;xlo<n;xlo++) {
    for (int xhi=xlo;xhi<n;xhi++) {
      for (int yhi=0;yhi<m;yhi++) {
        for (int ylo=yhi-1;ylo>=0;ylo--) {
          c[xlo][xhi][ylo][yhi]+=c[xlo][xhi][ylo+1][yhi];
        }
      }
    }
  }
  for (int ylo=0;ylo<m;ylo++) {
    for (int yhi=ylo;yhi<m;yhi++) {
      for (int xlo=0;xlo<n;xlo++) {
        for (int xhi=xlo+1;xhi<n;xhi++) {
          c[xlo][xhi][ylo][yhi]+=c[xlo][xhi-1][ylo][yhi];
        }
      }
    }
  }
  for (int ylo=0;ylo<m;ylo++) {
    for (int yhi=ylo;yhi<m;yhi++) {
      for (int xhi=0;xhi<n;xhi++) {
        for (int xlo=xhi-1;xlo>=0;xlo--) {
          c[xlo][xhi][ylo][yhi]+=c[xlo+1][xhi][ylo][yhi];
        }
      }
    }
  }
  for (int i=0;i<q;i++) {
    int xlo=readInt(),ylo=readInt(),xhi=readInt(),yhi=readInt();
    int ans=c[xlo-1][xhi-1][ylo-1][yhi-1];
    printf("%d\n",ans);
  }
}