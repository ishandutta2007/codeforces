#include <iostream>
#include <fstream>

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
const ll mn=5004,mc=26;
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll MAXFACT=mn*3;
ll fact[MAXFACT+1],invfact[MAXFACT+1];
inline ll mul(ll x,ll y) {return (x*y)%MOD;}
inline ll add(ll x,ll y) {return (x+y)%MOD;}
void init() {
  ll got=1;
  for (ll x=0;x<=MAXFACT;x++) {
    fact[x]=got;
    got=mul(got,x+1);
  }
  got=mod_pow(got,MOD-2,MOD);
  for (ll x=MAXFACT;x>=0;x--) {
    got=mul(got,x+1);
    invfact[x]=got;
    assert(mul(fact[x],invfact[x])==1);
  }
}
ll binom(ll n,ll k) {
  if (n<k) return 0;
  if (n<0||k<0) return 0;
  return mul(fact[n],mul(invfact[k],invfact[n-k]));
}

ll starbar(ll stars, ll parts) {
  if (parts==0) {
    return (stars==0)?1:0;
  }
  if (parts<=0||stars<0) return 0;
  return binom(stars+parts-1,parts-1);
}
ll f[mn][mn]; // f(x,k) := Number of subseq of length k ending at x
ll lastsum[mc][mn]; // g(c,k) := Last sum for char c, subseq length k
ll currentsum[mn]; // sum(k) := Sum for subseq k.
int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  init();
  ll n; string s; cin>>n>>s;
  memset(lastsum,0,sizeof lastsum);
  memset(currentsum,0,sizeof currentsum);
  memset(f,0,sizeof f);
  f[0][0]=1;
  {
      ll x=0;
      for (ll k=0;k<n;k++) { // Length of subsequence
          currentsum[k+1]+=f[x][k];
      }
  }
  for (ll x=1;x<=n;x++) { // Pos in string
      for (ll k=0;k<=n;k++) f[x][k]=f[x-1][k];
      ll c=s[x-1]-'a';
      for (ll k=n;k>=0;k--) {
          ll toadd=(currentsum[k]-lastsum[c][k]+MOD)%MOD;
          f[x][k]+=toadd; f[x][k]%=MOD;
          currentsum[k+1]+=toadd; currentsum[k+1]%=MOD;
          lastsum[c][k]=currentsum[k];
          // Force no 2 adjacent with same characters
          lastsum[c][k+1]=currentsum[k+1];
      }
  }
  ll final=0;
  for (ll k=0;k<=n;k++) {
    final+=mul(f[n][k],starbar(n-k,k));
  }
  final%=MOD;
  printf("%lld\n",final);
}