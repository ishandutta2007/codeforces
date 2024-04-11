#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<ll> vi;typedef vector<vi> vvi;
ll rint()
{
  ll x; cin>>x;
  return x;
}
bool go() {
  ll n=rint(); ll k=rint();
  vll inp(n+1,0LL);
  for (int i=1;i<=n;i++) {
    inp[i]=rint();
  }
  if (n==1 && inp[1]==k) return true;
  bool has=false;
  for (int x=1;x<=n;x++) {
    if (inp[x]==k) has=true;
  }
  if (has) {
    for (int x=1;x<n;x++) {
      if (inp[x]>=k) {
        if (inp[x+1]>=k) return true;
        if (x+2<=n && inp[x+2]>=k) return true;
      }
    }
  }
  return false;
}

int main() 
{
  ll t=rint();
  for (ll i=0;i<t;i++) {
    bool ans=go();
    if (ans) printf("yes\n");
    else printf("no\n");
  }
}