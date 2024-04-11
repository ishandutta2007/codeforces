#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
 
const int MX=20, BS=1<<MX, MOD=1e9+7;

ll t, k, n;
vi r;
ll fact[MX];
int cnt[MX];

int countBS(int bs) {
  int ans=0;
  RE(i,MX)
    if(bs & (1<<i))
      ans++;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  fact[0] = 1;
  REP(i,1,MX) fact[i] = fact[i-1]*ll(i);
  while(t--) {
    cin>>k;
    int i=2;
    n = 0;
    r.clear();
    while(k) {
      r.pb(k%i);
      k /= i++;
      n++;
    }
    sort(r.begin(), r.end(), greater<int>());
    ll ans = 1;
    RE(i,n)
      ans = ans*(n - max(0, r[i] - 1) - i);
    if(r.back() == 0) {
      ll endZero = 1;
      RE(i,n-1) {
        if(r[i])
          endZero = endZero*(n - max(0, r[i]) - i);
        else
          endZero = endZero*(n - max(0, r[i] - 1) - i);
      }
      ans -= endZero;
    }
    
    RE(i,MX+2) cnt[i] = 0;
    for(int i:r) cnt[i]++;
    RE(i,MX+2) ans /= fact[cnt[i]];
    cout<<ans-1<<endl;
  }
}