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

char readCh()
{
    readAhead(16);
    while(*stdinPos==' '||*stdinPos=='\n') ++stdinPos;
    char ans=*stdinPos;
    ++stdinPos;
    return ans;
}

const int mp=60;
typedef struct S {
  int a[60];
  int len;
} S;
S identity;
S combine(S &dest,S x, S y) {
  if (x.a[0]==0) dest=y;
  if (y.a[0]==0) dest=x;
  //for (int i=0;i<13;i++) printf("%d ",x.a[i]); printf("L\n");
  //for (int i=0;i<13;i++) printf("%d ",y.a[i]); printf("R\n");
  for (int i=0;i<mp;i++) {
    int t=x.a[i];
    dest.a[i]=t+y.a[(i+t)%mp];
  }
  dest.len=x.len+y.len;
  //for (int i=0;i<13;i++) printf("%d ",dest.a[i]); printf("D\n");
  return dest;
}
S combine(S x, S y) {
  S dest;
  combine(dest,x,y);
  return dest;
}

const ll MAXN=100002;
S t[2*MAXN];
int segn;
void build(int n) {  // build the tree
  segn=n;
  for (int i = n - 1; i > 0; --i) {
    combine(t[i], t[i<<1], t[i<<1|1]);
  }
}
void modify(int p, const S& value) {
  int n=segn;
    for (t[p += n] = value; p >>= 1; ) combine(t[p], t[p<<1], t[p<<1|1]);
}

S query(int l, int r) {
  int n=segn;
    r++;
    S resl=identity, resr=identity;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {resl = combine(resl, t[l++]);}
        if (r&1) {resr = combine(t[--r], resr);}
    }
    return combine(resl, resr);
}

S one[7];

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt();
  segn=n+1;
  for (int x=2;x<=6;x++) {
    one[x].len=1;
    for (int i=0;i<mp;i++) {
      one[x].a[i]=(i%x==0)?2:1;
    }
  }
  for (int i=0;i<n;i++) {
    int per=readInt();
    t[segn+i]=one[per];
  }
  build(segn);
  S tmp=combine(one[4],one[2]);
  //printf("tmp:a[0]:%d\n",tmp.a[0]);
  int q=readInt();
  for (int i=0;i<q;i++) {
    int c=readCh(),x=readInt(),y=readInt();
    if (c=='A') {
      --x; --y;
      S q=query(x,y-1);
      //printf("l:%d r:%d\n",x,y-1);
      int ans=q.a[0];
      printf("%d\n",ans);
    }
    else {
      --x;
      modify(x,one[y]);
    }
  }
}