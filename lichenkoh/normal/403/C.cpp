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
inline int rri()
{
  char c;
  while (c = getchar(), c <= ' ');
  bool sign = c == '-';
  if (sign)
  {
      c = getchar();
  }
  int res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')
  {
    res = res * 10 + (c - '0');
  }
  // One character is gobbled here
  return sign ? -res : res;
}
inline ll rrl()
{
  char c;
  while (c = getchar(), c <= ' ');
  bool sign = c == '-';
  if (sign)
  {
      c = getchar();
  }
  ll res = c - '0';
  while (c = getchar(), c >= '0' && c <= '9')
  {
    res = res * 10 + (c - '0');
  }
  // One character is gobbled here
  return sign ? -res : res;
}
inline char rrc()
{
  char c;
  while (c = getchar(), c <= ' ');
  return c;
}
inline int rrs(char *target) {
  char c;
  while (c = getchar(), c <= ' ');
  int idx=-1;
  target[++idx]=c;
  while(1) {
    c=getchar();
    if (c<=' '){
      target[++idx]='\0';
      return idx;
    }
    target[++idx]=c;
  }
}

vvi matrixUnit(ll n) {
    vvi res(n, vi(n));
    for (ll i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

vvi matrixMul(const vvi &a, const vvi &b) {
    ll n = a.size();
    ll m = a[0].size();
    ll k = b[0].size();
    vvi res(n, vi(k));
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
            for (ll p = 0; p < m; p++)
                res[i][j] = (res[i][j] + (long long) a[i][p] * b[p][j]) % MOD;
    return res;
}

void matrixMult(vvi &res, const vvi &a, const vvi &b) {
    ll n = a.size();
    ll m = a[0].size();
    ll k = b[0].size();
    for (ll i = 0; i < n; i++)
        for (ll j = 0; j < k; j++)
        {
          ll ans=0;
            for (ll p = 0; p < m; p++)
                ans = (ans + (long long) a[i][p] * b[p][j]) % MOD;
          res[i][j]=ans;
        }
}
const int mn=2004;
bitset<mn> g[mn];
bool bf(int n) {
  vvi inp;
  inp.resize(n);
  for (int x=0;x<n;x++) {inp[x].resize(n); for (int y=0;y<n;y++) inp[x][y]=g[x][y];}
  vvi a=inp;
  for (int k=0;k<500;k++) {
    bool ok=1;
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
      if (a[i][j]==0) {ok=0;break;}
    }
    if (ok) return 1;
    a=matrixMul(a,inp);
  }
  return 0;
}
bitset<mn> h[mn];
bitset<mn> seen;
bool solve2(int n) {
  queue<int> q;
  for (int x=0;x<n;x++) {
    if (h[0][x]) q.push(x);
  }
  seen=h[0];
  //for (int x=0;x<n;x++) {for (int y=0;y<n;y++) {
  //  printf("%d ",(int)h[x][y]);
  //} printf("\n");}
  while(!q.empty()) {
    int x=q.front(); q.pop();
    for (int y=0;y<n;y++) {
      if ((!seen[y])&&h[x][y]) {
        //printf("x:%d -> y:%d\n",x,y);
        q.push(y);
        seen[y]=true;
      }
    }
  }
  assert(seen.count()<=n);
  return (int)seen.count()==n;
}

bool solve(int n) {
  //for (int x=0;x<n;x++) {for (int y=0;y<n;y++) {
  //  printf("%d ",(int)g[x][y]);
  //} printf("\n");}
  int spec=-1;
  for (int k=0;k<n;k++) if(g[k][k]) spec=k;
  assert(spec!=-1);
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    int sx=(x==spec||x==0)?x^spec:x;
    int sy=(y==spec||y==0)?y^spec:y;
    h[sx][sy]=g[x][y];
  }
  assert(h[0][0]);
  if (!solve2(n)) return 0;
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    g[x][y]=h[y][x];
  }
  for (int x=0;x<n;x++) h[x]=g[x];
  if (!solve2(n)) return 0;
  return 1;
}
void test() {
  srand(time(0)+clock()+rand());
  for (int j=0;j<1000;j++) {
    int n=(rand()%6)+1;
    for (int x=0;x<n;x++) {
      h[x].reset();
      g[x].reset();
      for (int y=0;y<n;y++) g[x][y]=rand()&1;
    }
    int k=rand()%n;
    g[k][k]=1;
    bool b=bf(n); bool s=solve(n);
    if (b!=s) {
      for (int x=0;x<n;x++) {
        for (int y=0;y<n;y++) printf("%d",(int)g[x][y]);
        printf("\n");
      }
      printf("b:%d s:%d\n",b,s);
    }
  }
}
int main() 
{
  //test(); return 0;
	ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt();
  for (int x=0;x<n;x++) for (int y=0;y<n;y++) {
    int t=readInt();
    t=(t>0)?1:0;
    g[x][y]=t;
  }
  bool final=solve(n);
  if (final) printf("YES\n");
  else printf("NO\n");
}