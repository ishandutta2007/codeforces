#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
#include "bits/stdc++.h"
 
using namespace std;
#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <assert.h>
typedef long long ll;
typedef long double ld;
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

int main()
{
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  int orig=n;
  int k=1;
  while(n) {
    if (n==1) {
      if (k!=1) k/=2;
      for (int x=orig;x>=1;x--) {
        if (x%k==0) {
          printf("%d\n",x);
          return 0;
        }
      }
    }
    int even=n/2;
    int odd=(n+1)/2;
    for (int i=0;i<odd;i++) printf("%d ",k);
    k*=2;
    n=even;
  }
}