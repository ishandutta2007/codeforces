#include <bits/stdc++.h>
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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
//#define DEBUG_CAT
#ifdef DEBUG_CAT
#define dbg(...)   printf( __VA_ARGS__ )
#else 
#define dbg(...)   /****nothing****/
#endif

ll go(string &s, string &t) {
  int slen=s.length(), tlen=t.length();
  ll forbid=0;
  int j=0;
  for (int i=0;i<slen-1;i++) {
    if (j<tlen&&s[i]==t[j]) j++;
    forbid+=j;
  }
  return forbid;
}
int h[256][256];
int tl=0,tr=0;
void addr(string &t) {
  tr++;
  h[t[tr-1]][t[tr]]++;
}
void addl(string &t) {
  if (tr>tl) {
    h[t[tl]][t[tl+1]]--;
  }
  tl++;
}
ll strange(string &s, string &t) {
  int slen=s.length(), tlen=t.length();
  vector<char> vc={'R','G','B'};
  ll forbid=0;
  for (int si=0;si<slen;si++) {
    char sc=s[si];
    while(tr<tlen && t[tr]!=sc) addr(t);
    dbg("si:%d tl:%d tr:%d sc:%c t[tr]:%c\n",si,tl,tr,sc,t[tr]);
    if (si>0) {
      char c0=s[si-1],c1=s[si];
      dbg("%c%c\n",c0,c1);
      if (c0!=c1) {
        forbid+=h[c1][c0];
      }
      /*if (c0!=c1) {
        for (int ti=max(1,tl);ti<=min(tlen-1,tr);ti++) {
          dbg("si:%d ti:%d\n",si,ti);
          if (t[ti-1]==c1&&t[ti]==c0) {
            dbg("SUB\n");
            forbid++;
          }
        }
      }*/
    }
    if (tr<tlen) {
      assert(t[tr]==sc);
      addr(t);
    }
    if (tl<tlen && t[tl]==sc) addl(t);
  }
  return forbid;
}

int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s,t; cin>>s>>t;
  int slen=s.length(), tlen=t.length();
  ll forbids=go(s,t)+go(t,s);
  ll stranges=strange(s,t);
  ll all=slen*(ll)tlen;
  ll ans=all-forbids-stranges;
  printf("%lld\n",ans);
}