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
int rint();char rch();long long rlong();
const int mn=1e6+4;
int f[mn][2];
void reset(int cur) {
  f[cur][0]=INF; f[cur][1]=INF;
}
int vans[mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string a; cin>>a;
  int n=a.length();
  f[0][0]=0;
  f[0][1]=1;
  for (int i=0;i<n;i++) {
    int cur=i,nxt=i+1;
    reset(nxt);
    int c=a[i]-'0';
    {
      int now=f[cur][0];
      {
        // Add 0 or 1 depending on c
        chkmin(f[nxt][0],now+c);
      }
      if (c==0) {
        // Start 111 chain
        chkmin(f[nxt][1],now+1);
      }
    }
    {
      int now=f[cur][1];
      if (c==1) {
        // If c is 1, continue chain by putting 0.
        chkmin(f[nxt][1],now);
        // Or transition by putting -1
        chkmin(f[nxt][0],now+1);
      }
      if (c==0) {
        chkmin(f[nxt][1],now+1);
      }
    }
  }
  printf("%d\n",f[n][0]);
  //return 0;
  int t=0;
  for (int i=n-1;i>=0;i--) {
    int cur=i,nxt=i+1;
    int c=a[cur]-'0';
    int nv=f[nxt][t];
    int nt=-1;
    {
      {
        int now=f[cur][0];
        {
          // Add 0 or 1 depending on c
          if (t==0&&nv==now+c) {nt=0; vans[cur]=c;}
        }
        if (c==0) {
          // Start 111 chain
          if (t==1&&nv==now+1) {nt=0; vans[cur]=1;}
        }
      }
      {
        int now=f[cur][1];
        if (c==1) {
          // If c is 1, continue chain by putting 0.
          if (t==1&&nv==now) {nt=1; vans[cur]=0;}
          // Or transition by putting -1
          if (t==0&&nv==now+1) {nt=1; vans[cur]=-1;}
        }
        if (c==0) {
          if (t==1&&nv==now+1) {nt=1; vans[cur]=-1;}
        }
      }
    }
    assert(nt!=-1);
    t=nt;
  }
  if (t==1) printf("+2^%d\n",n);
  for (int i=0;i<n;i++) {
    int x=n-1-i;
    if (vans[i]==1) printf("+2^%d\n",x);
    else if (vans[i]==-1) printf("-2^%d\n",x);
  }
}