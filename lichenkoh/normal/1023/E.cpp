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
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
int rint();char rch();long long rlong();
int gn;
bool ask(int x1, int y1, int x2, int y2) {
  int n=gn;
  assert(abs(x1-x2)+abs(y1-y2)>=n-1);
  cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
  cout.flush();
  string s;cin>>s;
  return s[0]=='Y';
}

string ans1,ans2;
int ansi1=0,ansi2=0;
int tx,ty;
void go2(int x, int y) {
  int n=gn;
  if (x==tx&&y==ty) return;
  bool ydec=false;
  if (y==1) ydec=false;
  else {
    int ny=y-1;
    ydec=ask(1,1,x,ny);
  }
  if (ydec) {
    ans2[ansi2++]='R';
    go2(x,y-1);
  }
  else {
    ans2[ansi2++]='D';
    go2(x-1,y);
  }
}

void go(int x, int y) {
  int n=gn;
  if (ansi1==n-1) {
    tx=x; ty=y; return;
  }
  int nx=x+1;
  bool xinc=false;
  if (x==n) xinc=false;
  else {
    xinc = ask(nx,y,n,n);
  }
  if (xinc) {
    ans1[ansi1++]='D';
    go(x+1,y);
  }
  else {
    ans1[ansi1++]='R';
    go(x,y+1);
  }
}

int main() 
{
  int n; cin>>n; gn=n;
  ans1.resize(n-1);
  ans2.resize(n-1);
  go(1,1);
  //cout<<tx<<"::"<<ty<<endl;
  go2(n,n);
  reverse(ans2.begin(),ans2.end());
  cout<<"! "<<ans1<<ans2<<endl;
}