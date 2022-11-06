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
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#ifdef DEBUG_CAT

#define dbg(...)   dbg( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

const int md=10000+1;
vector<int> vlucky;
bitset<md> islucky;
void initlucky() {
for (int l=1;l<=4;l++) {
  for (int z=0;z<(1<<l);z++) {
    int x=0;
    for (int i=0;i<l;i++) {
      x*=10;
      if (z&(1<<i)) x+=7;
      else x+=4;
    }
    vlucky.PB(x);
    islucky[x]=true;
  }
}
}



const int mn=100000;


const int mg=sqrt(mn)+8;

int n;
int a[mn];
int sqrt_lidx[mg],sqrt_ridx[mg];
int sqrt_g[mn];

// Custom

int h[mg][md];
int vdelta[mg];

void sqrt_build() {
  int slim =round(sqrt(n))*1.5+1;
  //int slim=1; printf("FIXME\n");
  int glim=(n+slim-1)/slim;
  int rem=n-(glim-1)*slim;
  int idx=0;
  for (int g=0;g<glim;g++) {
    sqrt_lidx[g]=idx;
    int lim=(g==glim-1)?rem:slim;
    for (int s=0;s<lim;s++) {
      sqrt_g[idx]=g;

      // Custom
      //printf("g:%d %d\n",g,a[idx]);
      ++h[g][a[idx]];

      idx++;
    }
    sqrt_ridx[g]=idx-1;
  }
}



void group_modify(int g, int val) {
  //printf("g:%d deltaadd:%d\n",g,val);
  vdelta[g]+=val;
}

void naive_modify(int l, int r, int val) {
    int g=sqrt_g[l];
    assert(g==sqrt_g[r]);
    //int delta=vdelta[g];
  for (int x=l;x<=r;x++) {
    --h[g][a[x]];
    a[x]+=val;
    ++h[g][a[x]];
    //printf("x:%d a[x]:%d\n",x,a[x]);
  }
}

void sqrt_modify(int l, int r, int val) {
  int lg=sqrt_g[l];
  int rg=sqrt_g[r];
  if (lg==rg) {
    naive_modify(l,r,val);
  }
  else {
    naive_modify(l,sqrt_ridx[lg],val);
    naive_modify(sqrt_lidx[rg],r,val);
    //printf("lg:%d rg:%d\n",lg,rg);
    for (int g=lg+1;g<=rg-1;g++) group_modify(g,val);
  }
}

int naive_query(int l, int r) {
  int g=sqrt_g[l];
  int delta=vdelta[g];
  int ans=0;
  for (int x=l;x<=r;x++) {
    ans+=islucky[a[x]+delta];
  }
  //printf("l:%d r:%d delta:%d ans:%d\n",l,r,delta,ans);
  return ans;
}

int group_query(int g) {
  int ans=0;
  for (auto &lucky:vlucky) {
    int want=lucky-vdelta[g];
    if (want>=0) {
      ans+=h[g][want];
    }
  }
  //printf("g:%d ans:%d\n",g,ans);
  return ans;
}

int sqrt_query(int l, int r) {
  int lg=sqrt_g[l],rg=sqrt_g[r];
  if (lg==rg) {
    return naive_query(l,r);
  }
  else {
    int ans=naive_query(l,sqrt_ridx[lg])+naive_query(sqrt_lidx[rg],r);
    for (int g=lg+1;g<=rg-1;g++) {
      ans+=group_query(g);
    }
    return ans;
  }
}


int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  initlucky();
  int q;
  cin>>n>>q;
  for (int i=0;i<n;i++) {
    cin>>a[i];
  }
  sqrt_build();
  for (int i=0;i<q;i++) {
    string s; int l,r; cin>>s>>l>>r; --l; --r;
    if (s[0]=='c') {
      int ans=sqrt_query(l,r);
      printf("%d\n",ans);
    }
    else {
      int d; cin>>d;
      sqrt_modify(l,r,d);
    }
  }
}