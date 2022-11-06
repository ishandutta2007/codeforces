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
const int mn=2e5+4;
bitset<mn> ia,ib;
int vc[mn];
vector<int> vab,va,vb,vres;
void restr(vector<int> &v, int k) {
  int vsz=v.size();
  chkmin(k,vsz);
  if (vsz>k) {
    for (int i=k;i<vsz;i++) vres.PB(v[i]);
  }
  v.resize(k);
}

priority_queue<int> pql; // Maxheap
priority_queue<int,vector<int>, greater<int> > pqr; // Minheap
ll pqsum;
void pqinit() {
  pqsum=0;
  pqr.push(1<<30);
}

void pqins(int x) {
  if (x>=pqr.top()) pqr.push(x);
  else {pql.push(x); pqsum+=x;}
}
bool pqsetsize(int wantsize) {
    while(pql.size()>wantsize) {
      int got=pql.top(); pql.pop(); pqsum-=got;
      pqr.push(got);
    }
    while(pql.size()<wantsize&&!pqr.empty()) {
      int got=pqr.top(); pqr.pop(); pqsum+=got;
      pql.push(got);
    }
    return pql.size()==wantsize;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n=readInt(),m=readInt(),k=readInt();
  for (int i=0;i<n;i++) vc[i]=readInt();
  int an=readInt(); for (int i=0;i<an;i++) {int x=readInt()-1; ia[x]=true;}
  int bn=readInt(); for (int i=0;i<bn;i++) {int x=readInt()-1; ib[x]=true;}
  for (int i=0;i<n;i++) {
    int x=vc[i];
    if (ia[i]&&ib[i]) vab.PB(x);
    else if (ia[i]) va.PB(x);
    else if (ib[i]) vb.PB(x);
    else vres.PB(x);
  }
  int tlim=min((int)k,(int)min(va.size(),vb.size()));
  sort(va.begin(),va.end());
  sort(vb.begin(),vb.end());
  sort(vab.begin(),vab.end());
  sort(vres.begin(),vres.end());
  restr(va,tlim);restr(vb,tlim);restr(vab,k);
  multiset<int> sa,sb;
  
  ll final=1e18;
  ll suma=0,sumb=0,sumab=0;
  for (auto &w:va) {sa.insert(w);suma+=w;}
  for (auto &w:vb) {sb.insert(w);sumb+=w;}
  int t=tlim;
  //printf("tlim:%d\n",tlim);
  pqinit();
  for (auto &w:vres) {
    pqins(w);
  }
  int abi=0;
  for (;t>=0;t--) {
    int mid=k-t;
    if (mid>vab.size()) break;
    while(sa.size()>t) {
      auto it=sa.end(); --it;
      int got=*it;
      suma-=got;
      pqins(got);
      sa.erase(it);
    }
    while(sb.size()>t) {
      auto it=sb.end(); --it;
      int got=*it;
      sumb-=got;
      pqins(got);
      sb.erase(it);
    }
    int wantsize=max(0,m-2*t-(k-t));
    bool success=pqsetsize(wantsize);
    while(abi<max(0,k-t)&&abi<vab.size()) {
      sumab+=vab[abi];
      abi++;
    }
    if (success&&sa.size()==t&&sb.size()==t&&k-t==abi&&abi+2*t+wantsize==m) {
      //printf("t:%d. %lld %lld %lld %lld. %d vab:%d\n",t,suma,sumb,sumab,pqsum,abi,(int)vab.size());
      ll cand=suma+sumb+sumab+pqsum;
      chkmin(final,cand);
    }
  }
  if (final>=((1e18)-5)) final=-1;
  printf("%lld\n",final);
}