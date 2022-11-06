#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
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
#define endl "\n"
#define fst first
#define snd second
const int UNDEF = -1;
const int INF=1<<29;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
typedef pair<ll,ll> pll;typedef vector<ll> vll;typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vi> vvi;
int rint() {int x;scanf("%d",&x);return x;}
ll rlong() {ll x;scanf("%lld",&x);return x;}
typedef
tree<
  pair<ll,int>,
  null_type,
  less<pair<ll,int>>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;
ordered_set s;
const int mn=2e5+2;
int a[mn];

//PRESUM - want < t
//want>PRESUM - t
int main()
{
  int n=rint(); ll lim=rlong();
  for (int i=0;i<n;i++) a[i]=rint();
  ll presum=0;
  ll ans=0;
  s.insert(MP(0LL,1));
  for (int i=0;i<n;i++) {
    presum+=a[i];
    //printf("Count <= than %lld:%d\n",presum-lim,(int)s.order_of_key(MP((lim-presum),-1)));
    ans+=s.size()-s.order_of_key(MP((presum-lim+1),-1));
    //printf("presum:%lld\n",presum);
    s.insert(MP(presum,i+101));
  }
  printf("%lld\n",ans);
}