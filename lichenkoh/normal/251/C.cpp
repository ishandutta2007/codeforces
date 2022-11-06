#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define vendl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;

const int MAXC=5e7;
const int MAXB=1e6;
//const int MAXC=1e6;
//const int MAXB=6e5;
int g[MAXC];
int klim;
int brute(ll src, ll dest) {
  g[0]=0;
  for (ll x=dest+1;x<=src;x++) {
    int ans=g[x-dest-1];
    for (int k=klim;k>=2;k--) {
      int r=x%k;
      //printf("x:%lld k:%d r:%d cand:%d\n",x,k,r,g[x-r-dest]);
      if (r!=0&&x-r-dest>=0) chkmin(ans,g[x-r-dest]);
    }
    ans++;
    //printf("x:%lld ans:%d\n",x,ans);
    g[x-dest]=ans;
  }
  //printf("%lld->%lld\n",src,dest);
  return g[src-dest];
}

const int m=360360;
int fstep[m];
ll fnum[m];

int main()
{
  /*ll x=2;
  for (ll y=3;y<=15;y++) {
    x=(x*y)/__gcd(x,y);
  }
  printf("%lld\n",x); return 0;*/
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll src,dest;  cin>>src>>dest>>klim;
  ll x=src;
  int initstep=-1,loopstep; ll initnum,loopnum;
  {
    int step=1;
    while(x>0) {
      int key=x%m;
      if (fstep[key]!=0) {
        initstep=fstep[key];
        initnum=fnum[key];
        loopstep=step-initstep;
        loopnum=initnum-x;
        break;
      }
      fstep[key]=step;
      fnum[key]=x;
      int bestrem=1;
      for (int k=klim;k>=2;k--) {
        int rem=key%k;
        chkmax(bestrem,rem);
      }
      x-=bestrem;
      step++;
    }
  }
  ll final;
  //printf("initstep:%d\n",initstep);
  if (initstep!=-1) {
    ll dist=initnum-(dest+MAXB);
    if (dist>=0) {
      ll looptimes=(dist/loopnum);
      ll newsrc=initnum-looptimes*loopnum;
      //printf("dist:%lld looptimes:%lld newsrc:%lld loopnum:%lld\n",dist,looptimes,newsrc,loopnum);
      ll got=brute(newsrc,dest);
      final=got+initstep-1+1ll*looptimes*loopstep;
    }
    else final=brute(src,dest);
  }
  else final=brute(src,dest);
  printf("%lld\n",final);
}