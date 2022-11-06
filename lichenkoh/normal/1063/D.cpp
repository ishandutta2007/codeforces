#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
 
using namespace std;
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <assert.h>
typedef long long ll;
typedef double ld;
#define PB push_back
#define MP make_pair
const int MOD=1000000007;
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
const ll SLIM=sqrt((ld)1e11)+4;
/*
(n+k)*r+t+q=A // k>=q
(n+k)*r+t+q=A+1 // k>=q>=1 if gap exists, k>=1 o/w

(n+k)*r+q = A-t
k*r+q = A-t-n*r

k*r+q = RHS
0<=q<=t

k = RHS/r to (RHS-t)/r

Find highest k st k>=q

(w+q)*r+q = A-t-n*r
Find highest w+q st 0<=w<=n-t, 0<=q<=t
This means q must be minimized.

Suppose q is free. Then w can be binsearched?
If k is too high, then w is too high
*/

ll solve(ll n, ll t, ll A, bool qone) {
  if (A<t) return -1;
  if (n<=SLIM) {
    //printf("AA");
    for (ll k=n;k>=0;k--) {
      ll q=(A-t)%(n+k);
      if (qone && q==0) continue;
      if (k>=q && k-q <= n-t && q<=t) {
        assert(0<=q&&q<=t&&q<=k&&0<=k-q&&k-q<=n-t);
        return k;
      }
    }
    return -1;
  }
  else {
    //printf("BB");
    ll rlim=2+((A-t)/n);
    ll final=-1;
    for (ll r=1;r<=rlim;r++) {
      ll rhs=(A-t-n*r);
      if (rhs<0) break;
      ll k=min(n,min((n-t+rhs)/(r+1),rhs/r));
      if (k==0) continue;
      if (qone && (rhs%k)==0) k--;
      if (k<=0) continue;
      ll q=rhs%k;
      if (r*k+q==rhs&&q<=t&&k-q<=n-t) {
        chkmax(final,k);
      }
    }
    {
      ll q=A-t;
      ll w=n-t;
      if (!qone || q>=1) {
        if (q<=t && t+q==A) {
          chkmax(final,q+w);
        }
      }
    }
    return final;
  }
}
//  XXX
//01234
//01
int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  ll n,l,r,A;
  cin>>n>>l>>r>>A;
  if (l>r) r+=n;
  ll t=(r-l+1)%n;
  //printf("t:%lld\n",t);
  ll ans0=solve(n,t,A, false);
  ll ans1=solve(n,t,A+1, t!=0);
  ll final=max(ans0,ans1);
  printf("%lld\n",final);
}