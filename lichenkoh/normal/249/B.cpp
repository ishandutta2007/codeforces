#include <bits/stdc++.h>
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

const int mn=5e5+2;
char a[mn];
int sum[mn];
int getsum(int l, int r) {
  return sum[r+1]-sum[l];
}
int n,t;
int last=-1;
ll f(int mmid) {
  int k=mmid;
  stack<int> S;
  int right=0;
  ll final=1e18;
  ll need=0;
  for (int i=0;i<n;i++) {
    if (a[i]=='H') {
      chkmax(right,i);
      if (k==0) {
        if (S.empty()) {
          int imin=last,imax=n;
          while(imin<imax) {
            int imid=(imin+imax)>>1;
            if (getsum(i,imid)<0) imin=imid+1;
            else imax=imid;
          }
          if (imin<n) {
            ll ans=need+right+1ll+2ll*(imin-i);
            //printf("i:%d imin:%d sum:%d need:%d right:%d ans:%lld\n",i,imin,getsum(i,imin),need,right,ans);
            chkmin(final,ans);
          }
        }
        S.push(i);
      }
      else k--;
    }
    else if (a[i]=='S') {
      if (!S.empty()) {
        chkmax(right,i);
        int top=S.top();
        S.pop();
        if (S.empty()) {
          int dist=i-top;
          if (i<last) dist*=2;
          need+=dist;
          //if (need>t) break;
        }
      }
      else {
        k++;
      }
    }
  }
  if (S.empty()) {
    ll ans=need+right+1;
    chkmin(final,ans);
  }
  return final;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  scanf("%d %d\n%s\n",&n,&t,a);
  //assert(n==strlen(a));
  
  for (int i=n-1;i>=0;i--) {
    if (a[i]=='H') {last=i; break;}
  }
  int numh=0;
  sum[0]=0;
  for (int i=0;i<n;i++) {
    sum[i+1]=sum[i];
    if(a[i]=='H') {
      sum[i+1]--;
      numh++;
    }
    else if (a[i]=='S') sum[i+1]++;
  }
  //for (int i=0;i<=n;i++) printf("i:%d sum:%d\n",i,sum[i]);
  //if (last==-1) {
  //  printf("0\n"); return 0;
  //}
  //for (int imid=0;imid<=numh;imid++) printf("%d:%lld\n",imid,f(imid));
  //return 0;
  //printf("numh:%d\n",numh);
  int imin=0,imax=numh+1;
  while(imin<imax) {
    int imid=(imin+imax)>>1;
    ll need=f(imid);
    if (need>t) imin=imid+1;
    else imax=imid;
  }
  if (imin>=numh+1) printf("-1\n");
  else printf("%d\n",imin);
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