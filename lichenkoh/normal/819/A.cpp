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
const int mn=1e5+4;
bool s[26];
int t[mn];
int DEL=0;
int g(int a, int b, int l, int r) {
  for (int i=0;i<a;i++) {
    t[i]=i;
  }
  int x=a;
  while(x<=r) {
    int use=t[x-1];
    for (int i=0;i<a-b;i++) {
      chkmin(use,t[x-1-i]);
    }
    for (int i=0;i<b;i++) {
      t[x]=use;
      x++;
    }
    memset(s,0,sizeof s);
    for (int i=0;i<a;i++) {
      s[t[x-1-i]]=1;
    }
    int c=0;
    for (int i=0;i<a;i++) {
      while(s[c]) c++;
      t[x]=c;
      x++;
      c++;
    }
  }
  //for (int x=0;x<=r;x++) {
  //  printf("%d ",t[x]);
  //}
  //printf("\n");
  memset(s,0,sizeof s);
  for (int x=l;x<=r;x++) s[t[x]]=1;
  int ans=0; for (int c=0;c<26;c++) ans+=s[c];
  //memset(s,0,sizeof s);
  //int u=((r)/(a+b))*(a+b);
  //int d=u-(a+b);
  //for (int x=d;x<=u;x++) s[t[x]]=1;
  //int ans2=0; for (int c=0;c<26;c++) ans2+=s[c];
  return ans;
}

int f(int a, int b, int l, int r, int use, int b4) {
  for (int i=0;i<a;i++) {
    t[i]=i;
  }
  int x=a;
  while(x<=r) {
    for (int i=0;i<b;i++) {
      if (x<l) t[x]=b4;
      else t[x]=use;
      x++;
    }
    memset(s,0,sizeof s);
    for (int i=0;i<a;i++) {
      s[t[x-1-i]]=1;
    }
    int c=0;
    for (int i=0;i<a;i++) {
      while(s[c]) c++;
      t[x]=c;
      x++;
      c++;
    }
  }
  /*if (use==1&&b4==1)
  {for (int x=0;x<=r;x++) {
    printf("%d ",t[x]);
  }
  printf("\n");}*/
  memset(s,0,sizeof s);
  for (int x=l;x<=r;x++) s[t[x]]=1;
  int ans=0; for (int c=0;c<26;c++) ans+=s[c];
  //memset(s,0,sizeof s);
  //int u=((r)/(a+b))*(a+b);
  //int d=u-(a+b);
  //for (int x=d;x<=u;x++) s[t[x]]=1;
  //int ans2=0; for (int c=0;c<26;c++) ans2+=s[c];
  return ans;
}
const int D=300;
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int a,b,l,r; scanf("%d%d%d%d",&a,&b,&l,&r);
  --l; --r;
  int dl=l/(a+b);
  if (dl>=D) {
    l-=(dl-D)*(a+b);
    r-=(dl-D)*(a+b);
  }
  int dx=(r-l)/(a+b);
  DEL=0;
  if (dx>=D) {
    r-=(dx-D)*(a+b);
    DEL=dx-D;
  }
  int ans=g(a,b,l,r);
  for (int x=0;x<26;x++) for (int y=0;y<26;y++) chkmin(ans,f(a,b,l,r,x,y));
  printf("%d\n",ans);
}