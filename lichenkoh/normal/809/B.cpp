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
const int INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
//#define DEBUG_CAT
#ifdef DEBUG_CAT

#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
char str[2000];
bool query(int x, int y) {
  printf("1 %d %d\n",x,y);
  fflush(stdout);
  scanf("%s",str);
  return (str[0]=='T');
}
bool output(int x, int y) {
  printf("2 %d %d\n",x,y);
  fflush(stdout);
  return true;
}
int n,k;
int qcnt;
vector<int> secret;
void check(int x) {
  assert(1<=x);
  assert(x<=n);
}
/*bool query(int x, int y) {
  qcnt++;
  assert(qcnt<=60);
  assert(x!=y);
  check(x); check(y);
  int xans=INF,yans=INF;
  for (auto &w:secret) {
    chkmin(xans,abs(x-w));
    chkmin(yans,abs(y-w));
  }
  bool ans=(xans<=yans);
  dbg("x:%d y:%d ans:%d\n",x,y,ans);
  return ans;
}
bool output(int x, int y) {
  assert(x!=y);
  int ans=0;
  for (auto &w:secret) {
    if (w==x) ans++;
    if (w==y) ans++;
  }
  dbg("output: %d %d ans:%d\n",x,y,ans);
  return ans==2;
}*/
void gen() {
  int a[100000+5];
  srand(clock()+rand());
  n=rand()%(100000-2)+2;
  k=rand()%(n-1)+2;
  k=2;
  for (int x=0;x<n;x++) a[x]=x+1;
  random_shuffle(a,a+n);
  secret.clear();
  for (int x=0;x<k;x++) secret.PB(a[x]);
  qcnt=0;
}
int one(int x) {
  int l=x-1,r=x+1;
  bool lok=0,rok=0;
  if (l<1) lok=1;
  else {
    int q=query(x,l);
    if (q) lok=1;
  }
  if (r>n) rok=1;
  else {
    int q=query(x,r);
    if (q) rok=1;
  }
  if (lok&&rok) return x;
  else return -1;
}
int f(int l, int r) {
  if (l>r) return -1;
  if (l==r) {
    return one(l);
  }
  ll mid=(l+r)/2;
  int x=mid,y=mid+1;
  int q=query(x,y);
  if (q) {
    return f(l,x);
  }
  else {
    return f(y,r);
  }
}
void solve() {
  int ans1=f(1,n);
  assert(ans1!=-1);
  int ans2=f(1,ans1-1);
  bool got=false;
  int ans3=-1;
  if (ans2!=-1) {
    got=output(ans1,ans2);
  }
  else {
    ans3=f(ans1+1,n);
    assert(ans3!=-1);
    got=output(ans1,ans3);
  }
  if (!got) {
    dbg("n:%d k:%d ans:%d %d %d\n",n,k,ans1,ans2,ans3);
    for (auto &w:secret) dbg("%d ",w);
    dbg(" end secret\n");
    exit(0);
  }
}
void bf() {
  gen();
  solve();
}
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	//for (int k=0;k<500;k++) bf();
  scanf("%d %d",&n,&k);
  solve();
}