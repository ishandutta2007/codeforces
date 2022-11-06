#include "bits/stdc++.h"
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back

int main() 
{
  int n; cin>>n;
  vector<ll> orig(n);
  for (int i=0;i<n;i++) cin>>orig[i];
  vector<ll> a=orig;
  vector<ll> best;
  best.PB(a[0]);
  ll prodg=1;
  while(a.size()>1) {
    {ll g=a[0];
    for (int i=1;i<a.size();i++) g=__gcd(g,a[i]/prodg);
    prodg*=g;}
    vector<ll> nxt;
    vector<ll> cand;
    for (int i=0;i<a.size();i++) {
      if ((a[i]/prodg)%2==0) nxt.PB(a[i]);
      else cand.PB(a[i]);
    }
    if (cand.size() > best.size()) best=cand;
    a=nxt;
  }
  set<ll> origs; for (auto &w:orig) origs.insert(w);
  for (auto &w:best) origs.erase(w);
  printf("%d\n",(int)(origs.size()));
for (auto &w:origs) printf("%lld ",w);
  printf("\n");
  
}