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
const int mn=1e5+4;

// 2bx+b^2 =A
// x=(A-b^2)/2b
// b^2 <= sqrt(2e5)

ll a[mn];
void fail() {printf("No\n"); exit(0);}
ll sq(ll x) {return x*x;}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin>>n;
  for (int p=2;p<=n;p+=2) cin>>a[p];
  int prev=0;
  for (int p=2;p<=n;p+=2) {
    int A=a[p];
    pii lo=MP(INT_MAX,INT_MAX);
    for (int b=1;;b++) {
      int top=A-b*b,b2=2*b;
      if (top<b2) break;
      if (top%b2) continue;
      int x=top/b2;
      if (x>prev) chkmin(lo,MP(x+b,x));
    }
    if (lo.fst==INT_MAX) fail();
    a[p-1]=sq(lo.snd)-sq(prev);
    assert(a[p]==sq(lo.fst)-sq(lo.snd));
    prev=lo.fst;
  }
  printf("Yes\n");
  for (int p=1;p<=n;p++) printf("%lld ",a[p]);
}