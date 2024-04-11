#pragma GCC optimize("Ofast")
#pragma GCC tet("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
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
const int mn=304;

queue<int> q[mn][mn];

string s[mn][mn];
string t[mn][mn];
vector<pair<pii,pii> > vans;
int k2c[2]={1,2};
int rn,cn;
void mov(pii S, pii T) {
  assert(S!=T);//printf("%d %d %d %d\n",w.fst.fst,w.fst.snd,w.snd.fst,w.snd.snd);
  vans.PB(MP(S,T));
  int got=q[S.fst][S.snd].front();q[S.fst][S.snd].pop();
  q[T.fst][T.snd].push(got);
}
int cnt[mn][mn][2];
int r2need[mn][2];
int r2have[mn][2];
void pr() {
  for (int r=1;r<=rn;r++) {
    for (int c=1;c<=cn;c++) {
      vi v; queue<int> tmp=q[r][c];
      while(!tmp.empty()) {v.PB(tmp.front()); tmp.pop();}
      reverse(v.begin(),v.end());
      for (auto &w:v) printf("%d",w);
      printf("  ");
    }
    printf("\n");
  }
  printf("\n");
}
int main() 
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin>>rn>>cn;
  for (int r=1;r<=rn;r++) {
    for (int c=1;c<=cn;c++) {
      cin>>s[r][c];
      reverse(s[r][c].begin(),s[r][c].end());
      for (auto &b:s[r][c]) q[r][c].push(b-'0');
    }
  }
  for (int r=1;r<=rn;r++) {
    for (int c=1;c<=cn;c++) {
      cin>>t[r][c];
      reverse(t[r][c].begin(),t[r][c].end());
      for (auto &b:t[r][c]) cnt[r][c][b-'0']++;
    }
  }
  // Empty out first row into second row
  {
    int r=1;
    for (int k=0;k<2;k++) {
      int c=k2c[k];
      for(auto &b:s[1][c]) mov(MP(1,c), MP(2,c));
      s[2][c]+=s[1][c];
      //cout<<s[2][c]<<endl;
      //cout<<1<<":"<<c<<"clear"<<endl;
      s[1][c]="";
    }
  }
  //pr();
  for (int r=1;r<=rn;r++) {
    for (int c=1;c<=cn;c++) {
      for(auto &b:s[r][c]) {
        int k=b-'0';
        int nc=k2c[k];
        if (c==nc) {
          mov(MP(r,c),MP(1,c));
          r2have[1][k]++;
        }
        else {
          mov(MP(r,c),MP(r,nc));
          r2have[r][k]++;
        }
      }
    }
  }
  //pr();
  for (int r=1;r<=rn;r++) {
    for (int c=1;c<=cn;c++) {
      for (int k=0;k<2;k++) r2need[r][k]+=cnt[r][c][k];
    }
  }
  for (int k=0;k<2;k++) for (int r=1;r<=rn;r++) {
    int c=k2c[k];
    r2need[r][k]-=cnt[r][c][k];
    r2need[r][k]+=cnt[(r-1+1)%rn+1][c][k];
  }
  //printf("Phase 2\n");
  for (int k=0;k<2;k++) {
    int needi=1;
    int c=k2c[k];
    for (int r=1;r<=rn;r++) {
      while(r2have[r][k]>r2need[r][k]) {
        while(needi<=rn&&r2need[needi][k]<=r2have[needi][k]) needi++;
        if (needi<=rn&& r2need[needi][k]>r2have[needi][k]) {
          //printf("k:%d r:%d needi:%d. r2have[r][k]:%d r2need[r][k]:%d. r2need[needi][k]:%d r2have[needi][k]:%d\n",
          //  k,r,needi,r2have[r][k],r2need[r][k],r2need[needi][k],r2have[needi][k]);
          mov(MP(r,c),MP(needi,c));
          r2have[r][k]--;
          r2have[needi][k]++;
        }
      }
    }
  }
  for (int r=1;r<=rn;r++) {
    for (int c=3;c<=cn;c++) {
      for (auto &b:t[r][c]) {
        int k=b-'0'; int cs=k2c[k];
        mov(MP(r,cs),MP(r,c));
      }
    }
  }
  //printf("Fixup ind\n");
  for (int r=1;r<=rn;r++) {
    for (int kt=0;kt<2;kt++) {
      int ct=k2c[kt];
      for (auto &b:t[r][ct]) {
        int ks=b-'0'; int cs=k2c[ks];
        if (ks!=kt) mov(MP(r,cs),MP(r,ct));
        else mov(MP( (r-1-1+rn+rn)%rn+1, cs ),MP(r,ct));
      }
    }
  }
  //pr();
  //return 0;
  printf("%d\n",(int)(vans.size()));
  for (auto &w:vans) {
    printf("%d %d %d %d\n",w.fst.fst,w.fst.snd,w.snd.fst,w.snd.snd);
  }
}