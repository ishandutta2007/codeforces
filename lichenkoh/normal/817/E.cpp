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
const int INF=1<<25;
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

typedef struct _node {
  int c;
  _node *s[2];
  _node() {
    c=0; s[0]=s[1]=NULL;
  }
} node;

void ins(node *v, int x, int k, int val) {
  int b=(x>>k)&1;
  (v->c)+=val;
  if (k<0) return;
  if (v->s[b]==NULL) v->s[b] = new node;
  ins(v->s[b], x, k-1, val);
}

int query(node *v, int p, int l, int k) {
  if (v==NULL) return 0;
  int pb=(p>>k)&1;
  int lb=(l>>k)&1;
  int ans=0;
  if (k<0) return ans;
  if (lb) {
    if (v->s[pb]) {
      ans+=v->s[pb]->c;
      //printf("p:%d l:%d k:%d addc:%d\n",p,l,k,v->s[pb]->c);
    }
    ans+=query(v->s[pb^1], p, l, k-1);
  }
  else {
    ans+=query(v->s[pb], p, l, k-1);
  }
  //printf("p:%d l:%d k:%d ans:%d\n",p,l,k,ans);
  return ans;
}
const int MAXK=28;
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int q; scanf("%d",&q);
  node *root = new node;
  for (int i=0;i<q;i++) {
    int t,p; scanf("%d%d",&t,&p);
    if (t==3) {
      int l; scanf("%d",&l);
      int ans=query(root,p,l,MAXK);
      printf("%d\n",ans);
    }
    else {
      int delta=(t==1)?1:-1;
      ins(root,p,MAXK,delta);
    }
  }
}