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
int k;
int dp[2][30][30];
bool f(int want, int even, int odd) {
  int dpval=dp[want][even][odd];
  if (dpval!=-1) return dpval;
  if (even+odd==k) {
    return dp[want][even][odd]=((odd&1)==want);
  }
  if (even>0&&!f(want^1,even-1,odd)) return dp[want][even][odd]=true;
  if (odd>0&&!f(want^1,even,odd-1)) return  dp[want][even][odd]=true;
  return dp[want][even][odd]=false;
}
bool solve(int even, int odd) {
  if (k%2==0) {
    if (odd+even==k) {
      return odd&1;
    }
    if ((odd+even-k)&1) {
      int diag=(odd+even-(k+1))/2;
      int lo=1+diag;
      int hi=k+diag;
      //printf("lo:%d hi:%d even:%d odd:%d\n",lo,hi,even,odd);
      return (lo<=odd&&odd<=hi);
    }
    return false;
  }
  else {
    if (odd+even==k) return (even&1)==0;
    if (odd-even>=(k-1)) return true;
    //printf("odd:%d even:%d\n",odd,even);
    if ((odd-even)%2==0) {
      //printf("odd:%d even:%d -(k-1):%d\n",odd,even,-(k-1));
      if (odd-even>=-(k-1)) return true;
    }
    return false;
  }
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();k=readInt();
  int even=0,odd=0;
  for (int i=0;i<n;i++) {
    int x=readInt(); if (x&1)odd++; else even++;
  }
  //memset(dp,-1,sizeof dp);
  if (solve(even,odd)) printf("Stannis\n");
  else printf("Daenerys\n");
  return 0;
  
  /*for (k=1;k<=20;k++) {
    memset(dp,-1,sizeof dp);
    printf("k:%d\n",k);
    printf(" :");for (int i=0;i<=29;i++) printf("%x ",i);
    printf("\n");
    for (int even=0;even<=29;even++) {
      printf("%x:",even);
      for (int odd=0;odd<=29;odd++) {
        if (even+odd<k) printf("8 ");
        else {
          printf("%d ",f(1,even,odd));
          if(f(1,even,odd)!=solve(even,odd)) {
            printf("k:%d even:%d odd:%d correct:%d solve:%d\n",k,even,odd,f(1,even,odd),solve(even,odd));
            assert(0);
            exit(0);
          }
        }
      }
      printf("\n");
    }
  }*/
}