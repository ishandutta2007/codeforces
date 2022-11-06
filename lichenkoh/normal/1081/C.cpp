#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
const int MOD=998244353;
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<30;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
typedef vector<pii> vpii;
const int mn=2004;
int f[2][mn];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int B,C,K; cin>>B>>C>>K;
  int C1=C-1;
  f[0][0]=C;
  int cur=0,nxt=1;
  for (int b=0;b<B-1;b++) {
    memcpy(f[nxt],f[cur],sizeof f[0]);
    for (int k=0;k<K;k++) {
      f[nxt][k+1]=(f[nxt][k+1]+f[cur][k]*(ll)(C1))%MOD;
    }
    swap(cur,nxt);
  }
  printf("%d\n",f[cur][K]);
}