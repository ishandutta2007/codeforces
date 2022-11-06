#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef int ll;
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

#define dbg(...)   dbg( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
/*static char stdinBuffer[1024];
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
    readAhead(128);

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
*/
const int mn=100000;
const int mg=317+1;

queue<int> block[mg];

int n;
int a[mn];
int sqrt_lidx[mg],sqrt_ridx[mg];
int sqrt_g[mn],sqrt_s[mn];
int h[mg][mn+1];
int tmp[mg];
void sqrt_build() {
  int slim=round(sqrt(n));
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    sqrt_lidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    vector<int> v;
    for (int s=0;s<lim;s++) {
      int val=a[idx];
      sqrt_g[idx]=g;
      sqrt_s[idx]=s;
      h[g][val]++;
      v.PB(val);
      idx++;
    }
    reverse(v.begin(),v.end());
    for (auto &w:v) block[g].push(w);
    sqrt_ridx[g]=idx-1;
  dbg("g:%d %d->%d\n",g,sqrt_lidx[g],sqrt_ridx[g]);
  }
}
int getRightMostElementByGroup(int g) {
  return block[g].front();
}
void popRightMostElementByGroup(int g) {
  //dbg("pop:%d\n",g);
  block[g].pop();
}
void insLeftMostElementByGroup(int g, int val) {
  //dbg("ins:%d val:%d\n",g,val);
  block[g].push(val);
}

int putGroupIntoArray(int g, int *dest) {
  int sz=sqrt_ridx[g]-sqrt_lidx[g]+1;
  //dbg("g:%d sz:%d bsz:%d clear\n",g,sz,block[g].size());
  int extra=-1;
  for (int i=0;i<sz;i++) {
    assert(!block[g].empty());
    dest[sz-1-i]=block[g].front();
    block[g].pop();
  }
  for (int i=0;i<sz;i++) {
    dbg("%d ",dest[i]);
  }
  dbg(" end g:%d\n",g);
  if (!block[g].empty()) extra=block[g].front();
  while(!block[g].empty()) block[g].pop();
  return extra;
}
void sqrt_modify(int l, int r) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  int ls=sqrt_s[l],rs=sqrt_s[r];
  if (lg<rg) {
    for (int g=lg;g<rg;g++) {
      int e=getRightMostElementByGroup(g);
      //dbg("g:%d re:%d\n",g,e);
      if (g!=lg) popRightMostElementByGroup(g);
      insLeftMostElementByGroup(g+1,e);
      h[g][e]--;
      h[g+1][e]++;
    }
    int re;
    {
      int g=rg;
      int sz=sqrt_ridx[g]-sqrt_lidx[g]+1;
      int extra=putGroupIntoArray(rg, tmp);
      re=tmp[rs];
      for (int s=rs;s>=1;s--) tmp[s]=tmp[s-1];
      tmp[0]=extra;
      for (int s=sz-1;s>=0;s--) block[g].push(tmp[s]);
      h[rg][re]--;
      h[lg][re]++;
    }
    {
      int g=lg;
      int sz=sqrt_ridx[g]-sqrt_lidx[g]+1;
      putGroupIntoArray(g, tmp);
      for (int s=sz-1;s>=ls+1;s--) tmp[s]=tmp[s-1];
      tmp[ls]=re;
      for (int s=sz-1;s>=0;s--) block[g].push(tmp[s]);
    }
  }
  else {
    int g=rg;
    int sz=sqrt_ridx[g]-sqrt_lidx[g]+1;
    int extra=putGroupIntoArray(g, tmp);
    int re=tmp[rs];
    for (int s=rs;s>=ls+1;s--) tmp[s]=tmp[s-1];
    tmp[ls]=re;
    for (int s=sz-1;s>=0;s--) block[g].push(tmp[s]);
  }
}
int naive_query_helper(int g, int sl, int sr, int val) {
  int sz=sqrt_ridx[g]-sqrt_lidx[g]+1;
  putGroupIntoArray(g, tmp);
  int ans=0;
  for (int s=sl;s<=sr;s++) {
    if (tmp[s]==val) ans++;
  }
  for (int s=sz-1;s>=0;s--) {
    block[g].push(tmp[s]);
  }
  return ans;
}
int naive_query(int l, int r, int val) {
  int g=sqrt_g[l];
  //dbg("l:%d r:%d val:%d\n",l,r,val);
  assert(g==sqrt_g[r]);
  return naive_query_helper(g, sqrt_s[l], sqrt_s[r],val);
}
int sqrt_query(int l, int r, int val) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  if (lg==rg) {
    return naive_query(l,r,val);
  }
  else {
    int ans=naive_query(l,sqrt_ridx[lg],val)+naive_query(sqrt_lidx[rg],r,val);
    dbg("naive:%d->%d:%d %d->%d:%d\n",l,sqrt_ridx[lg],naive_query(l,sqrt_ridx[lg],val),
      sqrt_lidx[rg],r,naive_query(sqrt_lidx[rg],r,val)
      );
    for (int g=lg+1;g<rg;g++) {
      ans+=h[g][val];
      dbg("Got g:%d ans:%d\n",g,h[g][val]);
    }
    return ans;
  }
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  //n=readInt();
  scanf("%d",&n);
  for (int i=0;i<n;i++) {
    //a[i]=readInt();
    scanf("%d",a+i);
  }
  sqrt_build();
  int q; scanf("%d",&q);
  int lastans=0;
  for (int i=0;i<q;i++) {
    //for (int g=0;g<=2;g++) {
    //  auto bb=block[g];
    //  putGroupIntoArray(g,tmp);
    //  block[g]=bb;
    //}
    //int t=readInt(),lp=readInt(),rp=readInt();
    int t,lp,rp; scanf("%d%d%d",&t,&lp,&rp);
    int l=lp+lastans-1; if (l>=n) l-=n;
    int r=rp+lastans-1; if (r>=n) r-=n;
    if (l>r) swap(l,r); 
    if (t==1) {
      sqrt_modify(l,r);
    }
    else {
      //int kp=readInt();
      int kp; scanf("%d",&kp);
      int k=kp+lastans-1; if (k>=n) k-=n;
      k++;
      //dbg("l:%d r:%d k:%d\n",l,r,k);
      lastans=sqrt_query(l,r,k);
      //lastans=naive_query(l,r,k); //dbg("\nNAIVE\n");
      printf("%d\n",lastans);
    }
  }
}