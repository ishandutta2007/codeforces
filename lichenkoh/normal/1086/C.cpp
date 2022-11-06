#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
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
// mt19937 rng; rng.seed(std::chrono::high_resolution_clock::now().time_since_epoch().count());
// template<typename T> int bins(vector<T> &v, T key) {int imin=0,imax=v.size();while(imin<imax) {int imid=(imin+imax)>>1;if (v[imid]<key) imin=imid+1;else imax=imid;}return imin;}
int n,k; string sa,sb,sc;
vi finalf; bitset<26> finalu;
bool dfs(int x, vi f, bitset<26> use, bool eqa, bool eqb) {
  if (x==n||((!eqa)&&(!eqb))) {
    //printf("f:%d %d\n",f[0],f[1]);
    finalf=f; finalu=use;
    return true;
  }
  int a=sa[x],b=sb[x],c=sc[x];
  int tlo=0,thi=k-1;
  if (eqa) chkmax(tlo,a);
  if (eqb) chkmin(thi,b);
  //printf("tlo:%d thi:%d eqa:%d eqb:%d f:%d %d\n",tlo,thi,eqa,eqb,f[0],f[1]);
  for (int t=tlo;t<=thi;t++) {
    if (f[c]==t) {
      if (dfs(x+1,f,use,eqa&&a==t,eqb&&b==t)) {
        //printf("x:%d c:%d t:%d\n",x,c,t);
        return true;
      }
    }
    else {
      if (use[t]) continue;
      if (f[c]!=-1) continue;
      bitset<26> nuse=use; nuse[t]=true;
      vi nf=f; nf[c]=t;
      if (dfs(x+1,nf,nuse,eqa&&a==t,eqb&&b==t)) {
        //printf("x:%d c:%d t:%d\n",x,c,t);
        return true;
      }
    }
  }
  return false;
}

void go() {
  cin>>k>>sc>>sa>>sb;
  for (auto &w:sa) w-='a';
  for (auto &w:sb) w-='a';
  for (auto &w:sc) w-='a';
  n=sc.length();
  vi f(k,-1); bitset<26> use; use.reset();
  for (int x=0;x<n;x++) {
    int a=sa[x],b=sb[x];
    int c=sc[x];
    if (a==b) {
      int t=a;
      if (f[c]==t) {}
      else {
        if (f[c]!=-1||use[t]) {cout<<"NO"<<endl; return;}
        f[c]=t; use[t]=true;
      }
    }
    else {
      // p<q
      bool ans=dfs(x,f,use,true,true);
      if (!ans) {cout<<"NO"<<endl; return;}
      else {
        f=finalf; use=finalu;
        break;
      }
    }
  }
  cout<<"YES"<<endl;
  string sout; sout.resize(k);
  for (int i=0;i<k;i++) {
    if (f[i]==-1) {
      for (int t=0;t<k;t++) {
        if (!use[t]) {
          f[i]=t; use[t]=true;
          break;
        }
      }
    }
    sout[i]=f[i]+'a';
  }
  cout<<sout<<endl;
  return;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int T; cin>>T;
  for (int i=0;i<T;i++) go();
}