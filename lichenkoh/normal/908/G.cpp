#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
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
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

int mod_pow(int a, int n) {const int mod=MOD; int ret = 1; int p = a % mod; while (n) { if (n & 1) ret = (ret *(ll) p) % mod; p = (p *(ll) p) % mod; n >>= 1; } return ret; }
const int mn=704;
const int MAXFACT=mn;
int fact[MAXFACT+1],invfact[MAXFACT+1];
inline int mul(int x,int y) {return (x*(ll)y)%MOD;}
int invten[mn],pten[mn],gten[mn],pg[mn][mn];
int binom(int n,int k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}
int bin[mn][mn];
void init() {
  {
    int x=1;
    for (int i=0;i<mn;i++) {
      pten[i]=x;
      x=mul(x,10);
    }
    gten[0]=0;
    for (int i=1;i<mn;i++) {
      gten[i]=gten[i-1]+pten[i-1];
      if (gten[i]>=MOD) gten[i]-=MOD;
    }
    for (int p=0;p<mn;p++) for (int y=0;y<mn;y++) {
      pg[p][y]=mul(pten[p],gten[y]);
    }
  }
  {
    int iten=mod_pow(10,MOD-2);
    int got=1;
    for (int x=0;x<mn;x++) {
      invten[x]=got;
      got=mul(got,iten);
    }
  }
  {
    int got=1;
    for (int x=0;x<=MAXFACT;x++) {
      fact[x]=got;
      got=mul(got,x+1);
    }
    got=mod_pow(got,MOD-2);
    for (int x=MAXFACT;x>=0;x--) {
      got=mul(got,x+1);
      invfact[x]=got;
    }
  }
  for (int n=0;n<mn;n++) for (int k=0;k<=n;k++) bin[n][k]=binom(n,k);
}

int f[10][2][mn];
void initd(int sd) {
  int cur=0,nxt=1;
  f[sd][0][0]=1;
  for (int d=9;d>=0;d--) {
    if (d==sd) {
      for (int x=0;x<mn;x++) {
        f[sd][cur][x]=mul(f[sd][cur][x],pten[x]);
      }
    }
    else {
      memset(f[sd][nxt],0,sizeof f[sd][nxt]);
      for (int x=0;x<mn;x++) {
        int now=f[sd][cur][x];
        for (int add=0;add<mn-x;add++) {
          f[sd][nxt][x+add]=(f[sd][nxt][x+add]+now*(ll)invfact[add])%MOD;
          //if (sd==1&&x+add==0) printf("x:%d add:%d\n",x,add);
        }
      }
      swap(cur,nxt);
    }
    //if (sd==1) printf("d:%d f:%d\n",d,f[sd][nxt][1]);
  }
  for (int x=0;x<mn;x++) f[sd][1][x]=mul(f[sd][1][x], fact[x]);
  assert(cur==1);
}


typedef unsigned long long ull;
int cnt[10];
int go(int fr) {
  dbg("fr:%d ",fr); for (int d=0;d<=9;d++) for (int i=0;i<cnt[d];i++) dbg("%d",d); dbg("\n");
  int sufsum=0;
  int final=0;
  for (int d=9;d>=1;d--) {
    int cntd=cnt[d];
    for (int len=cntd;len<=cntd+fr;len++) {
      int L=f[d][1][fr-(len-cntd)], R=pg[sufsum][len], M=bin[fr][len-cntd];
      int LM=mul(L,M);
      ull contrib=((ull)d)*(ull)LM*(ull)R;
      dbg("d:%d len:%d cntd:%d L:%d M:%d R:%d L*R:%lld dd:%d ss:%d l:%d\n",d,len,cntd,L,M,R,contrib,fr-(len-cntd),sufsum,len);
      final=((unsigned)final+(ull)contrib)%MOD;
    }
    sufsum+=cntd;
  }
  dbg("final:%d\n",final);
  return final;
}


int solve(string a) {
  memset(cnt,0,sizeof cnt);
  ll final=0;
  int alim=a.length();
  for (int x=0;x<alim;x++) {
    if (a[x]=='0') continue;
    int n=alim-x-1;
    int dlim=a[x]-'0'-1;
    for (int d=0;d<=dlim;d++) {
      cnt[d]++;
      final+=go(n);
      cnt[d]--;
    }
    cnt[a[x]-'0']++;
  }
  sort(a.begin(),a.end());
  int cum=0;
  for (auto &w:a) {
    cum=mul(cum,10);
    cum+=(w-'0');
  }
  final+=cum;
  return (int)(final%MOD);
}

int bf(string &inp) {
  int n=0;
  for (auto &w:inp) {
    n*=10;
    n+=(w-'0');
  }
  ll final=0;
  for (int x=1;x<=n;x++) {
    string a=to_string(x);
    sort(a.begin(),a.end());
    int cum=0;
    for (auto &w:a) {
      cum=mul(cum,10);
      cum+=(w-'0');
    }
    final+=cum;
  }
  return (int)(final%MOD);
}

void test() {
  for (int x=1;x<=22873;x++) {
    string a=to_string(x);
    int ss=solve(a);
    int bff=bf(a);
    if (ss!=bff) {
      printf("x:%d ss:%d bff:%d\n",x,ss,bff);
    }
  }
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  init();
  for (int d=1;d<=9;d++) initd(d);
  //test(); return 0;
  string a;
  cin>>a;
  int ans=solve(a);
  printf("%d\n",ans);
}