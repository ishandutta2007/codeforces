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

pair<ll,ll> vp[100005];
bool cmp(const pair<ll,ll> &x,const pair<ll,ll> &y) {
  ll a=x.fst,c=y.fst;
  ll b=x.snd,d=y.snd;
  ll l=a*d,r=b*c;
  if (l==r) {
    return x.snd<y.snd;
  }
  return l>r;
}
const int maxm=6;
ll bestval[2][maxm];
ll bestw[2][maxm];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n=readInt(),wlim=readInt();
  for (int i=0;i<n;i++) {
    vp[i].snd=readInt();
    vp[i].fst=readInt();
  }
  sort(vp,vp+n,cmp);
  memset(bestval,-1,sizeof bestval);
  memset(bestw,-1,sizeof bestw);
  bestw[0][0]=0;
  bestval[0][0]=0;
  ll final=0;
  int cur=0,nxt=1;
  for (auto &got:vp) {
    memcpy(bestval[nxt],bestval[cur],sizeof bestval[nxt]);
    memcpy(bestw[nxt],bestw[cur],sizeof bestw[nxt]);
    ll val=got.fst, weight=got.snd;
    for (int m=0;m<maxm;m++) {
      if (bestw[cur][m]==-1) continue;
      //printf("m:%d bestw:%lld bestval:%lld\n",m,bestw[cur][m],bestval[cur][m]);
      ll new_weight=weight+bestw[cur][m];
      if (new_weight<=wlim) {
        ll newval=bestval[cur][m]+val;
        chkmax(final,newval);
        int newm=new_weight%maxm;
        if (newval>bestval[nxt][newm] || (newval==bestval[nxt][newm]&&new_weight<bestw[nxt][newm])) {
          bestval[nxt][newm]=newval;
          bestw[nxt][newm]=new_weight;
        }
      }
    }
    swap(cur,nxt);
  }
  printf("%lld\n",final);
}//abz