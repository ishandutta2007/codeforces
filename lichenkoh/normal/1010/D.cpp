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
#ifdef ONLINE_JUDGE
#define assert(...) /* nothing */
#endif
#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif
const int mn=(1e6)+4;
const int IN=1,AND=2,OR=3,XOR=4,NOT=5;
map<string,int> hop;
int vt[mn];
int val[mn];
int vc[mn][2];
int dp[mn];
int gop(int op, int x, int y) {
  if (op==IN) return x;
  else if (op==AND) return x&y;
  else if (op==OR) return x|y;
  else if (op==XOR) return x^y;
  else if (op==NOT) return 1-x;
  else assert(false);
}

int pre(int x) {
  int ans;
  if (vt[x]==IN) ans=val[x];
  else if (vt[x]==NOT) ans=gop(vt[x],pre(vc[x][0]),0);
  else ans=gop(vt[x],pre(vc[x][0]),pre(vc[x][1]));
  return dp[x]=ans;
}

int vflip[mn];

void dfs(int x) {
  int old=dp[x];
  if (vt[x]==IN) vflip[x]=1;
  else if (vt[x]==NOT) {
    dfs(vc[x][0]);
  }
  else {
    for (int a=0;a<2;a++) for (int b=0;b<2;b++) {
      int ab=gop(vt[x],a,b);
      int ai=vc[x][0],bi=vc[x][1];
      if (ab!=old) {
        bool da=(dp[ai]!=a);
        bool db=(dp[bi]!=b);
        if (da&&db) {}
        else if (da) {
          dfs(ai);
        }
        else if (db) {
          dfs(bi);
        }
      }
    }
  }
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  hop["IN"]=IN;
  hop["AND"]=AND;
  hop["OR"]=OR;
  hop["XOR"]=XOR;
  hop["NOT"]=NOT;
  for (int x=1;x<=n;x++) {
    string t; cin>>t; int op=hop[t]; vt[x]=op;
    if (op==IN) cin>>val[x];
    else if (op==NOT) cin>>vc[x][0];
    else cin>>vc[x][0]>>vc[x][1];
  }
  // Compute values first
  pre(1);
  dfs(1);
  for (int x=1;x<=n;x++) {
    if(vt[x]==IN) {
      if (dp[1]^vflip[x]) printf("1");
      else printf("0");
    }
  }
  printf("\n");

}